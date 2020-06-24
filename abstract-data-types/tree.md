# Trees

## Abstract Data Type

A **tree** is an abstract data type that models a hierarchical tree structure and consists of a series of **nodes** linked by directed **branches** (or **edges**) from **parent** nodes to **child** nodes. Trees are widely used for representing hierarchies and storing data for efficient lookup.

![Tree](https://www.thecrazyprogrammer.com/wp-content/uploads/2019/09/General-Tree-Structure.png)

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
* **Branching factor**: the number of children for a given node

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

The tree abstract data type is incredibly flexible and is used in a wide range of applications – and so there are numerous specializations of this abstract data types in common use; some of these include:
 
* Binary search trees (#REF)
* Red-black trees
* Tries (#REF)
* Binary heaps (#REF)

As a result, there is not a set of basic operations that all trees will tend to implement (unlike other abstract data types like queues or lists). However, trees will generally provide methods for adding and removing nodes and traversing the elements of the tree (see below).

## Data Structures

Different types of tree may be best implemented using different data structures. For example, despite their underlying tree structure, binary heaps (#REF) are typically implemented using an array. 

Nonetheless, tree are often implemented using node object that holds some data and references to child nodes. These are simple and easy to implement (see below). Nodes can also store information such as references to parent or sibling nodes.

````
template<class T>
struct Tree_Node
{
    T& value;    
    list<Tree_Node*> children;
}
````

## Algorithms

While the data stuctures used to store trees tend to be relatively simple, the algorithms that operate on them are not necessarily so. This section discussed algorithms that are general to all tree structures (such as how to traverse its nodes); algorithms for specific types of trees (e.g. red-black trees) are discussed on the relevant pages

### Traversal

Tree **traveral** is the fundamental process of visiting each node in a tree exactly once; it is analogous to iterating over the elements in a linear data type like a list. Trees can be traversed in either **breadth-first** or **depth-first** order (same as graphs (#REF)).

#### Breadth-First Traversal

**Breadth-first** traversal is also known as **level-order** traversal because it proceeds level by level, starting with the root node; it examines every node at each successive level before proceeding to the next level. Depth-first traversal uses a queue: when we visited each node, we push its child nodes onto the queue.

````
function breadth_first(root):

    let Q be a queue
    Q.enqueue(root)

    while Q is not empty do:

        node := Q.dequeue()

        // ... Do something to node ...

        for each child c of node:
            Q.enqueue(node)

````

A breadth-first traversal visits each node exactly once, so its runtime is linear over the number of nodes in the tree. Its space complexity is proportional to the breadth of the tree (the total number of leaf node); it is _O(n)_ in the worst case, where every leaf node is a child of the root node. For a tree with depth _d_ and maximum branching factor _b_, the space complexity of breadth-first traversal can also be expressed as _O(b<sup>d</sup>)_

#### Depth-First Traversal

Starting at the root, **depth-first** traversal proceeds by fully searching each subtree before **backtracking** to search each remaining subtrees in sequence; it traverses as far along each branch as possible (until it reaches a leaf) before backtracking. Whereas breadth-first search uses a queue data structure, depth-first search leans on a stack. This can either by implemented by using a stack directly or by taking advantange of recursion to use the call stack; examples of both are given below.

````
function depth_first_stack(root):
    
    let S be a stack
    S.push(root)

    while S is not empty do:

        node := S.pop()

        // ... Do something to node ...

        for each child c of node:
            S.push(c)
````
````
function depth_first_recursive(root):

    // ... Do something to node ...

    for each child c of node:
        depth_first_recusrive(c)
````

**Depth-first** traversals differ in whether they examine a node or its children first; in the case of binary search tree (#REF), we differentiate between pre-order, in-order, or post-order depth-first traversals.

Like breath-first traversal, the runtime of depth-first search is linear over the total number of nodes in the tree. Unlike breath-first traversal, the space complexity of depth-first traversal it is proportional to the depth of the tree (the length of the longest path between a leaf node and the root node); but it is also _O(n)_ in the worst case, where every node has exactly one child. 

#### Comparison

Both breadth- and depth-first traversals have _O(n)_ runtime, but their space complexities differ. Breadth-first traversals is more efficient on deeper trees with smaller branching factors, while depth-first traversals is more efficient on shallow trees with higher branching factors. 

The table below summarizes some of the key differences between these two approaches to traversing a tree.

|                           | Breadth-first           | Depth-first           |
|:--------------------------|:-----------------------:|:---------------------:|
| Time complexity           | _O(n)_                  | _O(n)_                |
| Space complexity          | _O(n)_ / _O(bd)_        | _O(d)_                |
| Traversal order           | A→B→C→D→E...            | A→B→E→F→C...          |
| Underlying data structure | Queue                   | Stack                 |

## Examples and Problems

* Breadth-first traversal Python (#REF)
* Depth-first traversal Python (#REF)

## References

Koffman, Elliot B., and Paul A. T. Wolfgang. _Objects, Abstraction, Data Structures and Design Using C++_. Hoboken, NJ: John Wiley &amp; Sons, 2006.

Joshi, Vaidehi. _Breaking Down Breadth-First Search_. Medium.com, 2017. https://medium.com/basecs/breaking-down-breadth-first-search-cebe696709d9. 

Black, Paul E. "tree" in _Dictionary of Algorithms and Data Structures_. National Institute of Standards and Technology, 2017. https://xlinux.nist.gov/dads/HTML/tree.html. 