/**
 * @file IList.h
 * @author Taylor Curran
 * @brief Generic list interface
 * @version 0.1
 * @date 2020-06-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef I_LIST_H
#define I_LIST_H

#include "stddef.h"

/**
 * @brief A generic list interface
 * @tparam T - the type of the values stored in the list
 */
template<class T>
class IList
{
    public:

    // Forward declarations
    class iterator;
    class const_iterator;

    // Capacity
    bool empty() const;
    size_t size() const;

    // Element access
    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Iterators
    iterator begin();
    const_iterator cbegin() const;

    iterator end();
    const_iterator cend() const;

    // Modifiers
    void insert(size_t index, const T& value);
    iterator insert(iterator pos, const T& value);

    void remove(size_t index);
    iterator remove(iterator pos);

    void push_front(const T& value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();

    void clear();
};

template<class T>
class IList<T>::iterator
{
    public:

    T& operator*() const;
    T* operator->() const;

    iterator& operator++();         // Prefix increment
    iterator& operator++(int);      // Postfix increment
    iterator& operator--();         // Prefix decrement
    iterator& operator--(int);         // Postfix decrement 

    bool operator==(const iterator& other); 
    bool operator!=(const iterator& other);
};

template<class T>
class IList<T>::const_iterator
{
    public:

    const T& operator*() const;
    const T& operator->() const;

    const_iterator& operator++();         // Prefix increment
    const_iterator& operator++(int);      // Postfix increment
    const_iterator& operator--();         // Prefix decrement
    const_iterator& operator--(int);         // Postfix decrement  

    bool operator==(const const_iterator& other); 
    bool operator!=(const const_iterator& other);
};

#endif