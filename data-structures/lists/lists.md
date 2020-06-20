# Lists

## Abstract Data Type

A **list** is an abstract data type that represents a dynamic, countable collection of ordered values; the same or equal items may occur more than once in the list. Elements in a list can be referenced by their numerical position in the list, called their **index**. Lists differ from other ordered collections: unlike ordered set, they can contain duplicate values; unlike array, they can expand or shrink dynamically as values are added or removed; and unlike stacks, queues, or dequeues, values can be accessed, inserted, or removed from any index in the list.

A list supports four basic operations:
* `insert` a value at a given index
* `remove` a value at a given index
* `lookup` the value stores at a given index
* `size` of the list

List implementations also often support operations such as iterating over the values in a list or sorting a list. They are also commonly used as the basis for implementations of other ordered collections such as queues or stacks.

## Implementations

Lists are typically implemented using one of two data structures: as a dynamically-resizing array called at **array list** or as a chain of linked nodes called a **linked list**.

An **array list** or **dynamic array** (a *vector* in C++) stores the list values contiguously at the start of a fixed-size static array; the remaining positions towards the end of the array remain unused. As items are added to the array, these positions are filled. When the array is full, a new, larger array is created, and the items are copied over.

A **linked list** (simply a *list* in C++) consists of a series of **nodes**; each node holds the corresponding list value and a reference to one or two other nodes. The list itself only maintains a reference to the first (head) and possibly the last (tail) nodes in the sequence. In a **singly linked list**, each node only stores a reference to the next node; in a **doubly linked-list**, each node holds a reference to both the next and the previous nodes.

Array lists often achieve better performance than linked lists and use memory more efficiently: linked lists require significantly more memory to store pointers between nodes and their unpredictable memory access (because the nodes are not stored sequentially) maximize cache misses. Array lists also provide more efficient random access, since accessing an arbitrary index in a linked list required iterating through the nodes sequentially until the desired node is reached. And while inserting or removing items from an array list involves shifting over a large number of items within the array, this is an operation that modern caches perform extremely efficiently (see [Why you should avoid Linked Lists](https://www.youtube.com/watch?v=YQs6IC-vgmo) by Bjarne Stroustrup, the creator of C++).

The principal benefit of a linked list is that items can be added or removed without reallocating or reorganizing the entire data structure (because the nodes do not need to be stored contiguously in memory); this is particularly advantageous when removing the first element from a list (e.g. a queue) or when the list is used to store very lasrge data types.

The table below compares the runtime of typical list operations between array lists and linked lists.


|  *Performance: Array List vs Linked List*     | Array List        | Linked List                   |
| :-------------------------------------------- | :---------------: | :---------------------------: |
| Random Access                                 | _O(1)_            | _O(n)_                        |
| Insertion / removal at start                  | _O(n)_            | _O(1)_                        |
| Insertion / removal at end                    | _O(1)_*           | _O(1)_**                      |
| Insertion / removal during iteration          | _O(n)_            | _O(1)_                        |
| Insertion / removal by index                  | _O(n)_            | _O(n)_                        |

\* When the array is full, all the contents of the array need to be copied over to a new, larger array, with takes _O(n)_. However, this happens infrequently enough that the amortized runtime is still O(1). See *Cracking the Coding Interview*, p. 89, for further discussion.
\*\* If the linked list implementation maintains a pointer to the tail node; otherwise the runtime is _O(n)_.

## Algorithms

// TODO

## Examples and Problems

* [LinkedList](LinkedList.h) provides an example implementation of a linked list. It includes methods for accessing, modifying, adding, and removing values by index or by iterator. (see [#REF Iterator]). Its methods are loosely modelled on `std::list` (which is also implemented as a linked list) and its implementation was derived in part from from Koffman & Wolfgang 2006, Zeil 2006, and Riesbeck 2009.

* [ArrayList](ArrayList.h) contains a simple implementation of an array list that only allows values to be accessed, inserted, or removed by index; it does not support iterators, though these would be relatively trivial to implement. See also `std::vector` (which is also implemented as an array list). 

* TODO: Array list problem

* TODO: Linked list problem

## References

McDowell, Gayle Lakkmann _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

Zeil, Steven J. _Iterators: an ADT for Positions_. Old Dominion University, 2006. https://www.cs.odu.edu/~zeil/cs361/web11/website/Lectures/iterators/page/iterators.html.

Riesbeck, Christopher. _C++ Iterators_. Northwest University, 2009. https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterators.html. 

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.