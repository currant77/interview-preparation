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

A **sorting algorithm** is an algorithm that orders the values in a list according to some sorting order. Sorting is an common and important operation that improves the efficiency of other algorithms such as search (#REF) and merge (#REF).

Most sorting algorithms are **comparison-sorting** algorithms: they sort the list by comparing values using a _comparison operator_ which indicates their relative order. The following sections will discuss six comparison sorting algorithms: three simple but inefficient ones (insertion, bubble, and selection sort) and three more complex and more efficient ones (quick, merge, and heap sort). Comparison sorting algorithms cannot achieve performance better than _O(nlog(n))_, but non-comparison sorts can sort a list in linear time. They rely on the underyling characteristics of the data being sorted (e.g. the nuumber of bits in `int`) to avoid needing compare values to each other. We will discuss radix (or bucket) sort.

While sorting algorithms are most commonly compared by their runtime, there are other important differences. Some applications require a **stable** sorting algorithm, which sorts repeated elements into the same order that they appear in the input. Some algorithms depend on random access and so are unsuitable to linked list; others are **in-place** sorting algorithms that are more memory-efficient: they sort the list without needing to copy its values to another list. Finally, while some sorting algorithms may be inefficient for larger lists, their smaller overhead may make their more efficient for small lists – many efficient library sorting algorimths use these simple algorithms to sort smaller lists within more efficient recursive algorithms such as merge or quick sort.

#### Selection Sort

**Selection sort** is perhaps the simplest of all the sorting algorithms. It scans the list to find the smallest element, swaps that element to the start of the list, and then continues to repeatedly sort the remainder of the list. It runtime _O(n<sup>2</sup>)_ but it is a stable, in-place sorting algorithm that requires only constant memory. 

See implementation in `Python`. #REF

#### Bubble Sort

**Bubble sort** is another simple sorting algorithm. We proceed through the array in order, swapping adjacent values when their relative order, and repeat this process until the list is sorted (i.e. no swaps were needed on the last pass). It is named for the way that smaller elements (in the case of ascending sort) "bubble" to the front of the list In this case, smaller elements (nicknamed "turtles") can only move one position (towards the front of the list) per pass, while larger elements (nicknamed "rabbits") can move serveral positions – if it is unique, the largest value in the list will move all the way to the end on the first pass. 

Like selection sort, the average- and worst-case performance of bubble sort is _O(n<sup>2</sup>)_. However, unlike selection sort (and even more efficient algorithms such as quick sort), bubble sort can detect when the list is already sorted: its runtime in this case is just _O(n)_.

See implementation (#REF) in `Python`.

#### Insertion Sort

// TODO



#### Merge Sort

**Merge sort** takes a divide and conquer approach: it breaks the list in two, recursively sorts each half of the list, and then merges the two sorted halves. In essence, the algorithm repeatedly splits the list in half until each sublist contains only a single value, and then merges these sorted sublists back together to get the final sorted list (see diagram [here](https://cdn.programiz.com/sites/tutorial2program/files/merge-sort-example_0.png)). (#REF) and (#REF) provide implementations of merge sort in C++ and Python, respectively. 

The runtime of the merge sort algorithm can be expressed by the recurrence relation _T(n) = 2 T(n / 2) + O(n)_, which yieds a time complexity of _O(nlog(n))_ in the worst, best and average cases (since the list is always split in half on each recursive call). Most common implementations of merge sort do not sort in place, and so the algorithm typically requires _O(n)_ space (though there are more complicated 'in place' variants that require only a constant amount of additional space). When dealing with linked lists, it is possible to implement merge sort so that it requires only constant auxiliary space and _O(log(n))_ stack space. The basic merge sort algorithm is _stable_.

See implementations in `C++` (#REF) and `Python` (#REF).

#### Quick Sort

Like merge sort, **quick sort** is also a divide and conquer algorithm. It picks a _pivot_
element from the list, reorders the elements of the array so that all the elements with 
values less than the pivot come before it in the list (called _partitioning_), and then 
recursively sorts the halves on either side of the pivot (see diagram [here](https://images.deepai.org/glossary-terms/a5228ea07c794b468efd1b7f758b9ead/Quicksort.png)).

There are several different approaches to partitioning the list. Two common ones are the Lumot and Hoare partitioning schemes:

* In the _Lomuto_ partitioning scheme, the pivot is placed at the end of the list. The algorithm then uses an index _j_ to scan linearly across the list linearly, while maintaing an index _i_ such that all values to the left of _i_ are less than the pivot and all those between _i_ and _j_ are greater than it. Before recursively sorting the partitioned lists, it swaps the pivot element with the element at index _i_. See implementation here (#REF).

* The _Hoare_ partitioning scheme starts with two indices at the opposite ends of the list. These indices move towards each other, swapping values whenever they detect an _inversion_ – a pair of elements on the wrong side of the partition – until they meet somewhere in the middle. See implementation here (#REF).

Lomuto's partitioning scheme is simple and easy to understand, but has worse performance than Hoare's partitioning scheme: it requires three times more swaps on average.

The worst-case performance of quick sort occurs when the pivot (at each step) is chosen to be the smallest or largest value in the list. In this case, there will be no elements either greater than or less than the pivot, and so one partition will be empty and the other will contain all the elements except the partition – leading to _O(n<sup>2</sup>)_ performance. This commonly occurs when the first or last element is chosen as the pivot and the list is already sorted (a relatively common use case). But this can be rectified relatively easily, such as by simply choosing to pivot about an element in the middle of the list, or by pivoting about the median element in the list (which can be retrieved in linear time). 

The average and best-case performance of quick sort is _O(nlog(n))_ – the same as merge sort. Partitioning in quick sort is in-place and requires only constant space; the recursive calls then require _O(log(n))_ space in the best and average cases and _O(n)_ space in the worst case. Quick sort is not a stable sorting algorithm.

#### Heap Sort

// TODO

#### Radix Sort

// TODO

#### Comparison

Selection, insertion, bubble comparison
- selection and insertion can detect sorted list
- Insertion sort generally runs faster (https://en.wikipedia.org/wiki/Bubble_sort#:~:text=Bubble%20sort%2C%20sometimes%20referred%20to,until%20the%20list%20is%20sorted) and performs better on list that is already substantiallysorted. 

Merge sort: typically requires fewer comparison; more efficient if data can only be accessed sequentially (linked lists); better worst-case performance; constant store on linked lists.

Quick sort: smaller space requirement on arrays; can be more efficient if data can be randomly accessed; poor on linked lists (random access)

|                       | Best-case          | Average-case       | Worst-case                        | Memory                      | Stable    |
|:----------------------|:------------------:|:------------------:|:---------------------------------:|:---------------------------:|:---------:|
| Selection sort        | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_                | _O(1)_                      | Yes       |
| Bubble sort           |                    |                    |                                   |                             |           |
| Merge sort            | _O(nlog(n))_       | _O(nlog(n))_       | _O(nlog(n))_                      | _O(n)_ <sup>[1]</sup>       | Yes       |
| Quick sort            | _O(nlog(n))_       | _O(nlog(n))_       | _O(n<sup>2</sup>)_ <sup>[2]</sup> | _O(log(n))_ <sup>[3]</sup>  | No        |
| Heap sort             |                    |                    |                                   |                             |           |  
| Radix sort            |                    |                    |                                   |                             |           |

<sup>[1]</sup> Typical implementation on array list. There are more complex in-place variants that require only constant space and linked list implementations that require only constant auxiliary storage and _O(nlog(n))_ stack space.

<sup>[2]</sup> Worst-case performance of merge sort occurs when the pivot is always chosen to be the largest or smallest remaining value, such that the size of the list is only reduced by one on each pass.

<sup>[3]</sup> Average case. In the worst-case, required _O(n)_ storage space (see note above).

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

* Selection sort #REF (`Python`)

* Merge sort C++ (#REF)
* Merge sort Python (#REF)
* Quick sort Hoare C++ (#REF)
* Quick sort Lomuto Python (#REF)

## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

