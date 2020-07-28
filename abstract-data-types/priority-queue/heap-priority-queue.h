/**
 * @file heap-priority-queue.h
 * @author Taylor Curran
 * @brief Implementation of PriorityQueue using a binary heap 
 * @date 2020-07-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef HEAP_PRIORITY_QUEUE
#define HEAP_PRIORITY_QUEUE

#include <vector>               // std::vector
#include "priority-queue.h"     // PriorityQueue 

/**
 * @brief Implementation of a generic priority queue using a heap
 * 
 * @tparam T - element type
 * @tparam Less - Priority comparison operator object
 */
template <Class T, class Less = std::less<T>>
class HeapPriorityQueue : public PriorityQueue<T,Less>
{
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();

    bool empty() const override;
    size_t size() const override;
    const T &top() const override;
    void push(const T &value) override;
    void pop() override;
    void clear() override;

private:
    Less less_comparison;
    size_t num_entries;
    std::vector<T> heap;
};

template <class T, class Less>
HeapPriorityQueue<T, Less>::HeapPriorityQueue()
{
    num_entries = 0;
}

template <class T, class Less>
HeapPriorityQueue<T, Less>::~HeapPriorityQueue()
{
}

template <class T, class Less>
bool HeapPriorityQueue<T, Less>::empty() const override
{
}

template <class T, class Less>
size_t HeapPriorityQueue<T, Less>::size() const override
{
}

template <class T, class Less>
const T &HeapPriorityQueue<T, Less>::top() const override
{
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::push(const T &value) override
{
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::pop() override
{
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::clear() override
{ 
    num_entries = 0;   
    heap.size();
}

#endif