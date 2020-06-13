/**
 * @file tst_HashSet.cpp
 * @author Taylor Curran
 * @brief Tests for HashSet. Includes overriding default hash and
 * equality behaviour for std::string and a simple class.
 * @version 0.1
 * @date 2020-06-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cmath>
#include <string>
#include <cassert>
#include <iostream>
#include <functional>

#include "HashSet.h"

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
 * @brief String hash function (algorithm from Koffman & Wolfgang 2006, 538
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
 * @brief Custom equality comparison for Person
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
 * @brief Custom hash function based on boost::hash_combine
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

int main()
{
    std::cout << "Beginning tests..." << std::endl;

    std::cout << "Testing std::string..." << std::endl;

    // Create hash table using custom hash and equality objects
    // (Table is small to test resizing)
    HashSet<std::string, StringHash, StringEquality> t1(3);

    // Empty table
    assert(!t1.size());

    // Add "A", "B", and "C"
    assert(t1.insert("A"));
    assert(t1.insert("B"));
    assert(t1.insert("C"));
    assert(!t1.insert("A"));
    assert(!t1.insert("C"));

    assert(t1.size() == 3);
    assert(t1.contains("A"));
    assert(t1.contains("C"));
    assert(!t1.contains("D"));

    // Remove "B" and "A"
    assert(t1.remove("B"));
    assert(t1.remove("A"));
    assert(!t1.remove("A"));
    assert(t1.size() == 1);

    // Clear and add "D"
    t1.clear();
    assert(!t1.size());
    assert(!t1.contains("C"));
    assert(t1.insert("D"));
    assert(t1.contains("D"));
    assert(t1.size() == 1);

    std::cout << "Testing Person..." << std::endl;

    // Create hash table and assorted people
    HashSet<Person, PersonHash, PersonEquality> t2;
    Person tc{"Taylor", "Curran", 29, 7871325};
    Person tc2{"Taylor", "Curran", 29, 7899776};
    Person sc{"Spencer", "Curran", 15, 9293418};
    Person bo{"Barack", "Obama", 44, 1234567}; 

    // Add all
    assert(t2.insert(tc));
    assert(t2.insert(sc));
    assert(t2.insert(bo));
    assert(!t2.insert(bo));
    assert(!t2.insert(tc2));

    assert(t2.size() == 3);
    assert(t2.contains(tc));
    assert(t2.contains(tc2));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0);
}