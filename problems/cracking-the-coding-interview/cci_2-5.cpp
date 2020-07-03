/**
 * @file cci_2-5.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.5 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-02
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.5: " Sum Lists; You have two numbers represented by a linked list, 
where each node contains a single digit. The digits are stored in _reverse_ order,
such that the 1's digit is at the head of the list. Write a functiopn that adds
the two numbers and returns the sum as a linked list" */

/* Approach: Use recursion. Function should combine the values from the two
list and return a corresponding node. */

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

Node<int>* sum_lists(Node<int>* head1, Node<int>* head2, int overflow)
{
    int sum = overflow + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
    int underflow = sum % 10;
    overflow = sum / 10;

    Node<int>* next = NULL;

    if((head1 && head1->next) || (head2 && head2->next) || overflow > 0)
    {
        next = sum_lists(
            (head1 ? head1->next : head1), 
            (head2 ? head2->next : head2), 
            overflow);
    }

    return new Node<int>(underflow, next);
}

/**
 * @brief Returns a pointer to a list representing
 * the sum of the values from the two linked lists
 * (treats null list as zero)
 */
Node<int>* sum_lists(Node<int>* head1, Node<int>* head2)
{ 
    return sum_lists(head1, head2, 0);
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    Node<int>* n0 = NULL;
    Node<int>* n5 = new Node<int>(5);
    Node<int>* n29 = new Node<int>(9, new Node<int>(2));
    Node<int>* n617 = new Node<int>(7, new Node<int>(1, new Node<int>(6)));
    Node<int>* n295 = new Node<int>(5, new Node<int>(9, new Node<int>(2)));

    Node<int>* res;
    res = sum_lists(n0, n0);                    // [] + [] = []
    assert(compare_list<int>(res, {0}));        // 0  + 0  = 0           
    delete res;

    res = sum_lists(n0, n29);                   // [] + [9,2] = [9,2]
    assert(compare_list<int>(res, {9,2}));      // 0  + 29    = 29    
    delete res;

    res = sum_lists(n5, n29);                   // [5] + [9,2] = [4,3]
    assert(compare_list<int>(res, {4,3}));      // 5   + 29    = 34
    delete res;

    res = sum_lists(n5, n617);                  // [5] + [7,1,6] = [2,2,6]
    assert(compare_list<int>(res, {2,2,6}));    // 5   + 617     = 622
    delete res;

    res = sum_lists(n617, n295);                // [7,1,6] + [5,9,2] = 
    assert(compare_list<int>(res, {2,1,9}));    // 617     + 295     = 912
    delete res;

    res = sum_lists(n617, n617);                // [7,1,6] + [7,1,6] = [4,3,2,1]
    assert(compare_list<int>(res, {4,3,2,1}));  // 617     + 617     = 1234
    delete res;

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}