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

#include <iostream> // std::cout, std::endl
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
    explicit SinglyLinkedListNode(
        const T& data, 
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
    explicit DoublyLinkedListNode(
        const T& data, 
        DoublyLinkedListNode<T>* prev = NULL,  
        DoublyLinkedListNode<T>* next = NULL) : data(data), prev(prev), next(next)
    {
    
    }

    T data;
    DoublyLinkedListNode<T>* prev;
    DoublyLinkedListNode<T>* next;
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

template<class T>
void print_list(SinglyLinkedListNode<T>* head)
{
    std::cout << "[";

    while(head)
    {
        std::cout << head->data;
        head = head->next;

        if(head)
            std::cout << ",";
    }

    std::cout << "]" << std::endl;
}

#endif