/**
 * @file cci_2-8.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.8 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-04
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.8: "Loop Detection: Given a circular linked list, 
implement an algorithm that returns the node at the beginning of the 
loop." */

/* Approach: 

(a) Set (linear): use a set to store node addresses; return true if duplicates found

(b) Fast and slow runner: This approach requires quite an explanation, and is derived
from Cracking the Coding Interview (I wish I could say I derived it myself). Suppose we have
a fast runner (moves 2 nodes) and a slow runner (moves one node); suppose that the 
first node in the loop has index k and that the cycle has length c. When the slow 
runner enters the loop, the fast runner will be k nodes ahead: it will be k % c nodes
into the loop, meaning that it will be c - (k % c) loops "behind" the slow runner. At 
each further step around the loop, the fast runner will gain one step on the slow runner. 
They will thus collide c - (k % c) step into the loop, which is c - (c - (k % c)) = 
(k % c) nodes fom the start of the loop -- or simply k nodes from the start of the loop
(which may result in us circling the loop more than once). Then, if we keep one pointer at 
this collision point and start another from the head of the list, they will collide exactly
at the start of the loop! 

This is an incredibly elegant solution -- but it is quite a bit slower than a relatively 
simple set solution above and probably would rarely be implemented in practice as a result --
although it does have constant storage requirement, unlike the linear space needed for the set.
*/

#include <cassert>          // assert
#include <iostream>         // std::cout, std::endl;
#include <functional>       // std::function
#include <unordered_set>    // std::unordered_set

#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
Node<T>* contains_cycle_set(Node<T>* head)
{
    std::unordered_set<Node<T>*> set;

    while(head)
    {
        if(set.count(head))
            return head;

        else
            set.insert(head);

        head = head->next;
    }

    return NULL;
}

template<class T>
Node<T>* contains_cycle_runners(Node<T>* head)
{
    Node<T>* fast = head;
    Node<T>* slow = head;

    // Find collision point
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != slow)
        return NULL;

    // Find start of cycle
    fast = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

void tst(std::function<void(Node<int>*)> fn)
{
    Node<int>* head = NULL;
    assert(!contains_cycle_set(head));

    head = new Node<int>(5);
    assert(!contains_cycle_set(head));
    delete head;

    auto nine = new Node<int>(9);
    auto eight = new Node<int>(8, nine);
    auto seven = new Node<int>(7, eight);
    auto six = new Node<int>(6, seven);
    auto five = new Node<int>(5, six);
    auto four = new Node<int>(4, five);
    auto three = new Node<int>(3, four);
    auto two = new Node<int>(2, three);
    auto one = new Node<int>(1, two);

    // 9 -> 1
    nine->next = one;
    assert(contains_cycle_set<int>(one) == one);

    // 9 -> 2
    nine->next = two;
    assert(contains_cycle_set<int>(one) == two);

    // 9 -> 3
    nine->next = three;
    assert(contains_cycle_set<int>(one) == three);

    // 9 -> 4
    nine->next = four;
    assert(contains_cycle_set<int>(one) == four);

    // 9 -> 5
    nine->next = five;
    assert(contains_cycle_set<int>(one) == five);

    // 9 -> 6
    nine->next = six;
    assert(contains_cycle_set<int>(one) == six);

    // 9 -> 7
    nine->next = seven;
    assert(contains_cycle_set<int>(one) == seven);

    // 9 -> 8
    nine->next = eight;
    assert(contains_cycle_set<int>(one) == eight);

    // 9 -> 9
    nine->next = nine;
    assert(contains_cycle_set<int>(one) == nine);

    // 9 -> NULL
    nine->next = NULL;
    assert(!contains_cycle_set<int>(one));
}

int main()
{
    std::cout << std::endl << "Beginning tests for (a)..." << std::endl;

    tst(*contains_cycle_set<int>);

    std::cout << "All tests for (a) passed!" << std::endl;

    std::cout << std::endl << "Beginning tests for (b)..." << std::endl;

    tst(*contains_cycle_runners<int>);

    std::cout << "All tests for (b) passed!" << std::endl;
    
    exit(0); 
}