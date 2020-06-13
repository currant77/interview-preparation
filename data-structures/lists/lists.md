A **list** is a dynamic, countable collection of ordered items, where the same or equal items may occur more than once. Typical list implementations allow iteration over the list items by index, the addition and removal of an item at any list position (index), and an operation that returns the number of items in the list. Lists are commonly implemented using one of the following two concrete data structures:

* An **array list** or **dynamic array** (a *vector* in C++) stores the items contiguously at the start of a fixed-size static array; the remaining positions towards the end of the array remain unused. As items are added to the array, these positions are filled. When the array is full, a new, larger array is created, and the items are copied over.

* A **linked list** (simply a *list* in C++) consists of a series of **nodes**; each node holds the corresponding list item and a reference to one or two other nodes. The list itself only maintains a reference to the first (head) and possibly the last (tail) nodes in the sequence. In a **singly linked list**, each node only stores a reference to the next node; in a **doubly linked-list**, each node holds a reference to both the next and the previous nodes.

The principal benefit of a linked list is that items can be added or removed without reallocating or reorganizing the entire data structure because the nodes do not need to be stored contiguously in memory. However, array lists provide more efficient random access, since accessing an arbitrary index in a linked list required iterating through the nodes sequentially until the desired node is reached.

[Why you should avoid Linked Lists](https://www.youtube.com/watch?v=YQs6IC-vgmo) by Bjarne Stroustrup, the creator of C++, explains why array lists often achieve better performance than linked lists and use memory more efficiently, even if both perform linear search: linked lists require significantly more memory to store pointers between nodes and their unpredictable memory access (because the nodes are not stored sequentially) maximize cache misses. In addition, while inserting and deleting items from an array list involves moving over a large number of items within the array, this is an operation that modern caches perform extremely efficiently.

[IList.h](1_data_structures\1_sequence_containers/1_lists/IList.h) provides a simple C++ list interface, with methods for accesing items by index, adding and removing items, and determining the number of items in the list. [ArrayList.h](1_data_structures\1_sequence_containers/1_lists/ArrayList.h) and [LinkedList.h](1_data_structures\1_sequence_containers/1_lists/LinkedList.h) provide array list and a doubly linked list implementations of the interface, respectively. Tests for both implementations are provided in [tst_IList.cpp](1_data_structures\1_sequence_containers/1_lists/tst_IList.cpp).


|  *Performance: Array List vs Linked List*     | Array List      | Linked List                 |
| :-------------------------------------------- | :-------------: | :-------------------------: |
| Random Access                                 | O(1)            | O(n)                        |
| Insertion / removal at end                    | O(1)*           | O(1) (with tail reference)  |
| General insertion / removal during iteration  | O(n)            | O(1)                        |
| General insertion / removal by index          | O(n)            | O(n)                        |

\* When the array is full, all the contents of the array need to be copied over to a new, larger array, with takes O(n). However, this happens infrequently enough that the amortized runtime is still O(1). See *Cracking the Coding Interview*, p. 89, for further discussion.

**TODO**: expand interface and implementation to include support to C++ iterators, equality comparison, other constructors, operator overloads...