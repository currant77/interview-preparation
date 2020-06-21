/**
 * @file cci_1-1.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.1 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-06-21
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 1.1: 
(a) "Implement an algorithm to determine if a string has 
all unique characters. 
(b) What if you cannot use additional data structures?" */

/* Approach: 
(a) Insert the characters from the string into a set. If a character is
already in the set, return false; return true if we make it through all the
characters without a repeat. 
(b) Create an array of size equal to the number of characters. Change array
value for each character. Return true if value has already been changed; return
false if we make it through all the characters.*/

#include <cmath>
#include <string>
#include <cassert>
#include <iostream>
#include <unordered_set>

/**
 * @brief Returns true if the \p s does not contain any repeated
 * characters; false otherwise
 * @note Uses std::unordered_set
 */
bool isUniqueA(std::string s)
{
    std::unordered_set<char> set;

    for(auto it = s.begin(); it != s.end(); ++it)
    {
        if(set.count(*it) > 0)
            return false;
        
        else
            set.insert(*it);
    }

    return true;
}

/**
 * @brief Returns true if the \p s does not contain any repeated
 * characters; false otherwise
 * @note Does not use any library data structures
 */
bool isUniqueB(std::string s)
{
    // Create array with one entry for each char
    size_t size = std::pow(2, sizeof(char) * 8);
    char count[size] = {0};

    for(auto it = s.begin(); it != s.end(); it++)
    {
        if(count[*it] != 0)
            return false;
        
        else
            count[*it]++;
    }

    return true;
}


int main()
{
    std::cout << "Beginning tests..." << std::endl;

    assert(isUniqueA("Taylor"));
    assert(isUniqueB("Taylor"));
    assert(!isUniqueA("riffraff"));
    assert(!isUniqueB("ice cream"));
    assert(isUniqueA("Test"));
    assert(isUniqueB("Test"));
    assert(!isUniqueA("test"));
    assert(!isUniqueB("test"));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}