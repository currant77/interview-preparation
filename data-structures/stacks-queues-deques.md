# Stacks, Queues, and Deques

![Stack, Queue, Deque Illustration](https://www.nakjunizm.com/2017/02/24/Queue_And_Deque/queue1.png "Stack, Queue, Deque Illustration")

## Abstract Data Types

Like [lists](../lists/lists.md), stacks, queues, and deques are all abstract data types that represent dynamic, countable collections of ordered values. But, unlike lists, they provide only *limited access* to the values they store - values cannot be accessed, inserted, or removed at every position in the collection. While the extent of this access may vary (for example, implementations may provide read-only access to all of their values), stacks, queues, and deques should generally provide the following operations (see diagram and tables below):

* A **stack** follows the "*last in, first out*" (LIFO) principle: items can only be added or removed from the top (end) of the stack; the corresponding methods are usually named `push()` and `pop()`, respectively. 

* A **queue** follows the "*first in, first out*" (FIFO) principle: items can only be added to the back (end) of the queue and removed from the front; the corresponding methods are usually names `push()` and `pop()`, respectively. 

* A **deque** (an abbreviation of *double-ended queue*) is a generalization of the queue; it allows items to be added or removed from the front – `push_front()` and `pop_front()` – or the back – `push_back()` and `pop_back()`. 

|                 | Insertion       |Removal                      |
| :-------------- | :-------------: | :-------------------------: |
| Stack           | Back            | Back                        |
| Queue           | Back            | Front                       |
| Deque           | Front or Back   | Front or Back               |

Stack, queues, and deques may also allow elements at the ends to be accessed or modified through methods such as `top()`, `front()`, or `back()`.

## Implementations

The functionality required for each of these abstract data types is a subset of that required for a list, so they can all easily implemented as a wrapper to a list (see [lists](../lists/lists.md)) or directly using a dynamic array or a sequence of linked nodes. However, because of the different operations provided by each abstract data type, these approaches may not be equally efficient choices:

* *Stack*: Because its only allows items to be added or removed from the end of the ordered collection, a stack can be efficiently implemented using either a dynamic array or a linked list

* *Queue*: A queue only allows items to be added to the back and removed from the front of the ordered collection, so it is best implemented using a (singly or doubly) linked list, which provides fast insertion and removal at its head and tail (unlike an array-based implementation, which requires shifting over all the values in the array whenever `pop()` is called.) 

* *Deque* Because a deque allows items to be added or removed from both the front and back, it is best implemented using a doubly linked list. 

# Examples and Problems

* [Stack](Stack.h) implements a stack as a wrapper to [ArrayList](../lists/ArrayList.h).
* [Queue](Queue.h) implements a stack as a wrapper to [LinkedList](../lists/LinkedList.h); it defined a constant iterator to allow read-only access to all the values in the queue.

* TODO: stack problem
* TODO: queue problem
* TODO: deque problem

## References






