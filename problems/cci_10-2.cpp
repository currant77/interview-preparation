/**
 * @file cci_10-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 10.2 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-06-30
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 10.2: "Group Anagrams: Write a method to sort an array of strings so that
all the anagrams are next to each other" */

/* Approach: Define a hash map from a string to a list of strings. For each string in the list,
create a new string key by sorting its characters, and use this to insert it into the map. This
will group all anagrams in the same hash map bucket. Once all values have been inserted, simply
iterate over the hash map and output the values to the list. */

#include <string>           // std:string
#include <cassert>          // assert
#include <iostream>         // std::cout, std::endl
#include <algorithm>        // std::sort, std::copy
#include <unordered_map>    // std::unordered_map
#include <vector>           // std::vector

/**
 * @brief Returns a key corresponding to \p s
 * that consists of its characters sorted in 
 * alphabetic order
 */
std::string get_key(std::string s)
{
    // Copy characters to buffer
    char buffer[s.length() + 1];
    std::copy(s.begin(), s.end(), buffer);
    buffer[s.length()] = '\0';

    // Sort buffer
    std::sort(buffer, buffer + s.length());

    // Copy buffer to string
    return std::string(buffer);
}

/**
 * @brief Prints the strings in the array
 */
void print_strings(std::string* strings, size_t size)
{
    std::cout << "[";

    for(size_t i = 0; i < size - 1; i++)
        std::cout << *(strings + i) << ", ";

    std::cout << *(strings + size - 1) << "]" << std::endl;
}

/**
 * @brief Re-orders the strings such that all strings that
 * are anagams of each other are grouped together
 */
void group_anagrams(std::string* strings, size_t size)
{
    // Push strings to map
    std::string key;
    std::unordered_map<std::string, std::vector<std::string>> map;
    
    for(auto it = strings; it != strings + size; ++it)
        map[get_key(*it)].push_back(*it);

    // Output values in order
    std::string* output_it = strings;

    for(auto map_it = map.begin(); map_it != map.end(); ++map_it)
    {
        for(auto list_it = map_it->second.begin(); list_it != map_it->second.end(); ++list_it)
            *(output_it++) = *list_it;
    }
}

int main()
{
    // get_key() tests:

    std::cout << std::endl << "Beginning tests for get_key()..." << std::endl;

    assert(!get_key("").compare(""));
    assert(!get_key("a").compare("a"));
    assert(!get_key("acb").compare("abc"));
    assert(!get_key("aaa").compare("aaa"));
    assert(!get_key("zyx").compare("xyz"));
    assert(!get_key("bcdea").compare("abcde")); 

    std::cout << "All tests for get_key() passed!" << std::endl << std::endl; 

    // group_anagrams() tests:  
    
    std::cout << "Beginning tests for group_anagrams()..." << std::endl; 

    std::string one[] = {"ab", "ac", "aa", "ba", "aa", "ca"};
    group_anagrams(one, 6);
    print_strings(one, 6);

    // Result: [aa, aa, ab, ba, ac, ca]

    std::string two[] = {"AA", "aa", "dave", "dav", "ave", "aved", "aa"};
    group_anagrams(two, 7);
    print_strings(two, 7);

    // Result: [dav, ave, dave, aved, AA, aa, aa]

    std::cout << "All tests for group_anagrams() passed!" << std::endl;
    exit(0); 
}