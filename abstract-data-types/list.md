# Lists

## Definition

A **list** is an abstract data type that represents a mutable, countable collection of ordered values; the same or equal items may occur more than once in the list. Lists differ from other ordered collections: unlike sets (#REF), they can contain duplicate values; unlike arrays, they can expand or shrink dynamically as values are added or removed; and unlike stacks (#REF), queues (#REF), or dequeues (#REF), values can be accessed, inserted, or removed from any index in the list.

## Operations

Lists generally support four basic operations:
* `insert`: add a value to the list at a specified position
* `remove`: erase the value at a specified position from the list
* `lookup`: return the value in the list at a specified position
* `size`: return the number of values in of the list

A positions in a list is often specified by its ordinal number, called its _index_. By convention, indices are usually _zero-based_: the first value in the list has index zero, the second element has index one, and so on. Position can also be specified by an iterator (#REF) to the list, which is a container-independent abstraction of the concept of position in an ordered collection.

## Data Structures

Lists are typically implemented using one of two data structures: as a dynamically-resizing array called at **array list** (#REF) or as a chain of linked nodes called a **linked list** (#REF).

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

## Examples and Problems

// TODO

## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

