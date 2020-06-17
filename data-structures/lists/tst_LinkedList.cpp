/**
 * @file tst_LinkedList.cpp
 * @author 
 * @brief Tests for LinkedList
 * @version 0.1
 * @date 2020-06-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include <exception>
#include "LinkedList.h"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    LinkedList<int> list;

    assert(list.empty());
    assert(!list.size());

    // Insert elements by index
    list.insert(0,5);               // [5] : Insert at start
    list.insert(1,6);               // [5,6] : Insert at end
    list.insert(1,3);               // [5,3,6] : Insert in middle
    assert(list.size() == 3);

    // Insert elements by iterator
    auto it = list.begin();
    list.insert(it, 3);             // [3,5,3,6] : Insert at start
    assert(*it == 3);
    it++;
    list.insert(list.end(), 7);     // [3,7,5,3,6] : Insert in middle
    assert(*it == 7);
    it = list.end();
    list.insert(it,1);              // [3,7,5,3,6,7] : Insert at end
    assert(*it == 1);
    assert(list.size() == 6);

    // Access and modify by index
    assert(list[0] == 3);           // Access at start
    list[0] = 6;                    // [6,7,5,3,6,7] : Modify at start
    assert(list[0] == 6);
    assert(list[3] == 3);           // Access in middle
    list[3] = 8;                    // [6,7,5,8,6,7] : Modify in middle
    assert(list[3] == 8);
    assert(list[5] == 7);           // Access at end
    list[5] = 9;                    // [6,7,5,8,6,9] : Modify at end
    assert(list[5] == 9);                      

    /*
    // Access by const_iterator
    auto const_it = list.cbegin();
    assert(*const_it == 3);         // Access at start
    const_it++;
    assert(*const_it == 7);         // Access in middle
    const_it = --list.cend();       
    assert(*const_it == 7);         // Access at end
    */

    // Access and modify by iterator
    it = list.begin();
    assert(*it == 3);               // Access at start
    *it = 5;                  // [5,7,5,3,6,7] : Modify at start
    assert(*it == 5);
    it++;
    assert(*it == 7);               // Access in middle
    *it = 2;                        // [5,2,5,3,6,7] : Modify in middle
    assert(*it == 2);         
    it = --list.end();
    assert(*it == 7);               // Access at end
    *it = 0;                        // [5,2,5,3,6,0] : Modify at end

    // Remove by index
    list.remove(0);                 // [2,5,3,6,0] : Remove at start
    assert(list.size() == 5);
    assert(list[0] == 2);
    list.remove(2);                 // [2,5,6,0] : Remove in middle
    assert(list.size() == 4);
    assert(list[2] == 6);
    list.remove(3);                 // [2,5,6] : Remove at end
    assert(list.size() == 3);
    assert(list[2] == 6);

    // Remove by iterator
    it = list.begin()++;
    list.remove(it);                // [2,6] : Remove in middle
    assert(list.size() == 2);
    assert(*it == 6);           
    list.remove(it);                // [2] : Remove at end
    assert(list.size() == 1);
    assert(it == list.end());
    it--;
    list.remove(it);                // [] : Remove at start
    assert(list.empty());

    // Test errors
    try
    {
        list[-1];                   // Throw std::out_of_range
        assert(false);
    }
    catch(const std::out_of_range& e){}

    try
    {
        it = list.end();
        *it;                        // Throw std::out_of_range
        assert(false);
    }
    catch(const std::out_of_range& e){}

    try
    {
        it = list.begin();
        list.remove(it);            // Throw std::out_of_range
        assert(false);
    }
    catch(const std::exception& e){}

    // Clear

    assert(list.empty());
    assert(!list.size());

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}