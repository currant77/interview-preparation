/**
 * @file tst_HeapPriorityQueue.cpp
 * @author Taylor Curran
 * @brief Tests for HeapPriorityQueue
 * @version 0.1
 * @date 2020-07-19
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <cassert> // assert
#include <iostream> // std::endl, std::cout

#include "../_data-structures/heap/HeapPriorityQueue.h"

void tst_int(IPriorityQueue<int>* q)
{
    assert(!q->size());

    // Add one item -> [2]
    q->push(2); //
    assert(q->top() == 2);
    assert(q->size() == 1);
    q->pop();

    // Add several items -> [17,12,7,5,4,2,2,1]
    q->push(1);
    q->push(12);
    q->push(17);
    q->push(7);
    q->push(5);
    q->push(2);
    q->push(2);
    q->push(4);

    assert(q->top() == 17);
    assert(q->size() == 8);

    // Remove one item -> [12,7,5,4,2,2,1]
    q->pop();

    assert(q->top() == 12);

    // Remove two items -> [5,4,2,2,1]
    q->pop();
    q->pop();

    assert(q->top() == 5);

    // Remove two more items -> [2,2,1]
    q->pop();
    q->pop();

    assert(q->top() == 2);

    // Remove one more item -> [2,1]
    q->pop();
    assert(q->top() == 2);

    // Remove last two items -> []
    q->pop();
    q->pop();

    assert(!q->size());

    // Try to pop from empty priority queue
    q->pop();

    assert(!q->size());

    // Try to access top item from empty priority queue
    try {
        q->top();
        assert(false);
    } catch (const std::exception& e) {
        assert(true);
    }
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    IPriorityQueue<int>* int_pq = new HeapPriorityQueue<int>();
    tst_int(int_pq);
    delete int_pq;

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}