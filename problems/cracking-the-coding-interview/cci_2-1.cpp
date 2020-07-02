/**
 * @file cci_2-1.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.1 from Cracking the Coding Interview
 * @version 0.1
 * @date 2020-07-01
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Problem 2.1: "Remove Dups:
(a) Write code to remove duplicates from an unsorted linked list.
(b) How would you solve the problem if a temporary buffer was not allowed?
 */

/* Approach:
(a) Iterate through list, storing a set of values. Remove any value that 
is already in the set.
(b) Much slower. Two pointers. First one stays static as second one searches
rest of the list and removes duplicates. Runtime O(n^2).  */

#include <cassert>          // assert
#include <iostream>         // std::cout, std::endl
#include <unordered_set>    // std::unordered_set

// Classes and structs

template<class T>
struct Node
{
    T data;
    Node<T>* next;

    explicit Node(const T& data, Node<T>* next = NULL) : 
        data(data), next(next) 
    { 

    }  
    
    ~Node()
    { 
        delete next; 
    }
};

// Functions

template<class T>
void remove_dups_a(Node<T>* head)
{
    std::unordered_set<T> set;

    Node<T>* temp;
    while(head && head->next)
    {
        // Insert head data
        set.insert(head->data);

        // head->next is duplicate
        if(set.count(head->next->data) > 0)
        {
            temp = head->next;
            head->next = head->next->next;
            temp->next = NULL;
            delete temp;
        }

        else
        {
            head = head->next;
        }  
    }


}

template<class T>
void remove_dups_b(Node<T>* head)
{
    // TODO
}

template<class T>
void print_list(Node<T>* head)
{
    std::cout << "[";

    while(head && head->next)
    {
        std::cout << head->data << ",";
        head = head->next;
    }

    if(head)
    {
        std::cout << head->data;
    }

    std::cout << "]" << std::endl;
}

// Tests

int main()
{
    std::cout << std::endl << "Beginning tests for (a)..." << std::endl; 

    // Tests (a)

    Node<int>* head = NULL;       
    remove_dups_a(head);            // Input: []
    print_list(head);               // Output: []  

    head = new Node<int>(5);
    remove_dups_a(head);            // Input: [5]
    print_list(head);               // Output: [5]

    auto six = new Node<int>(6);
    head->next = six;
    remove_dups_a(head);            // Input: [5,6]
    print_list(head);               // Output: [5,6]

    auto five = new Node<int>(5);
    six->next = five;
    remove_dups_a(head);            // Input: [5,6,5]
    print_list(head);               // Output: [5,6]

    six->next = new Node<int>(6);
    remove_dups_a(head);            // Input: [5,6,6]
    print_list(head);               // Output: [5,6]

    auto sevenA = new Node<int>(7);
    auto eight = new Node<int>(8);
    auto nineA = new Node<int>(9);
    auto sevenB = new Node<int>(7);
    auto nineB = new Node<int>(9);

    six->next = sevenA;
    sevenA->next = eight;
    eight->next = nineA;
    nineA->next = nineB;
    nineB->next = sevenB;
    remove_dups_a(head);            // Input: [5,6,7,8,9,9,7]
    print_list(head);               // Output: [5,6,7,8,9]

    delete head;

    std::cout << "All tests for (a) passed!" << std::endl << std::endl;

    // Tests (b)

    std::cout << "Beginning tests for (b)..." << std::endl; 

    head = NULL;       
    remove_dups_b(head);            // Input: []
    print_list(head);               // Output: []  

    head = new Node<int>(5);
    remove_dups_b(head);            // Input: [5]
    print_list(head);               // Output: [5]

    six = new Node<int>(6);
    head->next = six;
    remove_dups_b(head);            // Input: [5,6]
    print_list(head);               // Output: [5,6]

    five = new Node<int>(5);
    six->next = five;
    remove_dups_b(head);            // Input: [5,6,5]
    print_list(head);               // Output: [5,6]

    six->next = new Node<int>(6);
    remove_dups_b(head);            // Input: [5,6,6]
    print_list(head);               // Output: [5,6]

    sevenA = new Node<int>(7);
    eight = new Node<int>(8);
    nineA = new Node<int>(9);
    sevenB = new Node<int>(7);
    nineB = new Node<int>(9);
    six->next = sevenA;
    sevenA->next = eight;
    eight->next = nineA;
    nineA->next = nineB;
    nineB->next = sevenB;
    remove_dups_b(head);            // Input: [5,6,7,8,9,9,7]
    print_list(head);               // Output: [5,6,7,8,9]

    delete head;

    std::cout << "All tests for (b) passed!" << std::endl;
    exit(0); 
}