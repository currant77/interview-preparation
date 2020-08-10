/**
 * @file IPriorityQueue.h
 * @author Taylor Curran
 * @brief Minimal priority queue interface
 * @version 0.1
 * @date 2020-08-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef I_PRIORITY_QUEUE_H
#define I_PRIORITY_QUEUE_H

#include <exception> // std::logic_error
#include <functional> // std::less

/**
 * @brief Priority queue abstract data type
 * 
 * @tparam T Data type
 * @tparam Less Priority comparison object (see std::less) 
 */
template <class T, class Priority_Less = std::less<T>>
class IPriorityQueue {

public:
    virtual ~IPriorityQueue();

    /**
     * @brief Returns the number of items in the priority queue
     * 
     * @return size_t Number of items in the priority queue
     */
    virtual size_t size() const noexcept = 0;

    /**
     * @brief Returns the highest priority item
     * @throw std::logic_error if priority queue is empty
     * @return const T& Const reference to highest priority item
     */
    virtual const T& top() const = 0;

    /**
     * @brief Adds the item to the priority queue
     * 
     * @param item Item to add to the priority queue 
     */
    virtual void push(const T& item) noexcept = 0;

    /**
     * @brief Removes highest priority item from the priority queue; if the 
     * priority queue is empty, does nothing
     * 
     */
    virtual void pop() noexcept = 0;
};

template <class T, class Priority>
IPriorityQueue<T, Priority>::~IPriorityQueue()
{
}

#endif