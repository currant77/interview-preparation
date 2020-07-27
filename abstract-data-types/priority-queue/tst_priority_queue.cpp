/**
 * @file tst_priority-queue.cpp
 * @author Taylor Curran
 * @brief Tests for Priority Queue
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>              // assert
#include <iostream>             // std::endl, std::cout

#include "explicit-heap.cpp"

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    PriorityQueue<int>* q = new ExplicitHeap<int>();
    
    // Empty 
    assert(q->empty());
    assert(!q->size());
    q->clear();
    assert(q->empty());
    assert(!q->size());

    // One element
    q->push(2);               // [2]
    assert(q->top() == 2);
    assert(!q->empty());
    assert(q->size() == 1);
    q->pop();

    // Many elements
    q->push(1);
    q->push(12);
    q->push(17);
    q->push(7);
    q->push(3);
    q->push(5);
    q->push(2);
    q->push(2);
    q->push(4);               // [17,12,7,5,4,2,2,1]
    assert(q->top() == 17);
    assert(q->size() == 8);
    
    q->pop();                   // [12,7,5,4,2,2,1]
    assert(q->top() == 12);    

    q->pop();
    q->pop();                   // [5,4,2,2,1]
    assert(q->top() == 5); 

    q->pop();
    q->pop();                   // [2,2,1]
    assert(q->top() == 2);

    q->pop();                   // [2,1]
    assert(q->top() == 2);

    q->clear();                 // []
    assert(q->empty());
    assert(!q->size());

    try
    {
        q->pop();
        assert(false);
    }
    catch(const std::exception& e)
    {
        assert(true);
    }

   try
    {
        q->top();
        assert(false);
    }
    catch(const std::exception& e)
    {
        assert(true);
    }
    
    std::cout << "All tests passed!" << std::endl;
    exit(0);   
}