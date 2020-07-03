/**
 * @file cci_2-4.cpp
 * @author Taylor Curran
 * @brief Solution to problem 2.4 from Cracking the Coding Interview
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
Problem 2.4: "Partition: write code to partition a linked list 
around a value x, such that all nodes less than x come before all 
node greater than or equal to x. If x is contained within the list,
the values of x only need to be after the element less than x (see
example below). The partition element x can appear anywhere in the
"right partittion"; it does not need to appear between the left and
right partitions."

EXAMPLE
[3,5,8,5,10,2,1] -> Partition = 5 -> [3,1,2 | 10,5,5,8] 

*/

/* Approach: Maintain two pointers. First one points to head, 
second one moves through list. Whenever it encounters a value less 
than the partition, it moves it to the front of the list 

Note: as in many other problems, the answer is not defined (unique),
so the 'tests' are just a manual check.
*/

#include <cassert>                          // assert
#include <iostream>                         // std::cout, std::endl;
#include "../../data-structures/Node.h"     // SinglyLinkedListNode<T>, print_list<T>

template<class T>
using Node = SinglyLinkedListNode<T>;

template<class T>
void partition(Node<T>*& head, const T& partition)
{
    Node<T>* move;
    Node<T>*ptr = head;

    while(ptr && ptr->next)
    {
        // Move ptr->next to head
        if(ptr->next->data < partition)
        {
            // Store ref to node to move
            move = ptr->next;
            
            // Adjust ptr ref
            ptr->next = ptr->next->next;

            // Adjust move ref
            move->next = head;
            head = move;
        }

        else ptr = ptr->next;
    }
}

int main()
{
    std::cout << std::endl << "Beginning tests..." << std::endl; 

    Node<int>* list = 
        new Node<int>(3, 
        new Node<int>(5, 
        new Node<int>(8, 
        new Node<int>(5, 
        new Node<int>(10, 
        new Node<int>(2, 
        new Node<int>(1)))))));

    // Partition is middle value
    partition(list, 4);
    print_list<int>(list);                  // [3,5,8,5,10,2,1] -> [1,2,3 | 5,8,5,10]

    // Partition is below minimum
    partition(list, 0);                     // [1,2,3,5,8,5,10] -> [ | 1,2,3,5,8,5,10]
    print_list<int>(list);

    // Partition is above maximum
    partition(list, 11);
    print_list<int>(list);                  // [1,2,3,5,8,5,10] -> [10,5,8,5,3,2,1 | ]

    // Partition is equal to middle item
    partition(list, 5);                     // [10,5,8,5,3,2,1] -> [1,2,3,10 | 5,8,5]
    print_list<int>(list);

    std::cout << "All tests passed!" << std::endl;
    exit(0); 
}