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
        class const_iterator;

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
        const_iterator begin() const;

        /**
         * @brief Returns an iterator to the end of the list
         */
        iterator end();

        /**
         * @brief Returns a constant iterator to the end of the list
         */
        const_iterator end() const;

        /**
         * @brief Inserts \p value at the given \p index
         * @throw std::out_of_range if \p index is not in range [0, size()]
         */
        void insert(size_t index, const T& value);

        /**
         * @brief Inserts \p value at the given \p position
         */
        iterator insert(iterator position, const T& value);

        /**
         * @brief Removes the value at \p index from the list
         * @throw std::out_of_range if \p index is not in range [0, size())
         */
        void remove(size_t index);

        /**
         * @brief Removes the value at \p position from the list
         */
        iterator remove(iterator pos);

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

    iterator();
    ~iterator();

    iterator(const iterator& it);               // Copy constructor
    iterator& operator=(const iterator& it);    // Assignment operator

    T& operator*() const;
    T* operator->() const;

    iterator& operator++();                     // Prefix increment
    iterator& operator++(int);                  // Postfix increment
    iterator& operator--();                     // Prefix decrement
    iterator& operator--(int);                  // Postfix decrement 

    bool operator==(const iterator& other); 
    bool operator!=(const iterator& other);
};

template<class T>
class LinkedList<T>::const_iterator
{
    public:

    const_iterator();
    ~const_iterator();

    const_iterator(const const_iterator& it);               // Copy constructor
    const_iterator& operator=(const const_iterator& it);    // Assignment operator

    T& operator*() const;
    T* operator->() const;

    const_iterator& operator++();                     // Prefix increment
    const_iterator& operator++(int);                  // Postfix increment
    const_iterator& operator--();                     // Prefix decrement
    const_iterator& operator--(int);                  // Postfix decrement 

    bool operator==(const const_iterator& other); 
    bool operator!=(const const_iterator& other);
};

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
}

template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::begin() const
{
    // TODO
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    // TODO
}

template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::end() const
{
    // TODO
}

template<class T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    // TODO
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator pos, const T& value)
{
    // TODO
}

template<class T>
void LinkedList<T>::remove(size_t index)
{
    // TODO
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::remove(iterator pos)
{
    // TODO
}

template<class T>
void LinkedList<T>::clear()
{
    // TODO
}

#endif