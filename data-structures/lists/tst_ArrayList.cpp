/**
 * @file tst_ArrayList.cpp
 * @author 
 * @brief Tests for ArrayList
 * @version 0.1
 * @date 2020-06-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include <exception>
#include "ArrayList.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    ArrayList<int> list;

    assert(list.empty());
    assert(!list.size());

    // Insert elements by index
    list.insert(0,5);               // [5] : Insert at start
    list.insert(1,6);               // [5,6] : Insert at end
    list.insert(1,3);               // [5,3,6] : Insert in middle
    assert(list.size() == 3);

    // Access and modify by index
    assert(list[0] == 5);           // Access at start
    list[0] = 6;                    // [6,3,6] : Modify at start
    assert(list[0] == 6);           
    
    assert(list[1] == 3);           // Access in middle
    list[1] = 8;                    // [6,8,6] : Modify in middle
    assert(list[1] == 8);
    
    assert(list[2] == 6);           // Access at end
    list[2] = 9;                    // [6,8,9] : Modify at end
    assert(list[2] == 9);    
    assert(list.size() == 3);                  

    // Remove by index
    list.remove(1);                 // [6,9] : Remove in middle
    assert(list.size() == 2);
    assert(list[1] == 9);

    list.remove(1);                 // [6] : Remove at end
    assert(list.size() == 1);         
    assert(list[0] == 6);
    
    list.remove(0);                 // [] : Remove at start
    assert(list.empty());

    // Test errors
    try
    {
        list[-1];                   
        assert(false);
    }
    catch(const std::exception& e){}
    
    list.clear();
    list.clear();
    
    // Clear
    assert(list.empty());
    assert(!list.size());

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}