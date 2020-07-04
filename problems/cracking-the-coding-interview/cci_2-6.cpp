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

/* Approach: A palindrome is a word that is spelled the same forward
as backwards. Using a recursive approach. Function should return a 
reference to the last remaining node in the list (by reference) in
addition to a bool */

#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>
#include <functional>                       // std::function

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
void tst(std::function<bool(Node<T>*)> fn)
{
    Node<int>* empty = NULL;            
    assert(fn(empty));               // [] -> true

    Node<int>* one = new Node<int>(5);          
    assert(fn(one));                 // [5] -> true
    delete one; 

    Node<char>* two_true = 
        new Node<char>('a', 
        new Node<char>('a'));
    assert(fn(two_true));            // ['a','a'] -> true
    delete two_true; 
    
    Node<char>* two_false = 
        new Node<char>('a', 
        new Node<char>('b'));
    assert(fn(two_false));           // ['a','b'] -> false
    delete two_false;

     Node<char>* three_true = 
        new Node<char>('a', 
        new Node<char>('b',
        new Node<char>('a')));
    assert(fn(three_true));          // ['a','b','a'] -> true
    delete three_true; 
    
    Node<char>* three_false = 
        new Node<char>('a', 
        new Node<char>('b',
        new Node<char>('c')));
    assert(fn(three_false));         // ['a','b','c'] -> false
    delete three_false; 

    Node<std::string>* long_true =
        new Node<std::string>("r",
        new Node<std::string>("a",
        new Node<std::string>("c",
        new Node<std::string>("e",
        new Node<std::string>("c",
        new Node<std::string>("a",
        new Node<std::string>("r")))))));
    assert(fn(long_true));         // ['r','a','c','e','c','a','r'] -> true
    delete long_true;
}

int main()
{
    std::cout << "Beginning tests..." << std::endl; 

    

    std::cout << "All tests passed!" << std::endl;
    
    exit(0); 
}