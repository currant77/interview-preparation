# Sets and Maps

## Sets

A **set** is an abstract data type consisting of a unordered collection of unique keys; it is consistent with the mathematical concept of a finite set. A **static set** (or **frozen set**) does not change after it has been constructed and only allows query operations on its elements; a **dynamic set** (or **mutable set**) also allows the insertion and removal of keys from the set.

A (dynamic) set supports four basic operations: `insert(v)`, `remove(v)`, `size()`, and `contains(v)`. More sophisticated implementations may support operations that return an enumeration of the keys in the set, provide an iterator to the collection or construct a set containg the elements of a collection. Sets can also support set-thoretical operations such as the union or intersection between two sets.

## Maps

A **map**, **dictionary**, or **associative array** is an abstract data type consisting of an unordered collection of key-value pairs, where each key in the collection is unique (values can be repeated). It is consistent with the mathematical concept of a function, where each key in its domain maps to a value in its codomain (or range). Like sets, maps can be either static or dynamic. 

A (dynamic) map also supports four basic operations: `insert(k,v)`, `remove(k)`, `size()`, and `lookup(k)`. Others operations such as iterating over the map's key-value pairs or updating the value corresponding to an existing key are commonly supported.

## Implementations

Sets and maps are typically implemented using either a self-balancing binary search tree or a hash table. Using a search tree requires that the keys have a defined order and allows the keys to be traversed in order. On the other hand, a hash table only needs to compare keys for equality but requires a defined hash function. With a good hash function, a hash table achieves much better average performance but worse worst-case performance (see table below). The C++ Standard Library differentiates between `std::set` and `std::map`, which are ordered collections implemented as red-black trees, and `std::unordered_set` and `std::unordered_map`, which are implemented as hash tables.

|                    |                       | Average-case | Worst-case   |
|--------------------|-----------------------|:------------:|:------------:|
| Hash Table         | Search                | _O(log(n))_  | _O(log(n))_  |
|                    | Insertion             | _O(log(n))_  | _O(log(n))_  |
|                    | Deletion              | _O(log(n))_  | _O(log(n))_  |
| Self-Balancing BST | Search                | _O(1)_       | _O(n)_       |
|                    | Insertion             | _O(1)_       | _O(n)_       |
|                    | Deletion              | _O(1)_       | _O(n)_       |

[ISet](ISet.h) and [IMap](IMap.h) contain general set and map interfaces, respectively. [HashSet](HashSet.h) provides an implementation of the set interface using a hash table with chaining; [HashMap](HashMap.h) and [RedBlackMap](RedBlackMap.h) are implementations of the map interface using a hash table with open addressing and a red-black tree, respectively. Tests for these classes can be found in [tst_HashSet.cpp](tst_HashSet.cpp), [tst_HashMap.cpp](tst_HashMap.cpp), and [tst_RedBlackMap.cpp](tst_RedBlackMap.cpp).

TODO: what is also in the tests (short description)

TODO: additional CTCI problems with these (preferably one with Python).

## References 

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

Chumbley, Alex, Snehal Shekatkar, Kirk Brunson, and Jimin Khim. “Associative Arrays.” Accessed June 13, 2020. https://brilliant.org/wiki/associative-arrays/.

Chumbley, Alex, Christopher Williams, and Raül Pérez. “Sets (ADT).” Accessed June 13, 2020. https://brilliant.org/wiki/sets-adt/.







