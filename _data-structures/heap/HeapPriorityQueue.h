/**
 * @file HeapPriorityQueue.h
 * @author Taylor Curran
 * @brief Implementation of IPriorityQueue interface using a binary heap 
 * @date 2020-07-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef HEAP_PRIORITY_QUEUE
#define HEAP_PRIORITY_QUEUE

#include <vector> // std::vector

// IPriorityQueue
#include "../../_abstract-data-types/priority-queue/IPriorityQueue.h"

/**
 * @brief Implementation of the IPriorityQueue interface using a binary heap
 * 
 * @tparam T Data type
 * @tparam Less Priority comparison object (see std::less) 
 * 
 * @details Parent of a node at index i is at index (i - 1) / 2; children are at
 * indices (2 * i) + 1 and (2 * i) + 2.
 */
template <class T, class Less = std::less<T>>
class HeapPriorityQueue : public IPriorityQueue<T, Less> {
public:
    explicit HeapPriorityQueue(std::vector<T> data = std::vector<T>());
    ~HeapPriorityQueue();

    size_t size() const noexcept override final;
    const T& top() const override final;
    void push(const T& item) noexcept override final;
    void pop() noexcept override final;

private:
    Less less_comparison;
    std::vector<T> heap;

    /**
     * @brief Recursively swaps the item at \p index in the heap with its 
     * parent item to restore the heap condition.
     * 
     * @param index 
     */
    void swapUp(size_t index) noexcept;

    /**
     * @brief Recursively swaps the item at \p index in the heap with its
     * children to restore the heap condition.
     * 
     * @param index 
     */
    void swapDown(size_t index) noexcept;
};

template <class T, class Less>
HeapPriorityQueue<T, Less>::HeapPriorityQueue(std::vector<T> data)
{
    heap = data;

    // Heapify
    for (int i = heap.size() - 1; i >= 0; i--) {
        swapDown(i);
    }
}

template <class T, class Less>
HeapPriorityQueue<T, Less>::~HeapPriorityQueue()
{
    heap.clear();
}

template <class T, class Less>
size_t HeapPriorityQueue<T, Less>::size() const noexcept
{
    return heap.size();
}

template <class T, class Less>
const T& HeapPriorityQueue<T, Less>::top() const
{
    if (heap.empty()) {
        throw std::logic_error("Cannot call top() on empty priority queue");
    }

    return heap.front();
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::push(const T& item) noexcept
{
    heap.push_back(item);
    swapUp(heap.size() - 1);
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::pop() noexcept
{
    if (heap.empty()) {
        return;
    }

    T temp = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    swapDown(0);
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::swapUp(size_t index) noexcept
{
    if (!index)
        return;

    size_t parent = (index - 1) / 2;

    if (less_comparison(heap[parent], heap[index])) {
        T temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        swapUp(parent);
    }
}

template <class T, class Less>
void HeapPriorityQueue<T, Less>::swapDown(size_t index) noexcept
{
    size_t index_max = index;
    size_t left_child = (2 * index) + 1;
    size_t right_child = (2 * index) + 2;

    if (left_child < heap.size() && less_comparison(heap[index_max], heap[left_child])) {
        index_max = left_child;
    }

    if (right_child < heap.size() && less_comparison(heap[index_max], heap[right_child])) {
        index_max = right_child;
    }

    if (index_max != index) {
        T temp = heap[index];
        heap[index] = heap[index_max];
        heap[index_max] = temp;

        swapDown(index_max);
    }
}

#endif