/**
 * @file cci_2-3.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.3 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-02
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.3: "Delete Middle Node: Implement an algorithm to delete 
a node in the middle (i.e. any node but the first and last node, not 
necessarily the exact middle) of a sinly linked list, given only 
access to that node."*/

/* Approach: Copy the next node's data to that node, update points */

#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, compare_list<T>()

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
void remove_middle_node(Node<T>* node)
{
    Node<T>* ptr = node->next;   
    
    node->data = node->next->data;  
    node->next = node->next->next;

    delete ptr;
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    Node<int>* head = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    remove_middle_node(head->next);                            // [1,2,3] -> [1,3]
    assert(compare_list<int>(head, {1,3}));

    head->next->next = new Node<int>(5, new Node<int>(7));
    remove_middle_node(head->next->next);                      // [1,3,5,7] -> [1,3,7]
    assert(compare_list<int>(head, {1,3,7}));

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}