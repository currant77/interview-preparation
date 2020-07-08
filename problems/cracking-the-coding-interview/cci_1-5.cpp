/**
 * @file cci_1-5.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.5 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-07
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 1.5: "One Away: There are three types of edits that can be 
performed on strings: insert a character, remove a character, or replace 
a chracter. Given two strings, write a function to check if they are one 
edit (or zero edits) away.""

EXAMPLES:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false */

/* Approach: Iterate over both string simultaneously. Check if 
values match; if not record and move on. Return false if more than
one edit found. */

#include <cmath>        // std::abs
#include <string>       // std::string
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;

bool one_away(const std::string& s1, const std::string& s2)
{
    if(std::abs((int)s1.length() - (int)s2.length()) > 1)
        return false;

    bool edited = false;

    // String have same length
    if(s1.length() == s2.length())
    {
        for(size_t i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i])
            {
                if(edited)
                    return false;
                else
                    edited = true;
            }
        }
    }

    // String have different lengths
    else
    {
        const std::string longer = s1.length() > s2.length() ? s1 : s2;
        const std::string shorter = s1.length() < s2.length() ? s1 : s2;

        size_t it_long = 0;
        size_t it_short = 0;

        while(it_long < longer.length() && it_short < shorter.length())
        {
            // Match
            if(longer[it_long] == shorter[it_short])
            {
                it_short++;
                it_long++;
            }

            // No match
            else
            {
                if(edited)
                    return false;

                else
                {
                    edited = true;
                    it_long++;
                }   
            }   
        }
    }

    return true;
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    assert(one_away("", ""));                   // empty
    assert(one_away("", "a"));                  // add one
    assert(one_away("a", ""));                  // remove one
    assert(one_away("a", "b"));                 // modify one
    assert(!one_away("", "ac"));
    
    assert(!one_away("ab", ""));
    assert(one_away("abc", "dabc"));   
    assert(one_away("abc", "ac"));
    assert(one_away("abc", "abb"));
    assert(!one_away("abc", "acd"));
    
    assert(one_away("pale", "ple"));
    assert(one_away("pales", "pale"));
    assert(one_away("pale", "bale"));
    assert(!one_away("pale", "bake"));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}