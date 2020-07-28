/**
 * @file priority-queue.cpp
 * @author Taylor Curran
 * @brief Generic interface for a max priority queue
 * @version 0.1
 * @date 2020-07-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>    // std::logic_error
#include <functional>   // std::less

/**
 * @brief Generic interface for a priority queue
 * 
 * @tparam T - element type
 * @tparam Less - Priority comparison operator object
 */
template<class T, class Less = std::less<T>>
class PriorityQueue
{
    public:
        virtual ~PriorityQueue(){}

        /**
         * @brief Return true if the priority queue is empty; false otherwise.
         */
        virtual bool empty() const = 0;

        /**
         * @brief Returns the number of values in the priority queue.
         */
        virtual size_t size() const = 0;

        /**
         * @brief Returns the maximum value in the priority queue.
         * @throw std::logic_error if priority queue is empty
         */
        virtual const T& top() const = 0;

        /**
         * @brief Adds the value to the priority queue
         */
        virtual void push(const T& value) = 0;

        /**
         * @brief Removes the maximum value from the priority queue
         * @throw std::logic_error if priority queue is empty
         */
        virtual void pop() = 0;

        /**
         * @brief Removes all the values from the priorty queue
         */
        virtual void clear() = 0;
};

#endif