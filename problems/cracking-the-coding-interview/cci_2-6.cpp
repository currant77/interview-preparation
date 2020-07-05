/**
 * @file cci_2-6.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.6 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-03
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem  2.6: "Palindrome: Implement a function to check if a 
linked list is a palindrome" */

/* Approach: 

(a) Reverse list and compare 

(b) Using a stack and a fast/slow runner (fast runner cover two nodes 
for each one covered by the slow runner). Push nodes onto the stack,
and then compare the second half. Need to be careful to account for list
of odd length (can maintain length counter)

(c) Using recursion. Function will return bool and reference to tail
*/

#include <stack>                            // std::stack
#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include <functional>                       // std::function
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

/**
 * @brief Returns linked list head that is a reversed
 * copy of the list that starts at \p head. Also returns
 * the length of the list by reference in \p length
 */
template<class T>
Node<T>* clone_and_reverse(Node<T>* head, int& length)
{
    length = 0;
    Node<T>* reversed = NULL;

    while(head)
    {
        reversed = new Node<T>(head->data, reversed);
        head = head->next;
        ++length;
    }

    return reversed;
}

template<class T>
bool is_palindrome_a(Node<T>* head)
{
    // Create reversed copy
    int length = 0;
    Node<T>* reversed = clone_and_reverse<T>(head, length);

    // Compare
    for(size_t i = 0; i < length / 2; ++i)
    {
        if(head->data != reversed->data)
            return false;

        head = head->next;
        reversed = reversed->next;
    }

    return true;
}

template<class T>
bool is_palindrome_b(Node<T>* head)
{
    Node<T>* slow = head;
    Node<T>* fast = head;
    std::stack<Node<T>*> stack;

    while(fast && fast->next)
    {
        stack.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Skip over middle in odd-length list
    if(fast)
        slow = slow->next;

    // Compare second half
    while(slow)
    {
        if(slow->data != stack.top()->data)
            return false;

        stack.pop();
        slow = slow->next;  
    }

    return true;
}

template<class T>
bool is_palindrome(Node<T>* head, Node<T>*& tail, size_t length)
{
    // Base case: empty list
    if(length == 0)
    {
        return true;
    }
    
    // Base case: middle of odd-length list
    if(length == 1)
    {
        tail = head->next;
        return true;
    }

    // Base case: middle of even-length list
    else if(length == 2)
    {
        tail = head->next;
        bool res = (head->data == tail->data);
        tail = tail->next;
        return res;
    }

    else
    {
        bool res = is_palindrome(head->next, tail, length - 2);
        res = res && (head->data == tail->data);
        tail = tail->next;

        return res ;
    }  
}

template<class T>
bool is_palindrome_c(Node<T>* head)
{
    // Find list length
    size_t length = 0;
    Node<T>* ptr = head;
    while(ptr)
    {
        ptr = ptr->next;
        ++length;
    }

    Node<T>* tail = NULL;
    return is_palindrome(head, tail, length);
}

void tst(std::function<bool(Node<int>*)> fn)
{
    Node<int>* empty = NULL;            
    assert(fn(empty));               // [] -> true

    Node<int>* one = new Node<int>(5);          
    assert(fn(one));                 // [5] -> true
    delete one; 

    Node<int>* two_true = 
        new Node<int>(1, 
        new Node<int>(1));
    assert(fn(two_true));            // [1,1] -> true
    delete two_true; 
    
    Node<int>* two_false = 
        new Node<int>(1, 
        new Node<int>(2));
    assert(!fn(two_false));          // [1,2] -> false
    delete two_false;

     Node<int>* three_true = 
        new Node<int>(1, 
        new Node<int>(2,
        new Node<int>(1)));
    assert(fn(three_true));          // [1,2,1] -> true
    delete three_true; 
    
    Node<int>* three_false = 
        new Node<int>(1, 
        new Node<int>(2,
        new Node<int>(3)));
    assert(!fn(three_false));        // [1,2,3] -> false
    delete three_false; 

    Node<int>* long_true =
        new Node<int>(1,
        new Node<int>(2,
        new Node<int>(3,
        new Node<int>(4,
        new Node<int>(3,
        new Node<int>(2,
        new Node<int>(1)))))));
    assert(fn(long_true));          // [1,2,3,4,3,2,1] -> true
    delete long_true;
}

int main()
{
    // (a) Reverse and compare
    std::cout << std::endl << "Beginning tests for (a)..." << std::endl; 
    tst(*is_palindrome_a<int>);
    std::cout << "All tests for (a) passed!" << std::endl;

    // (b) Stack
    std::cout << std::endl << "Beginning tests for (b)..." << std::endl; 
    tst(*is_palindrome_b<int>);
    std::cout << "All tests for (b) passed!" << std::endl;

    // (b) Recursion
    std::cout << std::endl << "Beginning tests for (c)..." << std::endl; 
    tst(*is_palindrome_c<int>);
    std::cout << "All tests for (c) passed!" << std::endl;
    
    exit(0); 
}