/**
 * @file 12-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 12.2 from Cracking the Coding Interview
 * @version 0.1
 * @date <date>
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 12.2: "Reverse String: Implement a function that reverses a null-
terminated string. */

#include <cassert> // assert
#include <iostream> // std::cout, std::endl;
#include <string.h> // strcmp

void reverse(char* str)
{
    if (!str)
        return;

    // Find length
    size_t length = 0;
    while (str[length] != '\0')
        length++;

    // Reverse list
    char temp;
    for (size_t i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    char actual[20];
    char expected[20];

    // Empty string
    strcpy(actual, "");
    strcpy(expected, "");

    reverse(actual);
    assert(!strcmp(actual, expected));

    // Single character
    strcpy(actual, "a");
    strcpy(expected, "a");

    reverse(actual);
    assert(!strcmp(actual, expected));

    // Long string 1
    strcpy(actual, "abc");
    strcpy(expected, "cba");

    reverse(actual);
    assert(!strcmp(actual, expected));

    // Long string 2
    strcpy(actual, "racecar 56");
    strcpy(expected, "65 racecar");

    reverse(actual);
    assert(!strcmp(actual, expected));

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}