/**
 * @file reverse_linked_list.cpp
 * @author Taylor Curran
 * @brief Algorithm for reversing a singly linked lsit
 * @version 0.1
 * @date 2020-07-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cassert>
#include <iostream>
#include "../data-structures/Node.h"

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
Node<T>* reverse_list(Node<T>* head)
{
    Node<T>* next;
    Node<T>* front = NULL;

    while(head)
    {
        next = head->next;
        head->next = front;
        front = head;
        head = next;
    }
    
    return front;
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl;

    Node<int>* head = NULL;
    head = reverse_list(head);
    assert(compare_list<int>(head, {}));

    head = new Node<int>(5);
    head = reverse_list(head);
    assert(compare_list<int>(head, {5}));
    delete head;

    head = 
        new Node<int>(5,
        new Node<int>(6,
        new Node<int>(7,
        new Node<int>(8,
        new Node<int>(9)))));
    head = reverse_list(head);
    assert(compare_list<int>(head, {9,8,7,6,5}));
    delete head;

    std::cout << "All tests passed!" << std::endl;
}