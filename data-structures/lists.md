# Lists

## Abstract Data Type

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



## Algorithms

// TODO

## Examples and Problems

* [LinkedList](LinkedList.h) provides an example implementation of a linked list. It includes methods for accessing, modifying, adding, and removing values by index or by iterator. (see [#REF Iterator]). Its methods are loosely modelled on `std::list` (which is also implemented as a linked list) and its implementation was derived in part from from Koffman & Wolfgang 2006, Zeil 2006, and Riesbeck 2009.

* [ArrayList](ArrayList.h) contains a simple implementation of an array list that only allows values to be accessed, inserted, or removed by index; it does not support iterators, though these would be relatively trivial to implement. See also `std::vector` (which is also implemented as an array list). 

* TODO: Array list problem

* TODO: Linked list problem

## References

Zeil, Steven J. _Iterators: an ADT for Positions_. Old Dominion University, 2006. https://www.cs.odu.edu/~zeil/cs361/web11/website/Lectures/iterators/page/iterators.html.

Riesbeck, Christopher. _C++ Iterators_. Northwest University, 2009. https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterators.html. 
