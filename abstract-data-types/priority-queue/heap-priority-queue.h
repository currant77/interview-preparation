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

#include <vector>           // std::vector
#include <exception>        // std::logic_error
#include "priority-queue.h" // PriorityQueue

/**
 * @brief Implementation of a priority queue using a heap
 */
template <class T, class Less = std::less<T>>
class HeapPriorityQueue : public PriorityQueue<T, Less>
{
public:
    HeapPriorityQueue(std::vector<T> data = std::vector<T>());
    ~HeapPriorityQueue();

    bool empty() const override;
    size_t size() const override;
    const T &top() const override;
    void push(const T &value) override;
    void pop() override;
    void clear() override;

private:
    Less less_comparison;
    std::vector<T> heap;

    void swapUp(size_t index);
    void swapDown(size_t index);
};

template <class T, class Less>
HeapPriorityQueue<T, Less>::HeapPriorityQueue(std::vector<T> data)
{
    heap = data;

    // Heapify
    for (int i = heap.size() - 1; i >= 0; i--)
    {
        swapDown(i);
    }
}

template <class T, class Less>
HeapPriorityQueue<T, Less>::~HeapPriorityQueue()
{
    heap.clear();
}

template <class T, class Less>
bool HeapPriorityQueue<T, Less>::empty() const
{
    return !heap.size();
}

template <class T, class Less>
size_t HeapPriorityQueue<T, Less>::size() const
{
    return heap.size();
}

template <class T, class Less>
const T &HeapPriorityQueue<T, Less>::top() const
{
    if (heap.empty())
    {
        throw std::logic_error("Cannot call top() on empty priority queue");
    }

    return heap.front();
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::push(const T &value)
{
    heap.push_back(value);
    swapUp(heap.size() - 1);
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::pop()
{
    if (heap.empty())
    {
        throw std::logic_error("Cannot call pop() on empty priority queue");
    }

    T temp = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    swapDown(0);
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::clear()
{
    heap.clear();
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::swapUp(size_t index)
{
    if (!index)
        return;

    size_t parent = (index - 1) / 2;

    if (less_comparison(heap[parent], heap[index]))
    {
        T temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        swapUp(parent);
    }
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::swapDown(size_t index)
{
    size_t index_max = index;
    size_t left_child = (2 * index) + 1;
    size_t right_child = (2 * index) + 2;

    if (left_child < heap.size() &&
        less_comparison(heap[index_max], heap[left_child]))
    {
        index_max = left_child;
    }

    if (right_child < heap.size() &&
        less_comparison(heap[index_max], heap[right_child]))
    {
        index_max = right_child;
    }

    if (index_max != index)
    {
        T temp = heap[index];
        heap[index] = heap[index_max];
        heap[index_max] = temp;

        swapDown(index_max);
    }
}

#endif