# Trees

A **tree** is an abstract data type that models a hierarchical tree structure and consists of a series of **nodes** linked by directed **branches** (or **edges**). Trees are widely used for representing hierarchies and storing data for efficient lookup.

![Tree](https://www.thecrazyprogrammer.com/wp-content/uploads/2019/09/General-Tree-Structure.png)

## General Definition

The elements of a tree are called **nodes**; each stores a value and is connected by directed **branches** (or **edges**) to zero or more successor nodes called **child** nodes; the predecessor of a node is called its **parent** node.

It is most useful and intuitive, to define trees recursively – since this is how the tree data structure and most operations on it are typically implemented. A **tree** can be defined recursively as either:

* (*i*) empty (no nodes), or 
* (*ii*) a **root** node with zero or more subtrees (i.e. its children are themselves the roots of subtrees). 

A tree can also be defined based on the mathematical definition of a tree: a *connected*, *undirected*, *acyclical* graph. Using this definition, we can define the abstract data type as a *rooted*, *directed* *out-tree*: one node is designed as the root node and all edges are directed away from the root. 

Two important results flow from these definitions: every node in tree except for the root node has exactly one parent node; and there is exactly one path from the root node to each node in the tree.

Trees are replete with terminology; many of them are based on analogy with a (physical) tree or a family tree:

* **Child**: a node directly connected to another when moving away from the root (a direct descendent)
* **Parent**: a node directly connected to another when moving towards the root (a direct ancestor)
* **Sibling**: a node with the same parent node
* **Descendant**:  a node connected to another when moving away from the root
* **Anscestor**: a node connected to another when moving towards the root 
* **Leaf** (or **external**): a node with no children
* **Branch** (or **internal**): a node with at least one child
* **Distance**: the number of edges along the path between two nodes
* **Depth**: the distance between a node and the root node
* **Level**: depth + 1
* **Width**: the number of nodes in a level
* **Height**: the number of edges on the longest path between the root and a descendant
* **Breadth**: the number of leaf nodes in a tree

The table below provides an example of these terms in action for the example tree in the image above. This tree has a height of 3 and a breadth of 6; it has five branch nodes (A, B, C, D, G) and six leaf nodes (E, F, J, K, H, I).

| Node          | A (root)                     | G (internal)        | J (leaf)       |
|---------------|:----------------------------:|:-------------------:|:--------------:|
| Children      | B, C, D                      | J, K                | -              |
| Parent        | -                            | C                   | G              |
| Siblings      | -                            | -                   | K              |
| Desendants    | B, C, D, E, F, G, H, I, J, K | J, K                | -              |
| Ancestors     | -                            | C, A                | G, C, A        |
| Depth         | 0                            | 2                   | 3              |
| Level         | 1                            | 3                   | 4              |


## Traversing Trees



## Hoffman Trees

// TODO
// See Foffman & Wolfgang 2006, 449-450
// TODO: implement Huffman tree cnoding / decoding

## Binary Trees

// TODO
// Different terms for binary traversal (pre-,in-post-order)

## Binary Search Tree

// TODO
// Definition

## Heaps and Priority Queues





// Other
## Hoffman Trees

// TODO
// See Foffman & Wolfgang 2006, 449-450
// TODO: implement Huffman tree cnoding / decoding

















## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.
