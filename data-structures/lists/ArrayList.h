/**
 * @file ArrayList.h
 * @author Taylor Curran
 * @brief Array list with basic functionality
 * @version 0.1
 * @date 2020-06-19
 * 
 * @note ArrayList does not implement the iterator pattern.
 * See LinkedList for an example; it is straighforward to 
 * implement this for ArrayList.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "stddef.h"   // size_t
#include <stdexcept>  // std::out_of_range, std::invalid_argument
#include <utility>    // std::move

/**
 * @brief Array list of values of type T; basic functionality
 */
template<class T>
class ArrayList
{
    public:
        /**
         * @brief Construct a new array list
         * @param initial_capacity - initial capacity of the array list; 
         * must be a positive integer
         */
        ArrayList(size_t initial_capacity = INITIAL_CAPACITY);

        ~ArrayList();   

        /**
         * @brief Returns true if the list is empty; false otherwise
         */
        bool empty() const;

        /**
         * @brief Returns the number of value in the list
         * @return size_t - number of value in the list
         */
        size_t size() const;

        /**
         * @brief Returns the value at \p index in the list
         * @throw std::out_of_range if index not in [0, size()) 
         * @param index - list index
         * @return T& - value at \p index in the list
         */
        T& operator[](size_t index);

        /**
         * @brief Returns the value at \p index in the list
         * @throw std::out_of_range if index not in [0, size()) 
         * @param index - list index
         * @return const T& - value at \p index in the list
         */
        const T& operator[](size_t index) const;

        /**
         * @brief Inserts \p value at the front of the list
         * @param value - value to insert
         */
        void push_front(const T& value);

        /**
         * @brief Inserts \p value at the back of the list
         * @param value - value to insert
         */
        void push_back(const T& value);

        /**
         * @brief Inserts \p value at \p index in list
         * @param index - list index at which to insert value
         * @param value - value to insert into list
         * @throw std::out_of range if index not in range [0, size()]
         */
        void insert(size_t index, const T& value);

        /**
         * @brief Removes value at the front of the list
         * @throw std::out_of_range if list is empty
         */
        void pop_front();

        /**
         * @brief Removes value at the end of the list
         * @throw std::out_of_range if list is empty
         */
        void pop_back();

        /**
         * @brief Removes the value at \p index in the list 
         * @param index - list index at which to remove value
         * @throw std::out_of_range if index is not in range [0, size())
         */
        void remove(size_t index);

        /**
         * @brief Removes all the values from the list 
         */
        void clear();

    private:
        // Constants
        static const size_t INITIAL_CAPACITY = 100;
        static const int EXPANSION_FACTOR = 2;

        // Members
        size_t initial_capacity;
        size_t capacity;
        size_t num_entries;
        T* array;

        void resize();
};

template<class T>
ArrayList<T>::ArrayList(size_t initial_capacity) :
    initial_capacity(initial_capacity), capacity(initial_capacity),
    num_entries(0), array(new T[initial_capacity])
{
    
}

template<class T>     
ArrayList<T>::~ArrayList()
{
    delete[] array;
}  

template<class T> 
bool ArrayList<T>::empty() const
{
    return !num_entries;
}

template<class T> 
size_t  ArrayList<T>::size() const
{
    return num_entries;
}

template<class T>
T& ArrayList<T>::operator[](size_t index)
{
    if(index < 0 || index >= num_entries)
        throw std::out_of_range("Index must be in range [0, size())");

    return array[index];
}

template<class T>
const T& ArrayList<T>::operator[](size_t index) const
{
    return ArrayList<T>::operator[](index);
}

template<class T>
void ArrayList<T>::push_front(const T& value)
{    
    insert(0, value);
}

template<class T>
void ArrayList<T>::push_back(const T& value)
{
    insert(num_entries, value);
}

template<class T>
void ArrayList<T>::insert(size_t index, const T& value)
{
    if(index < 0 || index > num_entries)
        throw std::out_of_range("Index must be in range [0, size()]");
    
    // Expand array if it is full
    resize();

    // Move elements over
    for(size_t i = size(); i > index; --i)
        array[i] = array[i-1];

    array[index] = value;
    ++num_entries;
}

template<class T>
void ArrayList<T>::pop_front()
{
    remove(0);
}

template<class T>
void ArrayList<T>::pop_back()
{
    remove(num_entries - 1);
}

template<class T>
void ArrayList<T>::remove(size_t index)
{
    if(index < 0 || index >= num_entries)
        throw std::out_of_range("Index must be in range [0, size())");

    // Remove value
    delete (array + index);
    --num_entries;

    // Shift values over
    for(int i = index; i < num_entries; i++)
        array[i] = array[i+1];
}

template<class T>
void ArrayList<T>::clear()
{
    num_entries = 0;
    capacity = initial_capacity;

    delete[] array;
    array = new T[capacity];    
}

template<class T>
void ArrayList<T>::resize()
{
    // Expand the array if its full
    if(num_entries >= capacity)
    {
        size_t new_capacity = capacity * EXPANSION_FACTOR;
        T* new_array = new T[new_capacity];

        std::move(array, array + num_entries, new_array);

        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }
}

#endif