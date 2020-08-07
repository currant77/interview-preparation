# Abstract Data Types

## Definition

An **abstract data type** (ADT) is a _mathematical model_ for a data type that is characterized by the operations that can be performed on it; it is an _abstraction_ that does not depend on how its underlying data is stored or how its operations are implemented.

Two common examples of abstract data types are strings and lists: strings (#REF) support operations such as concatenating them together or extracting subtrings, while lists (#REF) provide methods that return their size or add value to the list. 

Abstract data types are implemented using data structures (#REF), which describe ways of organizing and storing data. There may be more than one data structure that can be used to implement an abstract data type, each with its own advantages and disadvantages; one data structure can also be used to implement many different abstract data types. For example, the [list](#REF) abstract data type can be implemented using either an [array](#REF) or a series of [linked nodes](#REF), while an array can also be used to efficiently implement a [string](#REF) or [stack](#REF).

Many programming languages provide built-in implementations of common abstract data types. For example, the `C++` Standard Template Library (STL) provides implementations of the [list](http://www.cplusplus.com/reference/list/list/), [stack](http://www.cplusplus.com/reference/stack/stack/) and [map](https://en.cppreference.com/w/cpp/container/map) abstract data types; `Java` provides both abstract data type interfaces (e.g. [List](https://docs.oracle.com/javase/tutorial/collections/interfaces/list.html)) and concrete implementations (e.g. [LinkedList](https://docs.oracle.com/javase/7/docs/api/java/util/LinkedList.html) and [ArrayList](https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html)); and `Python` provides direct support for lists, strings, and dictionaries (maps).

## Features

Abstract data types can be classified as either mutable or immutable. Objects of a **mutable** data types can be modified such that the results of other operations return different results, while **immutable** data types cannot be modified once they are created. For example, lists (#REF) are usually mutable because they allow users to add and remove values from the list; but strings (#REF) are often immutable: operations on strings provude new strings rather than modifying existing strings. 

We can also classify the operations supported by an abstract data types into four categories:

* **Creators** create new objects of the data type from arguments other than objects of the type being constructued (e.g. creating a string from a array of characters).
* **Producers** create new objects of the data type from old objects of the type (e.g. creating a new string by concatenating two other strings).
* **Observers** take objects of the abstract type and return objects of a different type without modifying the object (e.g. returing the length of string).
* **Mutators** change objects (e.g. adding a value to the end of a list).

Many abstract data types possess **invariants**: properties that will be true for the entire lifetime of objects of the data type. For example, a self-balancing binary search tree (#REF) always has height ⌊_log(n)_⌋. Immutability is a common invariant for many abstract data types – once an object is created, it is guaranteed never to change. To implement invariance, creaters and producers must _establish_ the invariant (make sure it is always true of the initial state of the object) and mutators and observers must _preserve_ the invariant (make sure it is always true at the end of the operation).

## Designing Abstract Data Types

A well-designed abstract data type should follow these rules of thumb (from Amarasinghe et al, 2014):

* It should implement _a few simple operations_ that can be combined in powerful ways, rather than many complex operations.
* Operations should have _coherent behaviour_ – not litany of special cases (for example, a list should behave the same whether it holds integers or strings).
* While the set of operations provided by the data type should be as small as possible, it needs to be _adequate_ for the needs of typical users.
* The abstract data type _should not mix generic and domain specific features_.
* It should be _representation independent_: it should not depend on how the underlying data is stored (and should not expose this representation through any of its oeprations).

## Common Abstract Data Types

There are many common abstract data types that are used consistently in nearly every domain and are often defined or implemented by languages:

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

Amarasinghe, Saman, Saman Amarasinghe, Adam Chlipala, Srini Devadas, Michael Ernst, Max Goldman, John Guttag, Daniel Jackson, et al. _Reading 8: Abstract Data Types_. Massachusetts Institue of Technology: 6.005 – Software Construction, 2014. http://web.mit.edu/6.005/www/fa14/classes/08-abstract-data-types/. 

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.