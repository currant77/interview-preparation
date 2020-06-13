# Hash Tables

A **hash table** is a container that uses a **hash function** to find, insert, and remove keys from *buckets* or *slots* in a fixed-size array, usually in linear time. A hash table can be used to to implement an **associative array** (or **map**) or **set**.

## Hashing

A **hash function** maps a key to a fixed-sized **hash code** (usually an `int` or `long`), which then corresponds to an index in the hash table's fixed-size array (a modulo operation by the hash table size is typically used to translate the hash code into a table index).

A hash function must be deterministic: the same key should always yield the same hash code. A _good_ hash code function should be fast to compute and should minimize **collisions** – the frequency with which two different keys correspond to the same hash table index.

Generating good hash code functions is somewhat of an experimental process. There are built-in or easy-to-find implementations for most common data types in most languages, but it may be necessary in some cases to implement or override hash functions for custom data types. For example, it is best practice to always override the corresponding hash functions when overriding equality operators so that the behaviour is consistent (see [here](https://www.geeksforgeeks.org/override-equalsobject-hashcode-method/)). 

## Collision Resolution

Of course, because a hash table maps from a larger (potentially infinite) set (e.g. the set of `string` values), to a smaller (finite) set (the size of the hash table), collisions are bound to happen. There are two main approaches for handling them: **open addressing** and **chaining**. 

### Open Addressing

In **open addressing**, each hash table entry corresponds to a single key. When searching for an key, the hash table entries are examined, starting with the index corresponding to the hash code and following a **probing sequence**, until either the item or an empty slot is found (indicating that the value is not in the table). As a result, open addressing requires dynamic resizing (see below) to ensure that the hash table never fills up completely. As the hash table fills up, performance can also suffer as probe sequences lengthen.

The simplest probing sequence is **linear probing**, where the interval between probes is constant. Linear probing is easy to implement, efficient (because it makes good use of caching), and widely used. However, even with a good hash function, linear probing can lead to clustering, long search chains, and reduced performance as the hash table nears capacity (see [here](https://upload.wikimedia.org/wikipedia/commons/1/1c/Hash_table_average_insertion_time.png)). Common alternatives include **quadratic hashing** (which probes _k_, _k_ + 1, _k_ + 4, _k_ + 9,..., for hashcode _k_) and **double hashing**, where the interval between probes is computed by a second hash function.

Extra care also needs to be taken when removing an item from a hash table implemented with open addressing – it cannot simply be removed from the table, since that might break the search chain leading to another key in the table. This can be solved by inserting a dummy value or by shifting all the keys that appear after it in the search chain.

### Chaining

In **chaining** (or **bucket hashing**), each table element references a list (a **bucket**) that contains all the items that hash to that table index. Finding an element is simply a matter of searching the list at the index given by the hash function. Compared to open addressing, chaining does only requires searching elements that map to the same index (in open addressing, search chains for different indices can overlap) and can store more elements than the size of the hash table. As demonstrated in the [link](https://upload.wikimedia.org/wikipedia/commons/1/1c/Hash_table_average_insertion_time.png) above, the performance of a hash table implemented using chaining also tends to deteriorate less rapidly at higher load factors.

## Dynamic Resizing

Regardless of whether addressing or chaining is used to address collision, performance will suffer as the hash table fills up; this can be fixed by dynamically resizing to a larger table. This is done by allocating a new table (usually twice as large) and rehashing all the keys into the new table (unlike data structures like an array list, it is not sufficiently to simple copy all of the keys over to the new table).

## Performance

The main advantage of a hash table is speed: a good hash function and hash table implementation they can generally achieve average constant-time lookup, insertion, and deletion. However, hash functions can be less space-efficient than alternatives like a binary search trees (this might be a particular consideration if the key objects take up a lot of memory), can become very inefficient if there are many collisions, and can have poor worst-case performance (dynamic resizing is a linear operation).

|             | Average-case | Worst-case |
|-------------|:------------:|:----------:|
| Search      | _O(1)_       | _O(n)      |
| Insertion   | _O(1)_       | _O(n)      |
| Deletion    | _O(1)_       | _O(n)      |
|

## Problems and Implementations

* [Hash Set](HashSet.h) provides a generic implementation of [ISet](ISet.h) that allows the user to override the default hash function (`std::hash<T>`) and equality comparison (`std::equal_to<T>`) (see [here](https://thispointer.com/using-unordered_set-with-custom-hasher-and-comparision-function/) for another example of how to write custom hash and comparison functions). The [test file](tst_HashSet.cpp) provides an example of this for `std::string` and a custom struct; it also provides examples of a string hash function (Koffman & Wolfgang 2006, 538) and a hash function for a custom class based on `boost:hash_combine`. 
* TODO: implementation of `Map` interface and `HashMap` implementation (using open addressing)
* TODO: at least one problem from _Cracking the Coding Interview_

## Additional Notes

* One way to try to reduce collisions is to use a prime number-size hash table; this is discussed at length [here](https://stackoverflow.com/questions/1145217/why-should-hash-functions-use-a-prime-number-modulus).
* Quadratic probing can get stuck in infinite loops or fail to probe all the table indices; but it is possible to show that this will never occur if the table size is a prime number and it is no more than half full (Koffman & Wolfgang 2006, 538).

## References

Cormen, Thomas H., Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. _Introduction to Algorithms_. Cambridge, MA: MIT Press, 2009.

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.