# Hash Maps

A **hash map** (or **hash table**) is an implementation of an **associative array** (or **map**) that uses a **hash function** to sort values into into *buckets* or *slots* in an array. 

## Hashing

A **hash function** maps a key value to a fixed-sized **hash code** (usually an `int` or `long`), which corresponds to an index in a fixed-size array called a **hash table**. 

A hash function must be deterministic: the same key should always yield the same hash code. Futher, a good hash code function should be fast to compute and should minimize **collisions** – the frequency with which two different keys correspond to the same hash code.

Generating good hash code function is somewhat of an experimental process. There are built-in or easy to find implementations for most common data types in most languages, but it may be necessary in some cases to implement or override hash functions for custom data types. For example, it is best practice to always override the corresponding hash functions when overriding equality operators so that the behaviour is consistent.

TODO: add example.

TODO: implementation for `string`

TODO: implementation for custom class

## Collision Resolution

### Open Addressing

### Chaining

## Dynamic Resizing

## Performance