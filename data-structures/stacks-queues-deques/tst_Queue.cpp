/**
 * @file tst_Queue.cpp
 * @author Taylor Curran
 * @brief Tests for Queue
 * @version 0.1
 * @date 2020-06-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include "Queue.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    Queue<int> q;

    assert(q.empty());
    assert(!q.size());
    assert(q.cbegin() == q.cend());

    // Insert items
    q.push_back(1);                  // <[1]<
    assert(q.front() == 1);
    assert(q.back() == 1);
    
    q.push_back(5);                  // <[1,5]<
    assert(q.back() == 5);

    q.push_back(12);                 // <[1,5,12]<
    assert(q.back() == 12);
    assert(q.front() == 1);
    assert(q.size() == 3);

    // Iterate over values
    Queue<int>::const_iterator cit = q.cbegin();
    assert(*(cit++) == 1);
    assert(*(cit++) == 5);
    assert(*(cit--) == 12);
    assert(*(cit++) == 5);
    assert(*(cit++) == 12);
    assert(cit == q.cend());

    // Remove items
    q.pop_front();              // <[5,12]<
    assert(q.front() == 5);
    assert(q.back() == 12);

    q.pop_front();              // >[12]>
    assert(q.front() == 12);
    assert(q.back() == 12);
    assert(q.size());

    q.clear();                  // >[]> 
    q.clear(); 

    assert(q.empty());

    try
    {
        q.pop_front();
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }

    try
    {
        q.front();
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }

    try
    {
        q.cbegin()++;
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
    
    try
    {
        q.cbegin()--;
    }
    catch(const std::invalid_argument& e)
    {
        assert(true);
    }
                  
    std::cout << "All tests passed!" << std::endl;
    exit(0);   
}