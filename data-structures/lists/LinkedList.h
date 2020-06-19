/**
 * @file LinkedList.h
 * @author Taylor Curran
 * @brief Linked list with iterators
 * @version 0.1
 * @date 2020-06-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stddef.h"     // size_t
#include <stdexcept>    // std::out_of_range, std::invalid_argument
#include <algorithm>    // std::swap
#include <iterator>     // std::bidirectional_iterator_tag

/**
 * @brief Linked list of values of type T; supports 
 * operations by index and via iterators
 * @tparam T - the type of the values stored in the list
 */
template<class T>
class LinkedList
{
    public:
        // Forward declarations
        class iterator;
        class const_iterator;

        // Give iterators access to private members (?)
        friend class iterator;
        friend class const_iterator;

        LinkedList(); 
        ~LinkedList(); 
        LinkedList(const LinkedList<T>& other);
        LinkedList<T>& operator=(const LinkedList<T>& other);

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
        const_iterator cbegin() const;

        /**
         * @brief Returns an iterator to the end of the list
         */
        iterator end();

        /**
         * @brief Returns a constant iterator to the end of the list
         */
        const_iterator cend() const;

        /**
         * @brief Inserts \p value at the front of the list
         * 
         * @param value 
         */
        void push_front(const T& value);

        /**
         * @brief Inserts \p value at the end of the list
         * 
         * @param value 
         */
        void push_back(const T& value);

        /**
         * @brief Inserts \p value at the given \p index
         * @throw std::out_of_range if \p index is not in range [0, size()]
         */
        void insert(size_t index, const T& value);

        /**
         * @brief Inserts \p value at the given \p position
         * @throw std::invalid_argument if iterator is not for this list
         * @return iterator - iterator that points to the newly inserted value
         */
        iterator insert(iterator position, const T& value);

        /**
         * @brief Removes the value at the front of the list
         * @throw std::invalid_argument if list is empty
         */
        void pop_front();
        
        /**
         * @brief Removes the value at the end of the list
         * @throw std::invalid_argument if list is empty
         */
        void pop_back();
        
        /**
         * @brief Removes the value at \p index from the list
         * @throw std::out_of_range if \p index is not in range [0, size())
         */
        void remove(size_t index);

        /**
         * @brief Removes the value at \p position from the list
         * @throw std::out_of_range if \p position == list.end()
         * @throw std::invalid_argument if iterator is not for this list
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
        // Forward declarations
        struct Node;
        friend class Node;

        // Members
        Node* head;
        Node* tail;
        size_t num_entries;

        /**
         * @brief Returns a pointer to the node at \p index
         * @throw std::out_of_range if \p index is not in [0,size())
         */
        Node* find(size_t index) const;
};

template<class T>
class LinkedList<T>::iterator
{
    public:
        // Definitions
        typedef std::bidirectional_iterator_tag iterator_category;

        ~iterator(){ }

        iterator(const iterator& it)   // Copy constructor
        {
            list = it.list;
            node = it.node;   
        }

        iterator& operator=(const iterator& it)   // Assignment operator
        {
            list = it.list;
            node = it.node;
            return *this;
        }

        /**
         * @brief Returns a reference to the currently referenced item
         * or if iterator is not for this list
         */
        T& operator*() const   // Dereference
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
                return node->value;
        }

        /**
         * @brief Returns an pointer to referenced item. T must be 
         * a class or struct - enforced by compiler.
         * @throw std::invalid_argument if the iterator is equal to end()
         */
        T* operator->() const
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
                return &(node->value);
        }

        /**
         * @brief Advances the iterator
         * @throw std::invalid_argument if the iterator is equal to end()
         * @return iterator& - iterator to the next position
         */
        iterator& operator++()  // Prefix increment
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
            {
                node = node->next;
                return *this;
            }
        }

        /**
         * @brief Advances the iterator
         * @throw std::invalid_argument if the iterator is equal to end()
         * @return iterator& - iterator to the current position 
         */
        iterator operator++(int)   // Postfix increment
        {
            iterator copy = *this;
            ++(*this);
            return copy;
        }

        /**
         * @brief Moves the iterator backwards
         * @throw std::invalid_argument if the iterator is equal to begin()
         * @return iterator& - interator to the previous position
         */
        iterator& operator--()   // Prefix decrement
        {
            if(node == list->head)
                throw std::invalid_argument("Iterator equal to begin()");
            
            if(node == NULL)
                node = list->tail;
            
            else
                node = node->previous;
            
            return *this;
        }

        /**
         * @brief Moves the iterator backwards
         * @throw std::invalid_argument if the iterator is equal to begin()
         * @return iterator& - iterator to the current position
         */
        iterator operator--(int)   // Postfix decrement 
        {
            iterator copy = *this;
            --(*this);
            return copy;
        }

        /**
         * @brief Compares iterators for equality; returns 
         * true if both refer to the same position in the same list
         */
        bool operator==(const iterator& other)
        {
            return node == other.node;
        } 

        bool operator!=(const iterator& other)
        {
            return !(operator==(other));
        }

    private:
        // Only LinkedList<T> has access to private constructor
        friend class LinkedList<T>;

        iterator(LinkedList<T>* list, Node* node) :
            list(list), node(node){ }

        Node* node;
        LinkedList<T>* list;
};

template<class T>
class LinkedList<T>::const_iterator
{
    public:
        // Definitions
        typedef std::bidirectional_iterator_tag iterator_category;

        ~const_iterator(){ }

        const_iterator(const const_iterator& it)   // Copy constructor
        {
            list = it.list;
            node = it.node;
        }

        const_iterator& operator=(const const_iterator& it)   // Assignment operator
        {
            list = it.list;
            node = it.node;
            return *this;
        }

        /**
         * @brief Returns a const reference to the currently referenced item
         * @throw std::invalid_argument if the iterator is equal to end()
         */
        const T& operator*() const    // Dereferencing
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
                return node->value;
        }

        /**
         * @brief Returns a const pointer to referenced item. T must be 
         * a class or struct - enforced by compiler.
         * @throw std::invalid_argument if the iterator is equal to end()
         */
        const T* operator->() const
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
                return &(node->value);
        }

        /**
         * @brief Advances the iterator
         * @throw std::invalid_argument if the iterator is equal to end()
         * @return const_iterator& - const iterator to the next position
         */
        const_iterator& operator++()   // Prefix increment
        {
            if(node == NULL)
                throw std::invalid_argument("Iterator equal to end()");
            else
            {
                node = node->next;
                return *this;
            }
        }

        /**
         * @brief Advances the iterator
         * @throw std::invalid_argument if the iterator is equal to end()
         * @return const_iterator& - const iterator to the current position 
         */
        const_iterator operator++(int)   // Postfix incremen
        {
            const_iterator copy = *this;
            ++(*this);
            return copy;
        }

        /**
         * @brief Moves the iterator backwards
         * @throw std::invalid_argument if the iterator is equal to begin()
         * @return const_iterator& - const iterator to the previous position
         */
        const_iterator& operator--()   // Prefix decrement
        {
            if(node == list->head)
                throw std::invalid_argument("Iterator equal to begin()");
            
            if(node == NULL)
                node = list->tail;
            
            else
                node = node->previous;
            
            return *this;
        }

        /**
         * @brief Moves the iterator backwards
         * @throw std::invalid_argument if the iterator is equal to begin()
         * @return const_iterator& - const iterator to the current position
         */
        const_iterator operator--(int)    // Postfix decrement 
        {
            const_iterator copy = *this;
            --(*this);
            return copy;
        }

        /**
         * @brief Compares iterators for equality; returns 
         * true if both refer to the same position in the same list
         */
        bool operator==(const const_iterator& other)
        {
            return node == other.node;
        }

        bool operator!=(const const_iterator& other)
        {
            return !(operator==(other));
        }

    private:
        friend class LinkedList<T>;

        const_iterator(const LinkedList<T>* list, const Node* node) :
            list(list), node(node){ }

        const Node* node;
        const LinkedList<T>* list;
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

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    num_entries = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    head = NULL;
    tail = NULL;
    num_entries = 0;

    for(auto it = other.begin(); it != end(); ++it)
    {
        push_back(*it);
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    LinkedList<T> temp(other);
    std::swap(temp);
    return *this;
}

template<class T>
bool LinkedList<T>::empty() const
{
    return !num_entries;
}

template<class T>
size_t LinkedList<T>::size() const
{
    return num_entries;
}

template<class T>
T& LinkedList<T>::operator[](size_t index)
{
    return find(index)->value;
}

template<class T>
const T& LinkedList<T>::operator[](size_t index) const
{
   T& value = operator[](index);
   return value;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    return iterator(this, head);
}

template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::cbegin() const
{
    return const_iterator(this, head);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    return iterator(this, NULL);
}

template<class T>
typename LinkedList<T>::const_iterator LinkedList<T>::cend() const
{
    return const_iterator(this, NULL);
}

template<class T>
void LinkedList<T>::push_front(const T& value)
{
    head = new Node{value, NULL, head};

    // Update next node
    if(head->next) 
        head->next->previous = head;

    // Update tail
    if(tail == NULL)
        tail = head;

    num_entries++;
}

template<class T>
void LinkedList<T>::push_back(const T& value)
{
    tail = new Node{value, tail, NULL};

    // Update previous node
    if(tail->previous)
        tail->previous->next = tail;

    // Update head
    if(head == NULL)
        head = tail;

    num_entries++;
}

template<class T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    // Insert at head
    if(index == 0)
        push_front(value);

    // Insert at tail
    else if(index == num_entries)
        push_back(value);

    // Insert in middle
    else
    {
        Node* prev = find(index - 1);
        Node* next = prev->next;

        Node* insert = new Node{value, prev, next};

        insert->next->previous = insert;
        insert->previous->next = insert;

        num_entries++; 
    }   
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::insert(iterator pos, const T& value)
{
    if(pos.list != this)
        throw std::invalid_argument("Iterator does no match list");
    
    // Insert at head
    else if(pos.node == head)
    {
        push_front(value);
        return begin();
    }
        
    // Insert at tail
    else if(pos.node == NULL)
    {
        push_back(value);
        return iterator(this, tail);
    }
        
    // Insert in middle
    else
    {
        Node* next = pos.node;
        Node* prev = next->previous;

        Node* insert = new Node{value, prev, next};

        insert->next->previous = insert;
        insert->previous->next = insert;

        num_entries++;
        return iterator(this, insert);
    }
}

template<class T>
void LinkedList<T>::pop_front()
{
    if(!num_entries)
        throw std::out_of_range("Cannot pop_front() on an empty list");

    Node* temp = head;
    head = head->next;

    if(head)
        head->previous = NULL;
    else
        tail = NULL;

    delete temp;
    num_entries--;  
}

template<class T>
void LinkedList<T>::pop_back()
{
    if(!num_entries)
        throw std::out_of_range("Cannot pop_back() on an empty list");

    Node* temp = tail;
    tail = tail->previous;

    if(tail)
        tail->next = NULL;
    else
        head = NULL;

    delete temp;
    num_entries--;
}

template<class T>
void LinkedList<T>::remove(size_t index)
{
    // Remove from front
    if(index == 0)
        pop_front();

    else if(index == num_entries - 1)
        pop_back();
    
    else
    {
        Node* re = find(index);

        re->next->previous = re->previous;
        re->previous->next = re->next;

        delete re;
        num_entries--;   
    }
}


template<class T>
typename LinkedList<T>::iterator LinkedList<T>::remove(iterator pos)
{
    if(pos.list != this)
        throw std::invalid_argument("Iterator does no match list");

    if(empty())
        throw std::invalid_argument("Cannot remove item from empty list");

    if(pos == end())
        throw std::invalid_argument("Iterator equal to end()");

    iterator ret(this, pos.node->next);

    // Remove from head
    if(pos == begin()) 
        pop_front();

    // Remove from tail
    else if(pos.node == tail)
        pop_back();

    // Remove from middle
    else
    {
        Node* erase = pos.node;

        erase->next->previous = erase->previous;
        erase->previous->next = erase->next;

        delete erase;
        num_entries--;
    }

    return ret;
}

template<class T>
void LinkedList<T>::clear()
{
    Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    num_entries = 0;
}

template<class T>
typename LinkedList<T>::Node* LinkedList<T>::find(size_t index) const
{
    // Check bounds
    if(index < 0 || index >= num_entries)
    {
        throw std::out_of_range("Index must be in range [0,size())");
    }

    Node* n = head;
    for(size_t i = 0; i != index; i++)
        n = n->next;

    return n;
}

#endif