/**
 * @file Node.h
 * @author Taylor Curran
 * @brief Simple node structs for singly-linked list, doubly-linked list.
 * Also includes various helper functions
 * @version 0.1
 * @date 2020-07-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef NODE_H
#define NODE_H

#include <vector>   // std::vector

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
struct DoublyLinkedListNode : public SinglyLinkedListNode<T>
{
    explicit DoublyLinkedListNode(
        const T& data, 
        DoublyLinkedListNode<T>* prev = NULL,  
        DoublyLinkedListNode<T>* next = NULL) : 
            prev(prev), SinglyLinkedListNode<T>(data,next)
    {
        
    }

    DoublyLinkedListNode<T>* prev;
};

/**
 * @brief Compares list values to expected values using equality comparison
 */
template<class T>
bool compare_list(SinglyLinkedListNode<T>* head, std::vector<T> expected)
{
    auto it = expected.begin();
    while(head && it != expected.end())
    {
        if(head->data != *it)
            return false;

        head = head->next;
        ++it;
    }

    if(head != NULL || it != expected.end())
        return false;

    else
        return true;
}

#endif