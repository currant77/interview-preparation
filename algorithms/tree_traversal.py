"""
@file: tree_traversal.py
@author: Taylor Curran
@brief: Implementation of breadth-first and depth-first tree traversal
@version 0.1
@date 2020-06-20

@note Depth-first traversal is implemented recursively (i.e. using the call stack),
while breadth-first traversal is implemented using a queue.

@copyright Copyright (c) 2020
"""

# Imports
import queue as q

# Class declarations
class Node:
    """ Class representing a node in a general tree structure"""

    def __init__(self, data):
        self.data = data
        self.children = []

    def __str__(self):
        return str(self.data)

# Function declarations
def depth_first(root, method):
    """ Performs a recursive depth-first traversal of the given tree and
    calls method(node) on each node in the tree"""

    method(root)

    for child in root.children:
        depth_first(child, method)

    return

def breadth_first(root, method):
    """ Performs a breadth-first traversal (using a queue) of 
    the given tree and calls method(node) on each node in the tree"""

    queue = q.Queue()
    queue.put(root)

    while queue.empty() is not True:
        node = queue.get()
        method(node)
        
        for child in node.children:
            queue.put(child)

    return

print("Beginning tests...")

# Create tree
# From https://www.thecrazyprogrammer.com/wp-content/uploads/2019/09/General-Tree-Structure.png

A = Node("A")
B = Node("B")
C = Node("C")
D = Node("D")
E = Node("E")
F = Node("F")
G = Node("G")
H = Node("H")
I = Node("I")
J = Node("J")
K = Node("K")

A.children = [B,C,D]
B.children = [E,F]
C.children = [G]
D.children = [H,I]
G.children = [J,K]


f = lambda node : list_insert()

print("Depth-first:")
df_list = []
depth_first(A, lambda node : df_list.append(node.data))
print(df_list)

assert df_list == ["A","B","E","F","C","G","J","K","D","H","I"]

print("Breadth-first:")
bf_list = []
breadth_first(A, lambda node : bf_list.append(node.data))
print(bf_list)

assert bf_list == ["A","B","C","D","E","F","G","H","I","J","K"]

print("All tests passed!")