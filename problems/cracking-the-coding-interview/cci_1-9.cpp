/**
 * @file cci_1-9.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.9 from Cracking the Coding Interview
 * @version 0.1
 * @date 20202-07-15
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 1.9: "String Rotation: Assume you have a method `isSubstring()`
which checks if one word is a substring of another. Given two strings, s1
and s2, write code to check if s2 is a rotation of si using only one call
to `isSubstring()` (e.g. 'waterbottle' is a rotation of 'erbottlewat')" */

/* Approach: If s1 is a rotation of s2, then it is possible to split both
into parts x and y such that s1 = xy and s2 = yx. Therefore, if we put 
two copies of s1 together we get xyxy. which contains s2. So we can search
s1 + s1 for s2. */

#include <string>       // std::string
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;

bool isSubtring(std::string str, std::string sub)
{
    if(str.length() < sub.length())
        return false;

    size_t result = str.find(sub);
    return (result != std::string::npos);
}

bool isRotation(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
        return false;  
    
    return isSubtring((s1 + s1), s2);
}

int main()
{
    std::cout << std::endl << "Beginning tests for isSubtring()..." << std::endl; 

    assert(isSubtring("", ""));
    assert(isSubtring("a", "a"));
    assert(isSubtring("aa", "aa"));
    assert(isSubtring("abba", "ab"));
    assert(isSubtring("abba", "ba"));
    assert(isSubtring("abba", "bb"));
    assert(isSubtring("abba", "abba"));
    
    assert(!isSubtring("abba", "bbb"));
    assert(!isSubtring("abba", "abbab"));
    assert(!isSubtring("abba", "babba"));
    assert(!isSubtring("abba", "babbab"));

    std::cout << "Beginning tests for isRotation()..." << std::endl; 

    assert(isRotation("", ""));
    assert(isRotation("abcd", "abcd"));
    assert(isRotation("abcd", "bcda"));
    assert(isRotation("abcd", "cdab"));
    assert(isRotation("abcd", "dabc"));
    
    assert(!isRotation("", "a"));
    assert(!isRotation("abcd", "cdba"));
    assert(!isRotation("abcd", "acbd"));
    assert(!isRotation("abcd", "abcda"));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}