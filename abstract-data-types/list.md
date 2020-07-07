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

## Array List

An **array list** or **dynamic array** (a *vector* in C++) stores the list values contiguously at the start of a fixed-size static array; the remaining positions towards the end of the array remain unused. As items are added to the array, these positions are filled. When the array is full, a new, larger array is created, and the items are copied over. 

[ArrayList](#REF) contains a simple implementation of an array list that only allows values to be accessed, inserted, or removed by index; it does not support iterators, though these would be relatively trivial to implement. See also `std::vector` (which is also implemented as an array list).

## Linked List

A **linked list** (simply a *list* in C++) consists of a series of **nodes**; each node holds the corresponding list value and a reference to one or two other nodes. The list itself only maintains a reference to the first (head) and possibly the last (tail) nodes in the sequence. In a **singly linked list**, each node only stores a reference to the next node; in a **doubly linked-list**, each node holds a reference to both the next and the previous nodes.

[LinkedList](#REF) provides an example implementation of a linked list. It includes methods for accessing, modifying, adding, and removing values by index or by iterator (see #REF). Its methods are loosely modelled on `std::list` (which is also implemented as a linked list) and its implementation was derived in part from from Koffman & Wolfgang 2006, Zeil 2006, and Riesbeck 2009.

### Comparison

Array lists often achieve better performance than linked lists and use memory more efficiently: linked lists require significantly more memory to store pointers between nodes and their unpredictable memory access (because the nodes are not stored sequentially) maximize cache misses. Array lists also provide more efficient random access, since accessing an arbitrary index in a linked list required iterating through the nodes sequentially until the desired node is reached. And while inserting or removing items from an array list involves shifting over a large number of items within the array, this is an operation that modern caches perform extremely efficiently (see [Why you should avoid Linked Lists](https://www.youtube.com/watch?v=YQs6IC-vgmo) by Bjarne Stroustrup, the creator of C++).

<p align="center">
    <img src="https://s3-us-west-2.amazonaws.com/ib-assessment-tests/problem_images/array-vs-ll.png">
</p>
<p align="center">
    <em>Comparison of array list and linked list data structures</em>
</p>

The principal benefit of a linked list is that items can be added or removed without reallocating or reorganizing the entire data structure (because the nodes do not need to be stored contiguously in memory); this is particularly advantageous when removing the first element from a list (e.g. a queue) or when the list is used to store very lasrge data types.

The table below compares the runtime of typical list operations between array lists and linked lists.

|                                               | Array List            | Linked List                   |
|:----------------------------------------------|:---------------------:|:-----------------------------:|
| Random Access                                 | _O(1)_                | _O(n)_                        |
| Insertion / removal at start                  | _O(n)_                | _O(1)_                        |
| Insertion / removal at end                    | _O(1)_ <sup>[1]</sup> | _O(1)_ <sup>[2]</sup>         |
| Insertion / removal during iteration          | _O(n)_                | _O(1)_                        |
| Insertion / removal by random index                  | _O(n)_                | _O(n)_                        |

<sup>[1]</sup> When the array is full, all the contents of the array need to be copied over to a new, larger array, with takes _O(n)_. However, this happens infrequently enough that the amortized runtime is still O(1). See *Cracking the Coding Interview*, p. 89, for further discussion.

<sup>[2]</sup>If the linked list implementation maintains a pointer to the tail node; otherwise the runtime is _O(n)_.

## Algorithms

### Sorting Algorithms

A **sorting algorithm** is an algorithm that orders the values in a list according to some sorting order. Sorting is an common and important operation that improves the efficiency of other algorithms such as search (#REF) and merge (#REF).

Most sorting algorithms are **comparison-sorting** algorithms: they sort the list by comparing values using a _comparison operator_ which indicates their relative order. The following sections will discuss six comparison sorting algorithms: three simple but inefficient ones (insertion, bubble, and selection sort) and three more complex and more efficient ones (quick, merge, and heap sort). Comparison sorting algorithms cannot achieve performance better than _O(nlog(n))_, but non-comparison sorts can sort a list in linear time. They rely on the underyling characteristics of the data being sorted (e.g. the nuumber of bits in `int`) to avoid needing compare values to each other. We will discuss radix (or bucket) sort.

While sorting algorithms are most commonly compared by their runtime, there are other important differences. Some applications require a **stable** sorting algorithm, which sorts repeated elements into the same order that they appear in the input. Some algorithms depend on random access and so are unsuitable to linked list; others are **in-place** sorting algorithms that are more memory-efficient: they sort the list without needing to copy its values to another list. Finally, while some sorting algorithms may be inefficient for larger lists, their smaller overhead may make their more efficient for small lists – many efficient library sorting algorimths use these simple algorithms to sort smaller lists within more efficient recursive algorithms such as merge or quick sort.

#### Selection, Bubble, and Insertion Sorts

Selection, bubble, and insertion sort are three simple sorting algorithms that achieve _O(n<sup>2</sup>)_ in the average case.

**Selection sort** is perhaps the simplest of all the sorting algorithms. It scans the list to find the smallest element, swaps that element to the start of the list, and then continues to repeatedly sort the remainder of the list. It runtime _O(n<sup>2</sup>)_ but it is a stable, in-place sorting algorithm that requires only constant memory. 

On the other hand, **bubble sort** proceeds through the array in order, swapping adjacent values when their relative order, and repeat this process until the list is sorted (i.e. no swaps were needed on the last pass). It is named for the way that smaller elements (in the case of ascending sort) "bubble" to the front of the list In this case, smaller elements (nicknamed "turtles") can only move one position (towards the front of the list) per pass, while larger elements (nicknamed "rabbits") can move serveral positions – if it is unique, the largest value in the list will move all the way to the end on the first pass. 

Like selection sort, the average- and worst-case performance of bubble sort is _O(n<sup>2</sup>)_. However, unlike selection sort (and even more efficient algorithms such as quick sort), bubble sort can detect when the list is already sorted: its runtime in this case is just _O(n)_. It is also a stable sorting algorithm.

Lastly, **insertion sort** builds the final sorted list element-by-element (see graphic below). Like selection and insertion sort, it average- and worst-case runtime is _O(n<sup>2</sup>)_. But, like bubble sort, its best-case runtime (when the list is already sorted) is linear; in fact, its runtime is only _O(kn)_ is the case where the each value is at most _k_ positions away from its sorted position (i.e. when the list is already roughly sorted). It is a stable, in-place algorithm that requires only constant memory.

<p align="center">
    <img src="https://www.codeproject.com/KB/recipes/SortVisualization/Selection_Sort.gif" width="30%">
    <img src="https://www.codeproject.com/KB/recipes/SortVisualization/Bubble_Sort.gif" width="30%">
    <img src="https://www.codeproject.com/KB/recipes/SortVisualization/Insertion_Sort.gif" width="30%">
</p>

<p align="center">
    <em>Illustration of selection sort (left), bubble sort (center), and insertion sort (right)</em>
</p>

See #REF. #REF, and #REF.

#### Merge and Quick Sort

Merge and quick sort are two of the most efficient and widely-used sorting algorithms. Both use a divide and conquer approach to achieve _O(nlog(n))_ average runtime; but their worst-case performance, storage requirements, and stability differ

**Merge sort** breaks the list in two, recursively sorts each half of the list, and then merges the two sorted halves. In essence, the algorithm repeatedly splits the list in half until each sublist contains only a single value, and then merges these sorted sublists back together to get the final sorted list (see diagram [here](https://cdn.programiz.com/sites/tutorial2program/files/merge-sort-example_0.png)). (#REF) and (#REF) provide implementations of merge sort in C++ and Python, respectively. 

The runtime of the merge sort algorithm is _O(nlog(n))_ in the worst, best and average cases, since the list is always split in half on each recursive call. Most common implementations of merge sort do not sort in place, and so the algorithm typically requires _O(n)_ space (though there are more complicated 'in place' variants that require only a constant amount of additional space). When dealing with linked lists, it is possible to implement merge sort so that it requires only constant auxiliary space and _O(log(n))_ stack space. The basic merge sort algorithm is _stable_.

See implementations in `C++` (#REF) and `Python` (#REF).

<p align="center">
    <img src="https://www.codeproject.com/KB/recipes/SortVisualization/Merge_Sort.gif" width="30%">
    <img src="https://www.codeproject.com/KB/recipes/SortVisualization/Quick_Sort.gif" width="30%">
</p>

<p align="center">
    <em>Illustration of merge sort (left) and quick sort (right) </em>
</p>

Other other hand. **quick sort** picks a _pivot_ element from the list, reorders the elements of the array so that all the elements with values less than the pivot come before it in the list (called _partitioning_), and then recursively sorts the halves on either side of the pivot (see diagram [here](https://images.deepai.org/glossary-terms/a5228ea07c794b468efd1b7f758b9ead/Quicksort.png)).

There are several different approaches to partitioning the list. Two common ones are the Lumot and Hoare partitioning schemes:

* In the _Lomuto_ partitioning scheme, the pivot is placed at the end of the list. The algorithm then uses an index _j_ to scan linearly across the list linearly, while maintaing an index _i_ such that all values to the left of _i_ are less than the pivot and all those between _i_ and _j_ are greater than it. Before recursively sorting the partitioned lists, it swaps the pivot element with the element at index _i_. See implementation here (#REF).

* The _Hoare_ partitioning scheme starts with two indices at the opposite ends of the list. These indices move towards each other, swapping values whenever they detect an _inversion_ – a pair of elements on the wrong side of the partition – until they meet somewhere in the middle. See implementation here (#REF).

Lomuto's partitioning scheme is simple and easy to understand, but has worse performance than Hoare's partitioning scheme: it requires three times more swaps on average.

The worst-case performance of quick sort occurs when the pivot (at each step) is chosen to be the smallest or largest value in the list. In this case, there will be no elements either greater than or less than the pivot, and so one partition will be empty and the other will contain all the elements except the partition – leading to _O(n<sup>2</sup>)_ performance. This commonly occurs when the first or last element is chosen as the pivot and the list is already sorted (a relatively common use case). But this can be rectified relatively easily, such as by simply choosing to pivot about an element in the middle of the list, or by pivoting about the median element in the list (which can be retrieved in linear time). 

The average and best-case performance of quick sort is _O(nlog(n))_ – the same as merge sort – since in the average case each pivot with partition the list roughly in half. Partitioning in quick sort is in-place and requires only constant space; the recursive calls then require _O(log(n))_ space in the best and average cases and _O(n)_ space in the worst case. Quick sort is not a stable sorting algorithm.

#### Heap Sort

// TODO

#### Counting and Radix Sort

Counting and radix sort are two common non-comparison sorting algorithms. Rather than comparing the values in the list directly, they use some underlying properties of the data to sort it. This allows they to sort the list in linear time under certain circumstances: for counting sort, when the values in the list can be mapped to integer keys that have a small range of possible values; for radix sort, when the data in the list is composed using a small number of unique digits.

**Counting sort** sorts list values according to associated integer keys: each value in the list must map to an integer key. Suppose _max_ and _min_ are the maximum and minimum key values, respectively; let _k_ be the number of possible key values, where _k = max - min + 1_. Counting sort works by creating an count array of size _k_ that stores the number of occurences of each key in the list: the number of occurences of key _i_ is stored at index _i_ - min. This can then be transformed into a cumulative count array that stores the number of keys in the list less than or equal to a given key: the value at index _i_ stores the number of keys in the list less than or equal to _i + min_. We can then use this cumulative count array to place the list element into their final sorted order. The reference [here](https://www.programiz.com/dsa/counting-sort) provides a good illustration of this process.

<p align="center">
    <img src="https://cdn.programiz.com/sites/tutorial2program/files/Counting-sort-4_1.png" width="80%">
</p>

<p align="center">
    <em>Illustration of counting sort with input array, cumulative count array, and output array</em>
</p>

The performance of counting sort depends on the size of the list (_n_) and the range of integer keys (_k_). If _k_ is not known, it can be determine in linear time by scanning the list. It then takes _O(n)_ to create the count array, _O(k)_ to turn it into a cumulative count array, and _O(n)_ to use this array to create an output array, which can then be copied to the input list to produce the final sorted list.

Counting sort has best-, average-, and worst-case runtime of _O(n + k)_ and requires _O(n+ k)_ memory for the count, cumulative count, and output array. As a result, counting sort can be very efficient when the range of possible keys (_k_) is small relative to the size of the list. In this case, it runtime and memory are linear, yielding much better performance than any of the comparative sorting algorithms (which can only manage _O(nlog(n))_ at best). However, in most applications, the range of possible integer keys (e.g. a list of `int` values) is too large to make counting sort appropriate. 

Lastly, counting sort is a stable sorting algorithm. This will prove important in radix sort.

Counting sort #REF

**Radix sort** (also called **bucket sort**) is a non-comparison sorting algorithms that takes advantage of the fact that many primitive data types are represented using a finite number of unique digits such as binary bits (i.e. `0` or `1`), decimal digits (i.e. `0` to `9`), or characters (i.e. `a`, `b`, `c`, etc.). Radix sort uses this property to sort these data types without needing to directly compare them.

<p align="center">
    <img src="https://www.researchgate.net/publication/291086231/figure/fig1/AS:614214452404240@1523451545568/Simplistic-illustration-of-the-steps-performed-in-a-radix-sort-In-this-example-the.png" width="80%">
</p>

<p align="center">
    <em>Illustration of radix sort performed on three-digit decimal integers (k = 3, d = 10)</em>
</p>

Let the **radix** _d_ be the number of unique digits (e.g. two for binary digits, ten for decimal digits). In radix sort, we sort the values in the list into _d_ "buckets" by their radix; if values have more than one significant digit, we repeat this process for each digit until the list is sorted. Radix sort can be implemented to start with either the most significant digit (MSD) or least significant digit (LSD); LSD radix sort produces the order typically desired for numerical types: from smallest to largest.

There are different approach to sorting by radix. The most common is based on counting sort (#REF), where the range of integer keys is simply the radix _d_. The list can then be sorted by a given digit in _O(n + d)_. 

As a result, radix sort only requires iterating over the list once for every digit, giving a runtime of _O(k(n + d))_, where _k_ is the number of digits in the data type. Since both _k_ and _d_ are typically small, this usually reduces to linear runtime. For example, consider performing radix sort on a 32-bit integer. If we sort by binary digit, _d_ = 2 and_k_ = 32; if we sort by decimal digits, _d_ = 10 and _k_ = 10 (the maximum 32-bit integer is just over 2 trillion). Radix sort requires _O(k(n + d))_ storage and is a stable sorting algorithm.

See #REF.

#### Comparison

There are numerous resources that provide comparisons and illustrations of sorting algorithms. [Visualgo](https://visualgo.net/bn/sorting) has a simple interactive animation of all the sorting algorithms discussed above; Robert Kanasz's article on [Code Project](https://www.codeproject.com/Articles/132757/Visualization-and-Comparison-of-sorting-algorithms) provides a more detailedd discussion of a far wider range of sorting algorithms, and it the source for several of the the diagrams contained in the sections above.

Selection, bubble, and insertion sort are all simple, stable sorting algorithms with _O(n<sup>2</sup>)_ runtime. However, both bubble sort and insertion require only constant runtime in the best case (when the list is already sorted). In practice, insertion sort is the most efficient of these three algorithms because it also performs better on a list that is already substantially sorted. 

Despite their slower asymptotic runtime, all three of these algorithms sort in-place, require only constant memory, and can be faster in practice that more efficient sorting because of this lower overhead. As a result, many sorting implementations based on merge sort or quick sort use one of these algorimths (particularly insertion sort) internally to sort smaller lists.

// TODO merge sort vs quick sort vs heap sort

Merge sort: typically requires fewer comparison; more efficient if data can only be accessed sequentially (linked lists); better worst-case performance; constant store on linked lists.

Quick sort: smaller space requirement on arrays; can be more efficient if data can be randomly accessed; poor on linked lists (random access)

// TODO array vs linked list

|                               | Best-case          | Average-case       | Worst-case                        | Memory                      | Stable    |
|:------------------------------|:------------------:|:------------------:|:---------------------------------:|:---------------------------:|:---------:|
| Selection sort                | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_                | _O(1)_                      | Yes       |
| Bubble sort                   | _O(n)_             | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_                | _O(1)_                      | Yes       |
| Insertion sort                | _O(n)_             | _O(n<sup>2</sup>)_ | _O(n<sup>2</sup>)_                | _O(1)_                      | Yes       |
| Merge sort                    | _O(nlog(n))_       | _O(nlog(n))_       | _O(nlog(n))_                      | _O(n)_ <sup>[1]</sup>       | Yes       |
| Quick sort                    | _O(nlog(n))_       | _O(nlog(n))_       | _O(n<sup>2</sup>)_ <sup>[2]</sup> | _O(log(n))_ <sup>[3]</sup>  | No        |
| Heap sort                     |                    |                    |                                   |                             |           |  
| Counting sort <sup>[4]</sup>  | _O(n + k)_         | _O(n + k)_         |  _O(n + k)_                       | _O(n + k)_                  | Yes       |
| Radix sort <sup>[5]</sup>     | _O(d(n+k))_        | _O(d(n+k))_        | _O(d(n+k))_                       | _O(d(n+k))_                 | Yes       |

<sup>[1]</sup> Typical implementation on array list. There are more complex in-place variants that require only constant space and linked list implementations that require only constant auxiliary storage and _O(nlog(n))_ stack space.

<sup>[2]</sup> Worst-case performance of merge sort occurs when the pivot is always chosen to be the largest or smallest remaining value, such that the size of the list is only reduced by one on each pass.

<sup>[3]</sup> Average case. In the worst-case, required _O(n)_ storage space (see note above).

<sup>[4]</sup> _k_ is the range of integer key values.

<sup>[4]</sup> _k_ is the radix (the number of unique digits) and _d_ is the number of digits per value

### Searching Algorithms

// TODO

#### Linear Search

// TODO

#### Binary Search

// TODO

#### Comparison

// TODO

## Examples and Problems

* Data Structures:
    * Array list
    * Linked list

* Algorithms:
    * Sorting:
        * Selection sort (#REF)
        * Bubble sort (#REF)
        * Insertion sort (#REF)
        * Merge sort (#REF)
        * Quick sort (#REF)
        * Heap sort (#REF)
        * Counting sort (#REF)
        * Radix sort (#REF)
    * Searching

* _Cracking the Coding Interview_ Questions:
    * Chapter 2: Linked Lists:
        * 2.1 Remove Duplicates (#REF)
        * 2.2 Return Kth to Last (#REF)
        * 2.3 Delete Middle Node (#REF)
        * 2.4 Partition (#REF)
        * 2.5 Sum Lists (#REF)
        * 2.6 Palindrome (#REF)
        * 2.7 Intersection (#REF)
        * 2.8 Loop Detection (#REF)
    * Chapter 10: Sorting and Searching
        * 10.2 Group Anagrams (#REF)
        * 10.4 Sorted Search, No Size (#REF)

## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

“Counting Sort Algorithm.” Learn DS &amp; Algorithms. Programiz. Accessed June 30, 2020. hhttps://www.programiz.com/dsa/counting-sort.

“Radix Sort Algorithm.” Learn DS &amp; Algorithms. Programiz. Accessed June 30, 2020. https://www.programiz.com/dsa/radix-sort.

Robert, Kanasz. “Visualization and Comparison of Sorting Algorithms in C#.” CodeProject, December 14, 2010. https://www.codeproject.com/Articles/132757/Visualization-and-Comparison-of-sorting-algorithms.

