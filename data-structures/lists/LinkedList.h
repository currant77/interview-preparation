/**
 * @file IList.h
 * @author Taylor Curran
 * @brief Linked list
 * @version 0.1
 * @date 2020-06-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stddef.h"

/**
 * @brief A linked list of values of type T
 * @tparam T - the type of the values stored in the list
 */
template<class T>
class LinkedList
{
    public:
        // Forward declarations
        class iterator;
        // class const_iterator;

        /**
         * @brief Returns true if the list is empty; false otherwise
         */
        bool empty() const;

        /**
         * @brief Returns the number of values in the list
         */
        size_t size() const;

        /**
         * @brief Returns a reference to the value at the 
         * position given by \p index
         * @throw std::out_of_range if \p index is not in range [0, size())
         */
        T& operator[](size_t index);

        /**
         * @brief Returns a constant reference to the value at the 
         * position given by \p index
         * @throw std::out_of_range if \p index is not in range [0, size())
         */
        const T& operator[](size_t index) const;

        /**
         * @brief Returns an iterator to the beginning of the list 
         */
        iterator begin();

        /**
         * @brief Returns a constant iterator to the beginning of the list 
         */
        // const_iterator cbegin() const;

        /**
         * @brief Returns an iterator to the end of the list
         */
        iterator end();

        /**
         * @brief Returns a constant iterator to the end of the list
         */
        // const_iterator cend() const;

        /**
         * @brief Inserts \p value at the given \p index
         * @throw std::out_of_range if \p index is not in range [0, size()]
         */
        void insert(size_t index, const T& value);

        /**
         * @brief Inserts \p value at the given \p position
         * @return iterator - iterator that points to the newly inserted value
         */
        iterator insert(iterator position, const T& value);

        /**
         * @brief Removes the value at \p index from the list
         * @throw std::out_of_range if \p index is not in range [0, size())
         */
        void remove(size_t index);

        /**
         * @brief Removes the value at \p position from the list
         * @throw std::out_of_range if \p position == list.end()
         * @return iterator - iterator that points to the next value
         * after the value that was removed; if the last element was 
         * removed, points to list.end().
         */
        iterator remove(iterator position);

        /**
         * @brief Removes all the values from the list
         */
        void clear();

    private:
        // Forward declaration
        struct Node;
        friend class Node;

        Node* head;
        Node* tail;
        size_t num_entries;
};

// Nested classes and structs

template<class T>
class LinkedList<T>::iterator
{
    public:

    iterator()
    {
        // TODO
    }

    ~iterator()
    {
        // TODO
    }

    iterator(const iterator& it)   // Copy constructor
    {
        // TODO
        return;
    }

    iterator& operator=(const iterator& it)   // Assignment operator
    {
        // TODO
        return *this;
    }

    T& operator*() const   // Dereference
    {
        // TODO
        T t;
        return t;
    }

    T* operator->() const
    {
        // TODO
        return new T();
    }

    iterator& operator++()  // Prefix increment
    {
        // TODO
        return &this;
    }

    iterator& operator++(int)   // Postfix increment
    {
        // TODO
        return *this;
    }

    iterator& operator--()   // Prefix decrement
    {
        // TODO
        return *this;
    }

    iterator& operator--(int)   // Postfix decrement 
    {
        // TODO
        return *this;
    }

    bool operator==(const iterator& other)
    {
        // TODO
        return false;
    } 

    bool operator!=(const iterator& other)
    {
        // TODO
        return false;
    }
};

/**
template<class T>
class LinkedList<T>::const_iterator
{
    public:

    const_iterator()
    {
        // TODO
    }

    ~const_iterator()
    {
        // TODO
    }

    const_iterator(const const_iterator& it)   // Copy constructor
    {
        // TODO
        return;
    }

    const_iterator& operator=(const const_iterator& it)   // Assignment operator
    {
        // TODO
        return *this;
    }

    T& operator*() const    // Dereferencing
    {
        // TODO
        T t;
        return t;
    }

    T* operator->() const
    {
        // TODO
        return new T();
    }

    const_iterator& operator++()   // Prefix increment
    {
        // TODO
        return *this;
    }

    const_iterator& operator++(int)   // Postfix incremen
    {
        // TODO
        return *this;
    }

    const_iterator& operator--()   // Prefix decrement
    {
        // TODO
        return *this;
    }

    const_iterator& operator--(int)    // Postfix decrement 
    {
        // TODO
        return *this;
    }

    bool operator==(const const_iterator& other)
    {
        // TODO
        return false;
    }

    bool operator!=(const const_iterator& other)
    {
        // TODO
        return false;
    }
};
**/

template<class T>
struct LinkedList<T>::Node
{
    // Allow iterators access to node
    friend class iterator;
    friend class const_iterator;

    T value;
    Node* previous = NULL;
    Node* next = NULL;
};

// Member functions

template<class T>
bool LinkedList<T>::empty() const
{
    // TODO
    return false;
}

template<class T>
size_t LinkedList<T>::size() const
{
    // TODO
    return 0;
}

template<class T>
T& LinkedList<T>::operator[](size_t index)
{
    // TODO
    T t;
    return t;
}

template<class T>
const T& LinkedList<T>::operator[](size_t index) const
{
    // TODO
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    // TODO
    return iterator();
}

/**
template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const
{
    // TODO
    return const_iterator();
}
*/

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    // TODO
    return iterator();
}

/*
template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::cend() const
{
    // TODO
    return const_iterator();
}
*/

template<class T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    // TODO
    return;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator pos, const T& value)
{
    // TODO
    return iterator();
}

template<class T>
void LinkedList<T>::remove(size_t index)
{
    // TODO
    return;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::remove(iterator pos)
{
    // TODO
    return iterator();
}

template<class T>
void LinkedList<T>::clear()
{
    // TODO
    return;
}

#endif