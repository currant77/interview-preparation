/**
 * @file cci_2-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.2 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-02
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.2: Remove Kth to Last: implement an algorithm to find the kth to last element of a singly linked list. */

/* Approach: <text> */

#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include "../../data-structures/Node.h"     // DoublyLinkedList

template<class T>
using Node = SinglyLinkedListNode<T>;

// Functions

/**
 * @brief Removes the kth to last element in head.
 * Throw std::out_of_range if k is less than one or
 * greater than the length of the list.
 */
template<class T>
void remove_kth_last(Node<T>*& head, size_t k)
{
    if(k < 1)
        throw std::out_of_range("k cannot be less than one");

    // Determine length
    size_t length = 0;
    Node<T>* it = head;

    while(it)
    {
        ++length;
        it = it->next;
    }

    if(k > length)
        throw std::out_of_range("k cannot be larger than length of list");

    Node<T>* ptr;

    // Remove head
    if(k == length)
    {
        ptr = head;
        head = head->next;
        delete ptr;
    }

    // Remove another element
    else
    {
        it = head;
        while(k < length - 1)
        {
            it = it->next;
            --length;
        }

        ptr = it->next;
        it->next = it->next->next;
    }
    
    delete ptr;
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    Node<int>* head = new Node<int>(5);        
    remove_kth_last(head, 1);               // [5] -> []
    assert(compare_list(head, {}));

    head =                         
        new Node<int>(5, 
            new Node<int>(6, 
                new Node<int>(7, 
                    new Node<int>(8))));

    try
    {
        remove_kth_last(head, 5);
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }
    
    assert(compare_list(head, {5,6,7,8}));

    remove_kth_last(head, 4);               // [5,6,7,8] -> [6,7,8]
    assert(compare_list(head, {6,7,8}));

    remove_kth_last(head, 2);               // [6,7,8] -> [6,8]
    assert(compare_list(head, {6,8}));

    remove_kth_last(head, 2);               // [6,8] -> [8]
    assert(compare_list(head, {8}));

    remove_kth_last(head, 1);               // [8] -> []
    assert(compare_list(head, {}));

    try
    {
        head = NULL;
        remove_kth_last(head, 0);
        assert(false);
    }
    catch(const std::exception& e)
    {
        assert(true);
    }

    assert(compare_list(head, {}));
    
    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}