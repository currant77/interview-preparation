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

/* Problem 2.5: " Sum Lists: (a) You have two numbers represented by a linked list, 
where each node contains a single digit. The digits are stored in _reverse_ order,
such that the 1's digit is at the head of the list. Write a functiopn that adds
the two numbers and returns the sum as a linked list. (b) Suppose the digits are
stored in forward order? 

EXAMPLE:
(a) [7,1,6] + [5,9,2] -> [2,1,9]
(b) [6,1,7] + [2,9,5] -> [9,1,2]

*/

/* Approach: 
(a) Use recursion. Function should combine the values from the two
list and return a corresponding node.
(b) Use recursion. Return overflow from next node via reference 
*/

#include <cassert>      // assert
#include <iostream>     // std::cout, std::endl;
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

Node<int>* sum_lists_a(Node<int>* head1, Node<int>* head2, int overflow)
{
    int sum = overflow + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
    int underflow = sum % 10;
    overflow = sum / 10;

    Node<int>* next = NULL;

    if((head1 && head1->next) || (head2 && head2->next) || overflow > 0)
    {
        next = sum_lists_a(
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
Node<int>* sum_lists_a(Node<int>* head1, Node<int>* head2)
{ 
    return sum_lists_a(head1, head2, 0);
}

Node<int>* sum_lists_b(Node<int>* head1, Node<int>* head2, int& overflow)
{
    // Empty head cases
    if(!head1 && !head2)
    {
        return NULL;
    }

    int sum;
    Node<int>* next;
    
    if(!head1)
    {
        next = sum_lists_b(head1, head2->next, overflow);
        sum = overflow + (head2 ? head2->data : 0);
    }

    else if(!head2)
    {
        next = sum_lists_b(head1->next, head2, overflow);
        sum = overflow + (head1 ? head1->data : 0);
    }

    // Non-empty head cases
    else if(head1->next && !head2->next)
    {
        next = sum_lists_b(head1->next, head2, overflow);
        sum = overflow + (head1 ? head1->data : 0);
    }

    else if(!head1->next && head2->next)
    {
        next = sum_lists_b(head1, head2->next, overflow);
        sum = overflow + (head2 ? head2->data : 0);    
    }

    else
    {
        next = sum_lists_b(head1->next, head2->next, overflow);
        sum = overflow + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);  
    }

    overflow = sum / 10;
    return new Node<int>(sum % 10, next);
}

Node<int>* sum_lists_b(Node<int>* head1, Node<int>* head2)
{
    int overflow = 0;
    Node<int>* list = sum_lists_b(head1, head2, overflow);

    if(overflow > 0)
    {
        list = new Node<int>(overflow, list);
    }

    return list;
}

int main()
{
    // (a)

    std::cout << std::endl << "Beginning tests for (a)..." << std::endl; 

    Node<int>* n0 = NULL;
    Node<int>* n5 = new Node<int>(5);
    Node<int>* n29 = new Node<int>(9, new Node<int>(2));
    Node<int>* n617 = new Node<int>(7, new Node<int>(1, new Node<int>(6)));
    Node<int>* n295 = new Node<int>(5, new Node<int>(9, new Node<int>(2)));

    Node<int>* res;
    res = sum_lists_a(n0, n0);                  // [] + [] = [0]    * Returns zero list
    assert(compare_list<int>(res, {0}));        // 0  + 0  = 0             
    delete res;

    res = sum_lists_a(n0, n29);                 // [] + [9,2] = [9,2]
    assert(compare_list<int>(res, {9,2}));      // 0  + 29    = 29    
    delete res;

    res = sum_lists_a(n5, n29);                 // [5] + [9,2] = [4,3]
    assert(compare_list<int>(res, {4,3}));      // 5   + 29    = 34
    delete res;

    res = sum_lists_a(n5, n617);                // [5] + [7,1,6] = [2,2,6]
    assert(compare_list<int>(res, {2,2,6}));    // 5   + 617     = 622
    delete res;

    res = sum_lists_a(n617, n295);              // [7,1,6] + [5,9,2] = 
    assert(compare_list<int>(res, {2,1,9}));    // 617     + 295     = 912
    delete res;

    res = sum_lists_a(n617, n617);              // [7,1,6] + [7,1,6] = [4,3,2,1]
    assert(compare_list<int>(res, {4,3,2,1}));  // 617     + 617     = 1234
    delete res;

    std::cout << "All tests for (a) passed!" << std::endl;

    // (b)

    std::cout << std::endl << "Beginning tests for (b)..." << std::endl; 

    n0 = NULL;
    n5 = new Node<int>(5);
    n29 = new Node<int>(9, new Node<int>(2));
    n617 = new Node<int>(7, new Node<int>(1, new Node<int>(6)));
    n295 = new Node<int>(5, new Node<int>(9, new Node<int>(2)));

    res = sum_lists_b(n0, n0);                  // [] + [] = []
    assert(!res);                               // 0  + 0  = 0      * Returns NULL list           
    delete res;

    res = sum_lists_b(n0, n29);                 // [] + [9,2] = [9,2]
    assert(compare_list<int>(res, {9,2}));      // 0  + 92    = 92    
    delete res;

    res = sum_lists_b(n5, n29);                 // [5] + [9,2] = [9,7]
    assert(compare_list<int>(res, {9,7}));      // 5   + 92    = 97
    delete res;

    res = sum_lists_b(n5, n617);                // [5] + [7,1,6] = [7,2,1]
    assert(compare_list<int>(res, {7,2,1}));    // 5   + 716     = 721
    delete res;

    res = sum_lists_b(n617, n295);              // [7,1,6] + [5,9,2] = [1,3,0,8]
    assert(compare_list<int>(res, {1,3,0,8}));  // 716     + 592     = 1308
    delete res;

    res = sum_lists_b(n617, n617);              // [7,1,6] + [7,1,6] = [1,4,3,2]
    assert(compare_list<int>(res, {1,4,3,2}));  // 716     + 716     = 1432
    delete res;

    delete n0;
    delete n5;
    delete n29;
    delete n617;
    delete n295;

    std::cout << "All tests for (b) passed!" << std::endl;
    
    exit(0); 
    
}