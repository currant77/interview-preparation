# Stacks, Queues, and Deques

## Abstract Data Type

Like [lists](../lists/lists.md), stacks, queues, and deques are abstract data types that represent dynamic, countable collections of ordered values. But unlike lists, they provide only *limited access* to the values they store - values cannot be accessed, inserted, or removed at every position in the collection. While the extent of this access may vary (for example, implementations may provide read-only access to all of their values), stacks, queues, and deques should generally provide the following operations (see diagram and tables below):

* A **stack** follows the "*last in, first out*" (LIFO) principle: items can only be added or removed from the top (end) of the stack; the corresponding methods are usually named `push()` and `pop()`, respectively. 

* A **queue** follows the "*first in, first out*" (FIFO) principle: items can only be added to the back (end) of the queue and removed from the front; the corresponding methods are usually names `push()` and `pop()`, respectively. 

* A **deque** (an abbreviation of *double-ended queue*) is a generalization of the queue; it allows items to be added or removed from the front – `push_front()` and `pop_front()` – or the back – `push_back()` and `pop_back()`. 

|                 | Insertion       |Removal                      |
| :-------------- | :-------------: | :-------------------------: |
| Stack           | Back            | Back                        |
| Queue           | Back            | Front                       |
| Deque           | Front or Back   | Front or Back               |

Stack, queues, and deques may also allow elements at the ends to be accessed or modified through methods such as `peek()`, `top()`, `front()`, or `back()`.

<p align="center">
    <img src="https://www.nakjunizm.com/2017/02/24/Queue_And_Deque/queue1.png" width="80%">
</p>

<p align="center">
    <em>Illustration of operations supported by stacks, queues, and deques</em>
</p>

## Data Structures

The functionality required for each of these abstract data types is a subset of that required for a list, so they can all easily implemented as a wrapper to a list (#REF) or directly using a dynamic array (like an array list #REF) or a sequence of linked nodes (like a linked list #REF). However, because of the different operations provided by each abstract data type, these approaches may not be equally efficient choices:

* *Stack*: Because its only allows items to be added or removed from the end of the ordered collection, a stack can be efficiently implemented using either a dynamic array or a linked list

* *Queue*: A queue only allows items to be added to the back and removed from the front of the ordered collection, so it is best implemented using a (singly or doubly) linked list, which provides fast insertion and removal at its head and tail (unlike an array-based implementation, which requires shifting over all the values in the array whenever a value is either inserted or removed). 

* *Deque* Because a deque allows items to be added or removed from both the front and back, it is best implemented using a doubly linked list. 

## Algorithms

There are no algorithms for stacks, queues, and deques that are as fundamental as sorting a list or traversing a tree. However, the _"last in, first out"_ and _"first in, first out_" behaviour makes them useful for many other algorithms:

* Many recursive algorithms, such as reversing a linked list, can be written so that they use a stack abstract data type instead of the call stack to produce recursion.

* Tree traversal (#REF) and graph traversal (#REF) can both be implemented by using a stack or queues: using a stack produces a depth-first traversal (#REF), while using a queue produces breadth-first traversal (#REF). 

## Examples and Problems

* Data Structures:
    * Stack (#REF) - implemented as a wrapper to an array list (#REF)
    * Queue (#REF) - implemented as a wrapper to linked list; includes a constant iterator to allow read-only access to all the values in the queue.
    * Deque (#REF) - implemented as a doubly-linked list

* _Cracking the Coding Interview_ Questions:
    * Chapter 3: Stacks and Queues:
        * 3.2 Stack Min (#REF)
        * 3.4 Queue via Stack (#REF)
        * 3.5 Sort Stack (#REF)

# References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.