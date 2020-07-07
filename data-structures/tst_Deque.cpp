/**
 * @file tst_Deque.cpp
 * @author Taylor Curran
 * @brief Tests for Deque
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl
#include "Deque.h"      // Deque

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl;

    Deque<int> d;

    assert(d.empty());              // []
    assert(!d.size());

    // Insert items
    d.push_front(5);                // [5]
    assert(d.front() == 5);
    assert(d.back() ==  5);
    assert(!d.empty());
    assert(d.size() == 1);

    d.push_front(4);                // [4,5]
    assert(d.front() == 4);
    assert(d.back() == 5);

    d.push_back(6);                 // [4,5,6]
    
    d.push_back(7);                 // [4,5,6,7]
    
    d.push_back(8);                 // [4,5,6,7,8]
    assert(d.front() == 4);
    assert(d.back() == 8);
    assert(d.size() == 5);

    // Remove items
    d.pop_back();                   // [4,5,6,7]
    assert(d.back() == 7);
    assert(d.size() == 4);
    
    d.push_back(10);                // [4,5,6,7,10]
   
    d.pop_back();                   // [4,5,6,7]
    assert(d.back() == 7);
    assert(d.size() == 4);

    d.pop_front();                  // [5,6,7]
    
    d.pop_front();                  // [6,7]
    
    d.pop_back();                   // [6]
    assert(d.front() == 6);
    assert(d.back() == 6);
    assert(d.size() == 1);

    d.pop_front();                  // []
    assert(d.empty());              
    assert(!d.size());

    // Errors
    try
    {
        d.pop_front();
        assert(false);
    }
    catch(const std::invalid_argument& e){ }

    try
    {
        d.pop_back();
        assert(false);
    }
    catch(const std::invalid_argument& e){ }

    try
    {
        d.front();
        assert(false);
    }
    catch(const std::invalid_argument& e){ }

    try
    {
        d.back();
        assert(false);
    }
    catch(const std::invalid_argument& e){ }

    // clear()
    d.push_back(1);             // [1]
    d.push_front(2);            // [2,1]
    d.clear();                  // []

    assert(d.empty());              
    assert(!d.size());

    std::cout << "All tests passed!" << std::endl;
}
