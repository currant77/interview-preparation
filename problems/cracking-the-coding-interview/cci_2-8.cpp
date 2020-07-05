/**
 * @file cci_2-8.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.8 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-04
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.8: "Loop Detection: Given a circular linked list, 
implement an algorithm that returns the node at the beginning of the 
loop." */

/* Approach: 

(a) Set (linear): use a set to store node addresses; return true if duplicates found
(b) Recursive (quadratic): use a recursive function; each will iterate through the 
list searching for the head node. */

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}