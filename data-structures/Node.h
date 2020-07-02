/**
 * @file Node.h
 * @author Taylor Curran
 * @brief Simple node structs for singly-linked list, doubly-linked list.
 * @version 0.1
 * @date 2020-07-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef NODE_H
#define NODE_H

/**
 * @brief A singly-linked list node. No ownership of other nodes in
 * the list.
 * 
 * @tparam T 
 */
template<class T>
struct SinglyLinkedListNode
{
    explicit SinglyLinkedListNode(const T& data, 
    SinglyLinkedListNode<T>* next = NULL) : data(data), next(next)
    {
        
    }

    T data;
    SinglyLinkedListNode<T>* next;
};

/**
 * @brief A doubly-linked list node. No ownership of other nodes
 * in the list.
 * 
 * @tparam T 
 */
template<class T>
struct DoublyLinkedListNode
{
    explicit DoublyLinkedListNode(const T& data, 
        DoublyLinkedListNode<T>* prev = NULL,  
        DoublyLinkedListNode<T>* next = NULL) : 
            data(data), prev(prev), next(next)
    {
        
    }

    T data;
    DoublyLinkedListNode<T>* prev;
    DoublyLinkedListNode<T>* next;
};

#endif