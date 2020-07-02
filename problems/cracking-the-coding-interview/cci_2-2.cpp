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
void remove_kth_last(Node<T>* head, size_t k)
{

}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    Node<int>* head = NULL;
    remove_kth_last(head, 0);

    head = new Node<int>(5);        // Input:   [5]
    remove_kth_last(head, 1);       // Output:  []

    head =                          // Input: [5,6,7,8]
        new Node<int>(5, 
            new Node<int>(6, 
                new Node<int>(7, 
                    new Node<int>(8))));
    
    remove_kth_last(head, 4);       // Output: [6,7,8]
    remove_kth_last(head, 2);       // Output: [6,8]
    remove_kth_last(head, 2);       // Output: [8]
    remove_kth_last(head, 1);       // Output: []


    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}