/**
 * @file Queue.h
 * @author Taylor Curran
 * @brief Queue wity basic functionality and support for const
 * iteration over all positions in the queue.
 * @version 0.1
 * @date 2020-06-19
 * 
 * @note Implemented as a wrapper to Linked List
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "../lists/LinkedList.h"

/**
 * @brief Queue of values of type T
 * @tparam T - template parameter
 */
template<class T>
class Queue
{
    public:
        // Definitions
        typename LinkedList<T>::const_iterator const_iterator;
        
        Queue();
        ~Queue();

        bool empty() const;
        size_t size() const;

        /**
         * @brief Returns a reference to the value at the 
         * front of the queue
         * @return T& - reference to value at the front of 
         * the queue
         */
        T& front();

        /**
         * @brief Returns a const reference to the value at the 
         * front of the queue
         * @return const T& - const reference to value at the front of 
         * the queue
         */
        const T& front() const;

        /**
         * @brief Returns a  reference to the value at the 
         * back of the queue
         * @return T& - reference to value at the back of 
         * the queue
         */
        T& back();

        /**
         * @brief Returns a reference to the value at the 
         * back of the queue
         * @return const T& - const reference to value at the back of 
         * the queue
         */
        const T& back() const;

        /**
         * @brief Returns a const iterator to the front of the queue
         * @return const_iterator 
         */
        typename Queue<T>::const_iterator cbegin() const;

        /**
         * @brief Returns a const iterator to the back of the queue
         * @return const_iterator 
         */
        typename Queue<T>::const_iterator cend() const;

        /**
         * @brief Inserts \p value at the back of the queue 
         * @param value - value to be inserted
         */
        void push_back(const T& value);

        /**
         * @brief Removes the value at the back of the queue
         * @throw std::invalid_argument if the queue is empty
         */
        void pop_front();

        /**
         * @brief Removes all values from the queue 
         */
        void clear();

    private:
        LinkedList<T> list;
};

template<class T>
Queue<T>::Queue()
{

}

template<class T>
Queue<T>::~Queue()
{

}

template<class T>
bool Queue<T>::empty() const
{
    return list.empty();
}

template<class T>
size_t Queue<T>::size() const
{
    return list.size();
}

template<class T>
T& Queue<T>::front()
{
    return list[0];
}

template<class T>
const T& Queue<T>::front() const
{
    return list[0];
}

template<class T>
T& Queue<T>::back()
{
    return list[list.size()];
}

template<class T>
const T& Queue<T>::back() const
{
    return list[list.size()];
}

template<class T>
typename Queue<T>::const_iterator Queue<T>::cbegin() const
{
    return list.cbegin();
}

template<class T>
typename Queue<T>::const_iterator Queue<T>::cend() const
{
    return list.cend();
}

template<class T>
void Queue<T>::push_back(const T& value)
{
    return list.push_back(value);
}

template<class T>
void Queue<T>::pop_front()
{
    return list.pop_front();
}

template<class T>
void Queue<T>::clear()
{
    list.clear();
}

#endif