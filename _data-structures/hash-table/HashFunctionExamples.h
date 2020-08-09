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
 * @see https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/
 * @see https://en.cppreference.com/w/cpp/utility/hash
 */

#include <cmath>  // std::pow
#include <string> // std::string

/* Library class (std::string) ----------
By providing equality and hashing objects, we can provide a desired
behaviour in a specific context without changing the default behaviour
(represented by the comparison operators and std::hash) */

/**
 * @brief String equality comparison object
 */
struct StringEquality
{
public:
    bool operator()(const std::string &s1, const std::string &s2) const
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
    size_t operator()(const std::string &str) const
    {
        size_t hash = 0;
        size_t n = str.length() - 1;

        for (char const &c : str)
        {
            hash += c * std::pow(31, n--);
        }
        return hash;
    }
};

/* Custom class ---------------------
In contrast to the case above, here we want to change the default behaviour
by overriding the equality and inequality operators and std::hash. */

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

bool operator==(const Person &p1, const Person &p2)
{
    return !p1.first_name.compare(p2.first_name) &
            !p1.last_name.compare(p2.last_name) &
            p1.sin == p2.sin;
}

bool operator!=(const Person& p1, const Person& p2)
{
    return !(p1 == p2);
}

namespace std
{
    template<> struct hash<Person>
    {
        void combine(size_t &seed, size_t hash) const
        {
            seed ^= hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }

        size_t operator()(const Person &p) const
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
}
