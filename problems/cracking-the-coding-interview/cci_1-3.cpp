/**
 * @file cci_1-3.cpp
 * @author Taylor Curran
 * @brief Solution to problem 1.3 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-07
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 1.3: "URLify: Write a method to replace all spaces in a string 
with `%20`. You may assume that the string has sufficient memory space at
the end to gold the additional characters, and that you are given the "true"
length of the string.*/

/* Approach: There are many possible approaches to this problem. I chose to 
implement it by first scanning for the number of spaces, and then iterating
from the back foward to move the values more efficiently */

#include <string>       // std::string
#include <vector>       // std::vector
#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;

void URLify(char* string, size_t true_length)
{
    // Count spaces
    size_t space_count = 0;
    for(size_t i = 0; i < true_length; i++)
    {
        if(*(string + i) == ' ')
            space_count++;
    }

    // Work back from end
    int remove = true_length - 1;
    int insert = true_length + (2 * space_count) - 1;

    while(remove >= 0 && insert >= 0 && insert != remove)
    {
        if(*(string + remove) == ' ')
        {
            *(string + insert) = '0';
            *(string + insert - 1) = '2';
            *(string + insert - 2) = '%';

            insert -= 3;
            remove--;
        }

        else
        {
            *(string + insert) = *(string + remove);
            remove--;
            insert--;
        }            
    }
}

bool compare_string(const char* string, const std::string& compare)
{
    for(size_t i = 0; i < compare.length(); i++)
    {
        if(*(string + i) != compare[i])
            return false;
    }

    return true;
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    // Empty string
    char* empty = NULL;
    URLify(empty, 0);
    assert(compare_string(empty, ""));

    // No spaces
    char* no_spaces = new char[9]{'n','s','p'};
    URLify(no_spaces, 8);
    assert(compare_string(no_spaces, "nsp"));

    // One space
    char* one_space = new char[6]{'t',' ','c',' ',' '};
    URLify(one_space, 3);
    assert(compare_string(one_space, "t%20c"));

    // Two spaces
    char* two_space = new char[18]{'M','r','.',' ','J','o','h','n',' ','S','m','i','t','h',' ',' ',' ',' '};
    URLify(two_space, 14);
    assert(compare_string(two_space, "Mr.%20John%20Smith"));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}