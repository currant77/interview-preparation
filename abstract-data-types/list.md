# Lists

## Abstract Data Type

A **list** is an abstract data type that represents a mutable, countable collection of ordered values; the same or equal items may occur more than once in the list. Lists differ from other ordered collections: unlike sets (#REF), they can contain duplicate values; unlike arrays, they can expand or shrink dynamically as values are added or removed; and unlike stacks (#REF), queues (#REF), or dequeues (#REF), values can be accessed, inserted, or removed from any index in the list.

Lists generally support four basic operations:
* `insert`: add a value to the list at a specified position
* `remove`: erase the value at a specified position from the list
* `lookup`: return the value in the list at a specified position
* `size`: return the number of values in of the list

A positions in a list is often specified by its ordinal number, called its _index_. By convention, indices are usually _zero-based_: the first value in the list has index zero, the second element has index one, and so on. Position can also be specified by an iterator (#REF) to the list, which is a container-independent abstraction of the concept of position in an ordered collection.

## Data Structures

Lists are typically implemented using one of two data structures: as a dynamically-resizing array called at **array list** or as a chain of linked nodes called a **linked list**.

### Array List

An **array list** or **dynamic array** (a *vector* in C++) stores the list values contiguously at the start of a fixed-size static array; the remaining positions towards the end of the array remain unused. As items are added to the array, these positions are filled. When the array is full, a new, larger array is created, and the items are copied over. 

[ArrayList](#REF) contains a simple implementation of an array list that only allows values to be accessed, inserted, or removed by index; it does not support iterators, though these would be relatively trivial to implement. See also `std::vector` (which is also implemented as an array list).

### Linked List

A **linked list** (simply a *list* in C++) consists of a series of **nodes**; each node holds the corresponding list value and a reference to one or two other nodes. The list itself only maintains a reference to the first (head) and possibly the last (tail) nodes in the sequence. In a **singly linked list**, each node only stores a reference to the next node; in a **doubly linked-list**, each node holds a reference to both the next and the previous nodes.

[LinkedList](#REF) provides an example implementation of a linked list. It includes methods for accessing, modifying, adding, and removing values by index or by iterator (see #REF). Its methods are loosely modelled on `std::list` (which is also implemented as a linked list) and its implementation was derived in part from from Koffman & Wolfgang 2006, Zeil 2006, and Riesbeck 2009.

### Comparison

Array lists often achieve better performance than linked lists and use memory more efficiently: linked lists require significantly more memory to store pointers between nodes and their unpredictable memory access (because the nodes are not stored sequentially) maximize cache misses. Array lists also provide more efficient random access, since accessing an arbitrary index in a linked list required iterating through the nodes sequentially until the desired node is reached. And while inserting or removing items from an array list involves shifting over a large number of items within the array, this is an operation that modern caches perform extremely efficiently (see [Why you should avoid Linked Lists](https://www.youtube.com/watch?v=YQs6IC-vgmo) by Bjarne Stroustrup, the creator of C++).

The principal benefit of a linked list is that items can be added or removed without reallocating or reorganizing the entire data structure (because the nodes do not need to be stored contiguously in memory); this is particularly advantageous when removing the first element from a list (e.g. a queue) or when the list is used to store very lasrge data types.

The table below compares the runtime of typical list operations between array lists and linked lists.

|                                               | Array List        | Linked List                   |
| :-------------------------------------------- | :---------------: | :---------------------------: |
| Random Access                                 | _O(1)_            | _O(n)_                        |
| Insertion / removal at start                  | _O(n)_            | _O(1)_                        |
| Insertion / removal at end                    | _O(1)_*           | _O(1)_**                      |
| Insertion / removal during iteration          | _O(n)_            | _O(1)_                        |
| Insertion / removal by index                  | _O(n)_            | _O(n)_                        |

\* When the array is full, all the contents of the array need to be copied over to a new, larger array, with takes _O(n)_. However, this happens infrequently enough that the amortized runtime is still O(1). See *Cracking the Coding Interview*, p. 89, for further discussion.

\*\* If the linked list implementation maintains a pointer to the tail node; otherwise the runtime is _O(n)_.

## Algorithms

### Sorting Algorithms

// TODO

#### Bubble Sort & Selection Sort

// TODO

#### Quick Sort

// TODO

#### Merge Sort

**Merge sort** takes a divide and conquer approach: it breaks the list in two, recursively sorts each half of the list, and then merges the two sorted halves. In essence, the algorithm repeatedly splits the list in half until each sublist contains only a single value, and then merges these sorted sublists back together to get the final sorted list (see image below). 

![Merge Sort](https://cdn.programiz.com/sites/tutorial2program/files/merge-sort-example_0.png)

````
function merge_sort(list m):

    let len := length of m
    
    // Base case
    if len <= 1 then:
        return m

    // Recursive case
    let mid := len / 2
    
    let left := left sublist from index 0 to mid - 1
    let right := right sublist from index mid to len - 1

    // Sort each sublist
    merge_sort(left)
    merge_sort(right)

    // Merge sorted lists
    let result := empty list

    while right is not empty and left is not empty do:
        if first(left) <= first(right) then:
            append first(left) to result
            pop value from left
        else:
            append first(right) to result
            pop value from right

    // Append remaining values
    while left is not empty do:
        append first(left) to result
        pop value from left

    while right is not empty do:
        append first(right) to result
        pop value from right

    return result
````

See (#REF) for an implementation of merge sort in Python and tests.

#### Heap Sort

// TODO

#### Radix Sort

// TODO

#### Comparison

|                       | Best-case     | Average-case  | Worst-case    |
|:----------------------|:-------------:|:-------------:|:-------------:|
| Bubble sort           |               |               |               |
| Selection sort        |               |               |               |
| Quick sort            |               |               |               |
| Merge sort            |               |               |               |
| Heap sort             |               |               |               |
| Radix sort            |               |               |               |

### Searching Algorithms

// TODO

#### Linear Search

// TODO

#### Binary Search

// TODO

#### Comparison

// TODO

## Examples and Problems

* TODO: Array list problem

* TODO: Linked list problem

## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

