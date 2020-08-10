/**
 * @file HashFunctions.cpp
 * @author Taylor Curran
 * @brief Example hash functions
 * @version 0.1
 * @date 2020-08-08
 * 
 * @copyright Copyright (c) 2020
 * 
 * @see https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/
 * @see https://en.cppreference.com/w/cpp/utility/hash
 */

#include <cmath> // std::pow
#include <string> // std::string

/**
 * @brief Sample class. Represents a person. Two persons are considered equal if
 * they have the same name and the same social insurance number.
 * 
 */
struct Person {
    std::string name;
    std::string address;
    int sin;
};

// Creating custom hash and equality comparison objects ========================

/**
 * @brief String equality comparison object. Strings evaluate as equal if they
 * have the same characters (default behaviour compares objects).
 */
struct StringEqual {
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
struct StringHash {
public:
    size_t operator()(const std::string& str) const
    {
        size_t hash = 0;
        size_t n = str.length() - 1;

        for (char const& c : str) {
            hash += c * std::pow(31, n--);
        }
        return hash;
    }
};

// Overriding std::hash and equality operators =================================

bool operator==(const Person& lhs, const Person& rhs)
{
    StringEqual str_eq;
    return str_eq(lhs.name, rhs.name) && (rhs.sin == lhs.sin);
}

bool operator!=(const Person& p1, const Person& p2)
{
    return !(p1 == p2);
}

namespace std {
template <>
struct hash<Person> {
    void combine(size_t& seed, size_t hash) const
    {
        seed ^= hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    size_t operator()(const Person& p) const
    {
        size_t seed = 0;

        std::hash<int> int_hash;
        StringHash string_hash;

        combine(seed, string_hash(p.name));
        combine(seed, int_hash(p.sin));

        return seed;
    }
};
}