/**
 * @file cci_1-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.2 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-06-22
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 1.2: "Given two strings, write a method to decide if 
one is a permutation of the other. */

/* Approach: Check if strings have the same number of characters; if not,
return false. If they do, create an char-int map. Iterate through map for 
one string incrementing values, other string decrementing; check that all 
values are zero */

#include <string>
#include <cassert>
#include <iostream>
#include <unordered_map>

/**
 * @brief Returns true if \p s1 and \p s2 are permutations of each other
 */
bool isPermutation(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
        return false;

    std::unordered_map<char, int> map;

    // Increment for s1 chars
    for(auto it = s1.begin(); it != s1.end(); ++it)
    {
        // Insert char
        if(!map.count(*it))
            map.insert({*it, 1});
        
        // Increment count
        else
            map[*it]++;
    }

    // Decrement for s2 chars
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        if(!map.count(*it))
            return false;

        else
            map[*it]--;
    }
    
    // Check that all counts are zero
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        if((*it).second != 0)
            return false;
    }

    return true;
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    assert(isPermutation("racecar", "racecar"));
    assert(isPermutation("abc", "cba"));
    assert(!isPermutation("abc", "aab"));
    assert(!isPermutation("a", ""));
    assert(isPermutation("", ""));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}