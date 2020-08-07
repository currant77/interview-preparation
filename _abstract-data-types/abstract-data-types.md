# Abstract Data Types

## Definition

An **abstract data type** (ADT) is a _mathematical model_ for a data type that is characterized by the operations that can be performed on it; it is an _abstraction_ that does not depend on how its underlying data is stored or how its operations are implemented.

Two common examples of abstract data types are strings and lists: strings (#REF) support operations such as concatenating them together or extracting subtrings, while lists (#REF) provide methods that return their size or add value to the list. 

Abstract data types are implemented using data structures (#REF), which describe ways of organizing and storing data. There may be more than one data structure that can be used to implement an abstract data type, each with its own advantages and disadvantages; one data structure can also be used to implement many different abstract data types. For example, the [list](#REF) abstract data type can be implemented using either an [array](#REF) or a series of [linked nodes](#REF), while an array can also be used to efficiently implement a [string](#REF) or [stack](#REF).

## Properties

Abstract data types can be classified as either mutable or immutable. Objects of a **mutable** data types can be modified such that the results of other operations return different results, while **immutable** data types cannot be modified once they are created. For example, lists (#REF) are usually mutable because they allow users to add and remove values from the list; but strings (#REF) are often immutable: operations on strings provude new strings rather than modifying existing strings. 

We can also classify the operations supported by an abstract data types into four categories:

* **Creators** create new objects of the data type from arguments other than objects of the type being constructued (e.g. creating a string from a array of characters).
* **Producers** create new objects of the data type from old objects of the type (e.g. creating a new string by concatenating two other strings).
* **Observers** take objects of the abstract type and return objects of a different type without modifying the object (e.g. returing the length of string).
* **Mutators** change objects (e.g. adding a value to the end of a list).

Many abstract data types possess **invariants**: properties that will be true for the entire lifetime of objects of the data type. For example, a self-balancing binary search tree (#REF) always has height ⌊_log(n)_⌋. Immutability is a common invariant for many abstract data types – once an object is created, it is guaranteed never to change. To implement invariance, creaters and producers must _establish_ the invariant (make sure it is always true of the initial state of the object) and mutators and observers must _preserve_ the invariant (make sure it is always true at the end of the operation).

## Containers

A **collection** or **container** is an abstract data type, like a [tree](#REF) or [set](#REF), that groups to together _data items_ (or _elements_) that have some shared significance to the problem being solved. Containers usually contain a variable number of data items – they are mutable abstract data types that allow data items to be added or removed from the collection.

Most common abstract data types are containers (see `Java`'s [Collection](https://docs.oracle.com/javase/8/docs/api/java/util/Collection.html) interface, for example). 

Most containers (**object containers**) just store data items, but some – called **associative containers** – store a collection of data items (_keys_) that are each associated with a _value_ to form a _key-value pair_. Associative containers correspond to the mathematical concept of a _map_: they provide map from every key in the collection to the associated value. Any object container can be made into an associative container; the [map](#REF) and [multimap](#REF) associative containers, for example, correspond to the [set](#REF) and [multiset](#REF) object containers.

While the specific operations supported by each container differ, there are a number of types of operations common to most containers:

* `size()`: determine the number of data items in the collection
* `insert()`: add data items to the collection
* `remove()`: remove data items from the collection
* `contains()`: determine if a collections contains a given data item

Many collections also provide operations that support _traversing_ their data items: accessing each data item in the collection one by one. The ways in which the data items can traversed vary between abstract data types and their concrete implementations, but are generally based on the relations between the data items in the collections (see next paragraph). The concept of traversing the elements of a collection is encapsulated by the [iterator](#REF) abstract data type.

Differences between collections can be defined by the relations that exist between the data items that they contain. For example, there is are linear relations between the data items in a [list](#REF), hierarchical (parent-child) relations between elements in a [tree](#REF), and no relation between data items stored in a [set](#REF). These relations can defined either _explicitly_ by the program or _implictly_ by the data items themselves; for example, the data items in [queue](#REF) are defined explicitly by the order in which they are inserted into the queue, while those in a [priority queue](#REF) are defined implictly by some measure of priority. 

### No Relation

The simplest containers are those in which there is no relation, explicit or implicit, between the data items. In this case, operations on the container are just those applicable to a general container: determining the size of the container, checking if it contains a given element, and inserting or removing elements. 

Examples:
* [Set](#REF)
* [Map](#REF)
* [Multiset](#REF)
* [Multimap](#REF)











A **linear collection**, such as a [list](#REF) or [stack](#REF) defines a linear ordering between the data items in the collection, while an **associative collection** associates

## Designing Abstract Data Types

A well-designed abstract data type should follow these rules of thumb (from Amarasinghe et al, 2014):

* It should implement _a few simple operations_ that can be combined in powerful ways, rather than many complex operations.
* Operations should have _coherent behaviour_ – not litany of special cases (for example, a list should behave the same whether it holds integers or strings).
* While the set of operations provided by the data type should be as small as possible, it needs to be _adequate_ for the needs of typical users.
* The abstract data type _should not mix generic and domain specific features_.
* It should be _representation independent_: it should not depend on how the underlying data is stored (and should not expose this representation through any of its oeprations).

## Common Abstract Data Types

There are many common abstract data types that are used consistently in nearly every domain and are often defined or implemented by languages. For example, the `C++` Standard Template Library (STL) provides implementations of the [list](http://www.cplusplus.com/reference/list/list/), [stack](http://www.cplusplus.com/reference/stack/stack/) and [map](https://en.cppreference.com/w/cpp/container/map) abstract data types; `Java` provides both abstract data type interfaces (e.g. [List](https://docs.oracle.com/javase/tutorial/collections/interfaces/list.html)) and concrete implementations (e.g. [LinkedList](https://docs.oracle.com/javase/7/docs/api/java/util/LinkedList.html) and [ArrayList](https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html)); and `Python` provides direct support for lists, strings, and dictionaries (maps).

* [String](#REF)
* [Iterator](#REF)
* [Tree](#REF)
* [Graph](#REF)
* [Associative collections](#REF):
    * [Set](#REF)
    * [Map](#REF)
* [Linear colletions](#REF):
    * [List](#REF)
    * [Stack](#REF)
    * [Queue](#REF)
    * [Deque](#REF)
    * [Priority Queue](#REF)


## References

"Abstract Data Types." Algorithms and Data Structures. Department of Electrincal and Computer Engineering, University of Waterloo. Accessed August 7, 2020. https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/.

Amarasinghe, Saman, Saman Amarasinghe, Adam Chlipala, Srini Devadas, Michael Ernst, Max Goldman, John Guttag, Daniel Jackson, et al. _Reading 8: Abstract Data Types_. Massachusetts Institue of Technology: 6.005 – Software Construction, 2014. http://web.mit.edu/6.005/www/fa14/classes/08-abstract-data-types/. 

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.







