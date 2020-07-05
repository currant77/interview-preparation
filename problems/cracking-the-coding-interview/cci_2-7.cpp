/**
 * @file cci_2-7.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.7 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-04
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.7: "Intersection: given two (singly) linked lists, determine
if the two lists intersect." (By reference; that is, if the two lists share
a node)" */

/* Approach: 
(a) Use a set to store addresses and simply search for them 
(b) Use length. Traverse both lists to determine length. Compare
last node. If it is equal, set to pointers until they find intersection,
spacing them by length difference*/

#include <cassert>          // assert
#include <iostream>         // std::cout, std::endl;
#include <exception>        // std::invalid_argument
#include <unordered_set>    // std::unordered_set
#include <functional>       // std::function

#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
Node<T>* intersection_a(Node<T>* first, Node<T>* second)
{
    std::unordered_set<Node<T>*> addresses;

    while(first)
    {
        if(addresses.count(first))
            throw std::invalid_argument("First list contains a loop");
        
        addresses.insert(first);
        first = first->next;
    }

    while(second)
    {
        if(addresses.count(second))
            return second;

        second = second->next;
    }

    return NULL;
}

template<class T>
Node<T>* intersection_b(Node<T>* first, Node<T>* second)
{
    // Empty lists
    if(!first || !second) return NULL;

    // Find list length and last node
    size_t first_length = 1;
    Node<T>* first_ptr = first;

    while(first_ptr->next)
    {
        first_ptr = first_ptr->next;
        ++first_length;
    }

    size_t second_length = 1;
    Node<T>* second_ptr = second;

    while(second_ptr->next)
    {
        second_ptr = second_ptr->next;
        ++second_length;
    }
    
    // No intersection if ends do not match
    if(first_ptr != second_ptr) return NULL;

    // Advance pointers to starts
    first_ptr = first;
    second_ptr = second;

    while(first_length > second_length)
    {
        first_ptr = first_ptr->next;
        first_length--;
    }

    while(first_length < second_length)
    {
        second_ptr = second_ptr->next;
        second_length--;
    }

    // Find intersection
    while(first_ptr != second_ptr)
    {
        first_ptr = first_ptr->next;
        second_ptr = second_ptr->next;
    }

    return first_ptr;
}

void tst(std::function<Node<int>*(Node<int>*, Node<int>*)> fn)
{
    // Empty lists (no intersection)
    Node<int>* first = NULL;
    Node<int>* second = NULL;
    assert(!fn(first, second));

    // Intersection at head
    first = new Node<int>(1);
    second = first;
    assert(fn(first, second) == first);
    assert(fn(first, second) == second);

    // No intersection 
    second = new Node<int>(1);
    assert(!fn(first, second));

    // Intersection at second node
    first->next = new Node<int>(2);
    second->next = first->next;
    assert(fn(first, second) == first->next);
    assert(fn(first, second) == second->next);

    // No intersection 
    second->next = new Node<int>(2);
    assert(!fn(first, second));

    // First turns into second
    first->next->next = second;
    assert(fn(first, second) == second);
    assert(fn(first, second) == first->next->next);

    // Second turns into first
    first->next->next = NULL;
    second->next->next = first;
    assert(fn(first, second) == first);
    assert(fn(first, second) == second->next->next);

    // Long comparison
    Node<int>* ptr;
    while(second)
    {
        ptr = second->next;
        delete second;
        second = ptr;
    }

    ptr = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    first = new Node<int>(1, ptr);
    second = new Node<int>(3, new Node<int>(5, new Node<int>(7, ptr)));
    assert(fn(first, second) == ptr);
    assert(fn(first, second) == ptr);
}

int main()
{
    std::cout << std::endl << "Beginning tests for (a)..." << std::endl;

    tst(*intersection_a<int>); 

    std::cout << "All tests for (a) passed!" << std::endl;

    std::cout << std::endl << "Beginning tests for (b)..." << std::endl;

    tst(*intersection_b<int>); 

    std::cout << "All tests for (b) passed!" << std::endl;

    exit(0); 
}