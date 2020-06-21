# Trees

A **tree** is an abstract data type that models a hierarchical tree structure and consists of a series of **nodes** linked by directed **branches** (or **edges**) from **parent** nodes to **child** nodes. Trees are widely used for representing hierarchies and storing data for efficient lookup.

![Tree](https://www.thecrazyprogrammer.com/wp-content/uploads/2019/09/General-Tree-Structure.png)

## Abstract Data Type

The elements of a tree are called **nodes**; each stores a value and is connected by directed **branches** (or **edges**) to zero or more successor nodes called **child** nodes; the predecessor of a node is called its **parent** node.

There are many ways to define trees, but it is most useful and intuitive (at least in my opinion) to define trees recursively – since this is how the tree data structure and most operations on it are typically implemented. A **tree** can be defined recursively as either:

* (i) empty (no nodes), or 
* (ii) a **root** node *r* with zero or more subtrees whose roots are child nodes of *r*

A tree can also be defined based on the mathematical definition of a tree: a *connected*, *undirected*, *acyclical* graph. Using this definition, we can define the abstract data type as a *rooted*, *directed* *out-tree*: one node is designed as the root node and all edges are directed away from the root. 

Two important results flow from these definitions: every node in tree except for the root node has exactly one parent node; and there is exactly one path from the root node to each node in the tree (because there are no cycles).

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

| Node          | A (*root node*)              | G (*internal node*) | J (*leaf node*)|
|---------------|:----------------------------:|:-------------------:|:--------------:|
| Children      | B, C, D                      | J, K                | -              |
| Parent        | -                            | C                   | G              |
| Siblings      | -                            | -                   | K              |
| Desendants    | B, C, D, E, F, G, H, I, J, K | J, K                | -              |
| Ancestors     | -                            | C, A                | G, C, A        |
| Depth         | 0                            | 2                   | 3              |
| Level         | 1                            | 3                   | 4              |

The tree abstract data type is incredibly flexible and is used in a wide range of applications – and so there are numerous specializations in common use (see binary search trees (#REF), tries (#REF), red-black trees (#REF), and binary heaps (#REF)). As a result, there is not a set of basic operations that all trees will tend to implement (unlike other abstract data types like queues or lists). However, trees will generally provide methods for adding and removing nodes and traversing the elements of the tree (see below).

## Implementations

As discussed above, the wide variety of different types of trees makes any generlizations about tree data structures impossible. For example, despite their underlying tree structure, binary heaps (#REF) are typically implemented using an array. 

Nonetheless, a general tree data structure is relatively easy to implement: it can be as simple as an object that holds a value and a collection of child nodes (see below). The more important and difficult features of trees are their accompanying algorithms. Some of these are general (e.g. how to traverse a tree) and are discussed in the section below; others are specific to a given type of tree (e.g. balancing red-black trees). 

## Algorithms

### Traversal

// TODO

## Problems and Examples

// TODO

dfs_iterator
bfs_iterator

insert_child(pos, ref)
insert_after(pos, ref)
insert_before(pos, ref)
remove(pos, ref)

parent()
children()

empty();
num_nodes();



## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.
