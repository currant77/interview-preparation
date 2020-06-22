/**
 * @file cci_1-4.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.4 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-06-22
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem  1.4: "Palindrome Permutation: Given a striing, write a function to check if 
it is a permutation of a palindrome...The palindrome down not need to be limited to 
dictionary words" (i.e. it does not need to be a real word). */

/* Approach: In a palindrome, each char will occur an even number of times, except for
the middle character in the case where it has an odd length. Any permutation will share
the same properties. Use the same map-based approach as problem 1.2 to check this.
approach */

#include <string>
#include <cassert>
#include <iostream>
#include <unordered_map>

/**
 * @brief Returns true if a permutation of the given string 
 * is a palindrome (does not need to be a real word).
 */
bool isPalindromePermutation(std::string s)
{
    // Insert char counts into map
    std::unordered_map<char, int> map;
    
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        if(!map.count(*it))
            map.insert(std::make_pair(*it, 1));

        else
            map[*it]++;
    }

    // `even` is true if all remaining counts must be even
    bool even = (s.length() % 2) == 0;

    for(auto it = map.begin(); it != map.end(); ++it)
    {
        // If current count is odd
        if(((*it).second % 2) != 0)
        {
            if(even)
                return false;
            else
                even = true;
        }
    }

    return true;    
}

int main()
{
        std::cout << "Beginning tests..." << std::endl; 

    assert(isPalindromePermutation("racecar"));     // Palindrome
    assert(isPalindromePermutation("acercar"));     // Permutation of palindrome
    assert(isPalindromePermutation(""));            // Special case palindrom
    assert(isPalindromePermutation("a"));           // Special case calindrome
    assert(isPalindromePermutation("bbcc"));        // Permutation of palindrome
    assert(!isPalindromePermutation("abcb"));
    assert(isPalindromePermutation("aaaabaaaabb")); // Permutation of palindrome
    assert(!isPalindromePermutation("aaaabaaabb"));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}