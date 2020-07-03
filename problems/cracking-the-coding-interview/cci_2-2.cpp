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

/* 
Problem 2.2: Remove Kth to Last: implement an algorithm to find the kth to 
last element of a singly linked list. 
*/

/* 
Approach (a): 
(1) Scan the list to find length
(2) Scan the list to find k-th last element and remove it 

Approach (b):
Recursive approach. Recursive function return the length of the remaining
elements, and removes the next node if appropriate. SImilar but slight 
differences to several solutions in Cracking the Coding Interview.
*/

#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include <functional>                       // std::function
#include "../../data-structures/Node.h"     // SinglyLinkedListNode

template<class T>
using Node = SinglyLinkedListNode<T>;

// Functions

/**
 * @brief Removes the kth to last element in head.
 * Throw std::out_of_range if k is less than one or
 * greater than the length of the list.
 */
template<class T>
void remove_kth_last_a(Node<T>*& head, size_t k)
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

/**
 * @brief Removes the kth to last element in head.
 * Throw std::out_of_range if k is less than one or
 * greater than the length of the list.
 */
template<class T>
void remove_kth_last_b(Node<T>*& head, size_t k)
{
    if(k < 1)
        throw std::out_of_range("k cannot be less than one");

    size_t length = b_recursive(head, k);

    if(k < length)
        throw std::out_of_range("k cannot be greater than list length");
}

/**
 * @brief Recursive helper. Returns
 * the position of head from the end of the 
 * original last (with element removed)
 */
template<class T>
size_t b_recursive(Node<T>*& head, size_t k)
{
    // Base case
    if(!head)
        return 0;

    // General case
    size_t next_index = b_recursive(head->next, k);

    if(next_index == k)
    {
        Node<T>* ptr = head;
        head = head->next;
        delete head;
    }

    return next_index + 1;
}

void tst(std::function<void(Node<int>*&, size_t)> fn)
{
    Node<int>* head = new Node<int>(5);        
    fn(head, 1);                            // [5] -> []
    assert(compare_list(head, {}));

    head =                         
        new Node<int>(5, 
            new Node<int>(6, 
                new Node<int>(7, 
                    new Node<int>(8))));

    try
    {
        fn(head, 5);                        
        assert(false);
    }
    catch(const std::out_of_range& e)
    {
        assert(true);
    }
    
    assert(compare_list(head, {5,6,7,8}));

    fn(head, 4);                            // [5,6,7,8] -> [6,7,8]
    assert(compare_list(head, {6,7,8}));

    fn(head, 2);                            // [6,7,8] -> [6,8]
    assert(compare_list(head, {6,8}));

    fn(head, 2);                            // [6,8] -> [8]
    assert(compare_list(head, {8}));

    fn(head, 1);                            // [8] -> []
    assert(compare_list(head, {}));

    try
    {
        head = NULL;
        fn(head, 0);                       
        assert(false);
    }
    catch(const std::exception& e)
    {
        assert(true);
    }

    assert(compare_list(head, {}));
}

int main()
{
    std::cout << std::endl << "Beginning tests for approach (a)..." << std::endl; 

    tst(*remove_kth_last_a<int>);

    std::cout << "All tests for approach (a) passed!" << std::endl;

    std::cout << std::endl << "Beginning tests for approach (b)..." << std::endl; 

    tst(*remove_kth_last_a<int>);

    std::cout << "All tests for approach (b) passed!" << std::endl << std::endl;
    
    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}