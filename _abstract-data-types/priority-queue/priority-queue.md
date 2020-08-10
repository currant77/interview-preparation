# <Name> Abstract Data Type

## Definition

< Definition >
< Basic operations >
< Other consideration >

## Data Structures

< Common data structures (linked) >
< Comparison >

## Algorithms

< Common algorithms >

## Problems & Examples

* Interfaces:
    * [IPriorityQueue](IPriorityQueue.h): minimal `C++` priority queue interface
* Data structures:
* Algorithms:
* Problems:

## References

< Examples >

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

McDowell, Gayle Lakkmann. _Cracking the Coding Interview_. 6th ed. Palo Alto, CA: CareerCup, 2016.

“Counting Sort Algorithm.” Learn DS &amp; Algorithms. Programiz. Accessed June 30, 2020. https://www.programiz.com/dsa/counting-sort.

“Radix Sort Algorithm.” Learn DS &amp; Algorithms. Programiz. Accessed June 30, 2020. https://www.programiz.com/dsa/radix-sort.

Robert, Kanasz. “Visualization and Comparison of Sorting Algorithms in C#.” CodeProject, December 14, 2010. https://www.codeproject.com/Articles/132757/Visualization-and-Comparison-of-sorting-algorithms.



===========================

# Priority Queue

## Abstract Data Type

A **priority queue** is an abstract data type that stores a dynamic, countable collection of elements ordered by *priority*: a *[total order](https://en.wikipedia.org/wiki/Total_order)* relation between the elements that allows them to be ranked from highest to lowest priority. Like queues and stacks, priority queues are *limited access* containers; but rather than only providing access to the first or last element added to the container (respectively), they only provide operations to access and remove the element with the highest priority.

The priority queue abstract data type generally supports the following operations:
- `top`: returns the element with the highest priority
- `pop`: removes the element with the highest priority 
- `push`: adds an element to the priority queue
- `size`: returns the number of elements in the priority queue

## Data Structures

A **heap** is a specialized tree-based data structure, where each node is associated with an ordinal key. It satisfies two properties:
- _Shape property_: a heap is a _complete tree_ (#REF)
- _Heap property_: the key stored in each node is greater than or equal to (in a max heap) or less than or equal to (in a min heap) the keys of all of its children according to some total order. 

A direct consequence of the heap property is that the root node is always the node with the largest key in max heap or smallest key in a min heap. Furthermore, because the heaps are complete trees, they have height ⌈*log<sub>a</sub>(n)*⌉, where *a* is the tree's branching factor. However, unlike a binary search tree, a heap is not a sorted or fully ordered structure.

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/501px-Max-Heap.svg.png">
</p>
<p align="center">
    <em>Example of a binary max heap</em>
</p>

Priority queues can be implemented using a heap (usually a binary heap), where the priority of each element is represented by its associated key. If the larger key value are defined to correspond to higher priority, then the highest priority element will always be at the root of the max heap. 

Nodes are inserted or removed from heaps by having them "swim up" from the bottom or "sink down" from the top; this "bubbling" approach is reminisent of bubble sort (#REF) (but much more efficient). To add an node, insert it in the last available position in the complete tree structure (at the bottom right); then, if it violates the heap property, recursively swap it with its parent until this is satisfied. To remove a node, replace it with the last (bottom right) node, and then recursively swap it with its larger child (in the case of a max heap) until the heap property is satisfied. See #REF and #REF.

<p align="center">
    <img src="https://www.techiedelight.com/wp-content/uploads/2016/11/Push-min-heap.png">
</p>
<p align="center">
    <img src="https://www.techiedelight.com/wp-content/uploads/2016/11/Pop-min-heap.png">
</p>
<p align="center">
    <em>Inserting (top) amd removing (bottom) from a min heap</em>
</p>

Because a heap is a complete binary tree (#REF), it can be implemented efficiently using an array or vector. The root element is stored at index 0, its children at indices 1 and 2, their children at incides 3, 4, 5, and 6, and so on. In the general case, for a node at position _p_, its children at are positions _2p + 1_ and _2p + 2_; similarly, the parent of a node is found at position _(p - 1) / 2_. See #REF. 

Heaps provide a maximally efficient implementation of a priority queues, allowing elements to be inserted and removed in logarithmic time. They are also used to implement heap sort (#REF), an efficient _O(nlog(n))_ sorting algorithm.

| Operation                        | Runtime        |
|:---------------------------------|:--------------:|
| Access highest-priority element  | _O(1)_         |
| Remove highest-priority element  | _O(log(n))_    |
| Insert element                   | _O(log(n))_    |

## Examples & Problems

* Data Structures:
    * Binary heap implementation of priority queue (#REF)
* Algorithms:
    * Heap sort (#REF)

## References

Sedgewick, Robert, and Kevin Daniel Wayne. _Algorithms_. 4th ed. Upper Saddle River (NJ), NJ: Addison-Wesley, 2015.

Magnum, Lucas. "#SideNotes — Priority Queue — Abstract Data Type and Data Structure." Medium, October 27, 2018. https://medium.com/@lucasmagnum/sidenotes-priority-queue-abstract-data-type-and-data-structure-52b5fcd7b904. 

