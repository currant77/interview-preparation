/**
 * @file tst_Stack.cpp
 * @author Taylor Curran
 * @brief Tests for Stack
 * @version 0.1
 * @date 2020-06-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include "Stack.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    Stack<int> s;

    assert(s.empty());
    assert(!s.size());

    // Insert items at top
    s.push(1);                  // >[1]>
    assert(s.top() == 1);
    s.push(5);                  // >[1,5]>
    assert(s.top() == 5);
    s.push(12);                 // >[1,5,12]>
    assert(s.top() == 12);
    assert(s.size() == 3);

    // Remove items
    s.pop();                    // >[1,5]>
    assert(s.top() == 5);       
    s.pop();                    // >[1]>
    assert(s.top() == 1); 
    assert(s.size() == 1); 

    s.clear();                  // >[]>  

    assert(s.empty());

    try
    {
        s.pop();
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }

     try
    {
        s.top();
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }
                  
    std::cout << "All tests passed!" << std::endl;
    exit(0);   
}
