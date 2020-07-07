/**
 * @file Deque.h
 * @author Taylor Curran
 * @brief Deque implemented using doubly-linked list
 * @version 0.1
 * @date 2020-07-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>    // std::invalid_argument
#include "Node.h"       // DoublyLinkedListNode

template<class T>
using Node = DoublyLinkedListNode<T>;

template<class T>
class Deque
{
    public:
        
        Deque();
        ~Deque();

        bool empty() const;
        size_t size() const;

        /**
         * @brief Returns a reference to the front 
         * value in the deque
         * @throw std::invalid_argument if the deque is empty
         */
        T& front();

        /**
         * @brief Returns a reference to the front 
         * value in the deque
         * @throw std::invalid_argument if the deque is empty
         */
        const T& front() const;

        /**
         * @brief Returns a reference to the back 
         * value in the deque
         * @throw std::invalid_argument if the deque is empty
         */
        T& back();

        /**
         * @brief Returns a reference to the back 
         * value in the deque
         * @throw std::invalid_argument if the deque is empty
         */
        const T& back() const;

        /**
         * @brief Inserts \p value at the front
         */
        void push_front(const T& value);

        /**
         * @brief Inserts \p value at the front
         */
        void push_back(const T& value);

        /**
         * @brief Removes the front value
         * @throw std::invalid_argument if deque is empty
         */
        void pop_front();

        /**
         * @brief Removes the front value
         * @throw std::invalid_argument if deque is empty
         */
        void pop_back();

        /**
         * @brief Clears all values
         * 
         */
        void clear();

    private:
        size_t num_entries;
        Node<T>* head;
        Node<T>* tail;
};

template<class T>
Deque<T>::Deque()
{
    num_entries = 0;
    head = NULL;
    tail = NULL;
}

template<class T>
Deque<T>::~Deque()
{
    clear();
}

template<class T>
bool Deque<T>:: empty() const
{
    return !num_entries;
}

template<class T>
size_t Deque<T>::size() const
{
    return num_entries;
}

template<class T>
T& Deque<T>::front()
{
    if(!num_entries)
        throw std::invalid_argument("Cannot access empty deque");

    return head->data;
}

template<class T>
const T& Deque<T>::front() const
{
    return front();
}

template<class T>
T& Deque<T>::back()
{
    if(!num_entries)
        throw std::invalid_argument("Cannot access empty deque");

    return tail->data;  
}

template<class T>
const T& Deque<T>::back() const
{
    return back();
}

template<class T>
void Deque<T>::push_front(const T& value)
{
    head = new Node<T>(value, NULL, head);
    
    if(head->next)
        head->next->prev = head;

    else
        tail = head;

    ++num_entries;
}

template<class T>
void Deque<T>::push_back(const T& value)
{
    tail = new Node<T>(value, tail, NULL);
    
    if(tail->prev)
        tail->prev->next = tail;

    else
        tail = head;

    ++num_entries;
}

template<class T>
void Deque<T>::pop_front()
{
    if(!head)
        throw std::invalid_argument("Cannot call pop_front() on empty deque");
    
    Node<T>* ptr = head;
    head = head->next;

    if(head)
        head->prev = NULL;

    else
        tail = head;
    
    --num_entries;
    delete ptr;
}

template<class T>
void Deque<T>::pop_back()
{
    if(!tail)
        throw std::invalid_argument("Cannot call pop_back() on empty deque");

    Node<T>* ptr = tail;
    tail = tail->prev;

    if(tail)
        tail->next = NULL;

    else
        head = tail;

    --num_entries;
    delete ptr;
}

template<class T>
void Deque<T>::clear()
{
    Node<T>* ptr;

    while(head)
    {
        ptr = head;
        head = head->next;
        delete ptr;
    }

    num_entries = 0;
    head = NULL;
    tail = NULL;
}

#endif