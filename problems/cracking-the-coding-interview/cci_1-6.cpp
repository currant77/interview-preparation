/**
 * @file cci_1-6.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.6 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-15
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 1.6: "String Compression: Implement a method to perform basic
string compression using the counts of repeated characters. For example, 
the string `aabcccccaaa` would become `a2b1c5a3`. If the 'compressed' string 
would not become smaller than the original string, your method should return
the original string. You can assume that the string has only uppercase and
lowercase letters (a-z)" */

/* Approach: Iterate over the string and construct the new 'compressed' string;
then check whether the 'compressed' string is shorter, and return accordingly */

#include <string>       // std::string
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;


std::string compress_string(std::string str)
{
    size_t length = str.length();

    if(length < 3)
        return str;

    char prev = str[0];
    size_t char_count = 1;
    std::string compressed = "";

    for(size_t i = 1; i < length; i++)
    {
        if(str[i] == prev)
        {
            char_count++;
        }

        else
        {
            compressed += prev + std::to_string(char_count);
            prev = str[i];
            char_count = 1;
        }    
    }

    compressed += prev + std::to_string(char_count);
    
    return (compressed.length() < str.length() ? compressed : str);
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    std::string input;
    std::string expected;

    input = "";
    expected = "";
    assert(!expected.compare(compress_string(input)));

    input = "a";
    expected = "a";
    assert(!expected.compare(compress_string(input)));

    input = "aa";
    expected = "aa";
    assert(!expected.compare(compress_string(input)));

    input = "aaa";
    expected = "a3";
    assert(!expected.compare(compress_string(input)));

    input = "aabb";
    expected = "aabb";
    assert(!expected.compare(compress_string(input)));

    input = "abbbb";
    expected = "a1b4";
    assert(!expected.compare(compress_string(input)));

    input = "aabcccccaaa";
    expected = "a2b1c5a3";
    assert(!expected.compare(compress_string(input)));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}