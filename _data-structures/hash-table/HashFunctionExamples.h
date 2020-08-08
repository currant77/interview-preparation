/**
 * @file HashFunctions.cpp
 * @author Taylor Curran
 * @brief Sample implementations of custom hash function objects (see 
 * std::hash) with corresponding custom equality objects (see std::equal_to)
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cmath>        // std::pow
#include <string>       // std::string

// Library classes ----------

/**
 * @brief String equality comparison object
 */
struct StringEquality
{
    public:
        bool operator()(const std::string& s1, const std::string& s2) const
        {
            return !s1.compare(s2);
        }
};

/**
 * @brief String hash function object
 * @ref Koffman & Wolfgang 2006, 538
 */
struct StringHash
{
    public:
        size_t operator()(const std::string& str) const
        {
            size_t hash = 0;
            size_t n = str.length() - 1;  

            for(char const& c : str)
            {
                hash += c * std::pow(31, n--);
            }      
            return hash;
        }
};

// Custom class ---------------------

/**
 * @brief Simple struct for demonstrating custom hash function and 
 * and equality comparison. Two person objects are considered equal
 * if the have the same name and SIN. 
 */
struct Person
{
    public:
        std::string first_name;
        std::string last_name;
        int sin;
        int phone_number;      
};

/**
 * @brief Custom equality comparison object for \class Person
 */
struct PersonEquality
{
    public:
        bool operator()(const Person& p1, const Person& p2) const
        {
            return !p1.first_name.compare(p2.first_name) &
                    !p1.last_name.compare(p2.last_name) &
                    p1.sin == p2.sin;
        }
};

/**
 * @brief Custom hash function object for \class Person
 * @ref based on boost::hash_combine
 */
struct PersonHash
{
    private:
        void combine(size_t& seed, size_t hash) const
        {
            seed ^= hash + 0x9e3779b9 + (seed<<6) + (seed>>2);    
        }

    public:
        size_t operator()(const Person& p) const
        {
            size_t seed = 0;

            std::hash<int> int_hash;
            std::hash<std::string> string_hash;

            combine(seed, string_hash(p.first_name));
            combine(seed, string_hash(p.last_name));
            combine(seed, int_hash(p.sin));
        
            return seed;
        }
};