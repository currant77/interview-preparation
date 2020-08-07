# The Set and Map Abstract Data Types

## Definitions

### Set

A **set** is an abstract data type representing an unordered collection of _unique_ elements; it corresponds to the mathematical concept of a _finite set_. 

Sets generally support five basic operations:
* `size()`: determining the number of elements in the set
* `insert()`: adding an element to the set
* `remove()`: removing an element from the set
* `contains()`: determining if the set contains an element (if the element is a _member_ of the set)
* `clear()`: removing all elements from the set

More sophisticated implementations may support operations that return an enumeration of the elements in the set, provide an iterator to the collection or construct a set containg the elements of a collection. Sets can also support set-thoretical operations such as the union or intersection between two sets.

### Map

A **map**, **dictionary**, or **associative array** is an abstract data type representing of an unordered [associative collection](#REF) of key-value pairs, where each key in the collection is unique (values can be repeated). It is consistent with the mathematical concept of a _map_ or _function_, where each key in its domain maps to a value in its codomain (or range). 

Most collections do not have different names for the corresponding object and assocative containers; however, in this case the set ADT (object container) corresponds to the map ADT (associative container).

Sets generally support six basic operations:
* `size()`: determining the number of key-value pairs in the map
* `get()`: accessing the value associated with a key in the map
* `insert()`: adding a key-value pair to the set
* `remove()`: removing an key and its corresponding value from the set
* `contains()`: determining if the map contains a key
* `clear()`: removing all elements from the set

## Data Structures

Sets and maps are typically implemented using either a self-balancing [binary search tree](#REF) or a [hash table](#REF). Using a binary search tree requires that the elements have a defined order, while a hash table only needs to compare elements for equality but requires a defined hash function. 

With a good hash function (such that worst-case performance rarely occurs), a hash table achieves much better performance than a binary search tree. However, binary search tree are able to support iterating over the elements of the set or map in order, which can be useful in some application. For example, the `C++` Standard Template Library (STL) differentiated between the unordered sets and maps ([`std::unordered_set`](https://en.cppreference.com/w/cpp/container/unordered_set) and [`std::unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)), which are implemented using a hash table, and ordered sets and maps ([`std::set`](https://en.cppreference.com/w/cpp/container/set) and [`std::map`](https://en.cppreference.com/w/cpp/container/map)), which use a [red-black tree](#REF).

| Data structres: Sets & Maps       |                                  | Average-case | Worst-case   |
|-----------------------------------|----------------------------------|:------------:|:------------:|
| Self-Balancing Binary Search Tree | Search (`contains()`, `get()`)   | _O(log(n))_  | _O(log(n))_  |
|                                   | Insertion (`insert()`)           | _O(log(n))_  | _O(log(n))_  |
|                                   | Deletion (`remove()`)            | _O(log(n))_  | _O(log(n))_  |
| Hash table                        | Search (`contains()`, `get()`)   | _O(1)_       | _O(n)_       |
|                                   | Insertion (`insert()`)           | _O(1)_       | _O(n)_       |
|                                   | Deletion (`remove()`)            | _O(1)_       | _O(n)_       |






[ISet](ISet.h) and [IMap](IMap.h) contain general set and map interfaces, respectively. [HashSet](HashSet.h) provides an implementation of the set interface using a hash table with chaining; [HashMap](HashMap.h) and [RedBlackMap](RedBlackMap.h) are implementations of the map interface using a hash table with open addressing and a red-black tree, respectively. Tests for these classes can be found in [tst_HashSet.cpp](tst_HashSet.cpp), [tst_HashMap.cpp](tst_HashMap.cpp), and [tst_RedBlackMap.cpp](tst_RedBlackMap.cpp).

## Algorithms

<TODO>

## Problems & Examples

* Interfaces:
    * [Set](#REF)
    * [Map](#REF)
* Data structures:
    * [HashTableSet](#REF)
    * [RedBlackTreeMap](#REF)
* Algorithms:
    * <TODO>
* Problems:
    * <TODO>

## References

"Abstract Set/Map / Set/Map ADT." Algorithms and Data Structures. Department of Electrincal and Computer Engineering, University of Waterloo. Accessed August 7, 2020. https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/No_relation/Set/.