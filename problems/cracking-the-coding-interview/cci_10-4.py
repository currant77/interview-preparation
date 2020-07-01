"""
@file: cci_10-4.py
@author: Taylor Curran
@brief: Solution to problem 10.4 from Cracking the Coding Interview
@version 0.1
@date 2020-06-30

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
Problem 10.4: "Sorted Search, No Size. Youare given an array-like data structure 'Listy' 
which lacks a size method. Id does, however, have an elementAt() method that returns the 
element at index i in O(1) time. If i is beyond the bounds of the data structure, it returns 
-1. (For this reason, the data structure only supports positive integers.) Given a 'Listy'
which contains sorted, positive integers, find the index at which an element x occurs. If x
occurs multiple times, you may return any index." 
"""

""" 
Approach:
(1) Use a 'quadratic bounding' approach, starting with index 1. If the search value is 
greater than the value at that index, double the index. If it is less or past the end of
the list, take half the distance to the previous index.

"""

import math as math

class Listy:
    """ Class that takes a list positive integers and sorts it; 
    elementAt() returns the element at the given index if it exists 
    in the list, other it returns -1. """
    
    def __init__(self, list):
        self.list = list
        self.list.sort()

    def elementAt(self, i):
        if i >= 0 and i < len(self.list):
            return self.list[i]
        else:
             return -1

def find_in_listy(listy, i):
    """ Returns the index in listy that contains the value i. If
    i occurs multiple times in the list, returns one of the 
    corresponding indices. Returns -1 if the value is not in the 
    listy. """

    return helper_recursive(listy, i, 0, 1)

def helper_recursive(listy, i, start, end):

    # (1) Base case: one value
    if start == end:
        if listy.elementAt(end) == i:
            return end
        else: return -1

    val = listy.elementAt(end)

    # (2) Search before end
    if val == -1 or i < val:
        return helper_recursive(listy, i, start, math.floor((start + end) / 2))

    # (3) Search after end
    elif i > val:
        return helper_recursive(listy, i, end, end * 2)

    # (4) Found value
    else: return end        

print("Beginning tests...")

l = Listy([1, 1, 7, 12, 15, 19, 22, 22, 24, 257])

assert find_in_listy(Listy([]), 12) == -1
assert find_in_listy(l, 1) in [0,1]
assert find_in_listy(l, 2) == -1
assert find_in_listy(l, 7) == 2
assert find_in_listy(l, 12) == 3
assert find_in_listy(l, 15) == 4
assert find_in_listy(l, 18) == -1
assert find_in_listy(l, 19) == 5
assert find_in_listy(l, 22) in [6,7]
assert find_in_listy(l, 24) == 8
assert find_in_listy(l, 257) == 9
assert find_in_listy(l, 300) == -1

print("All tests passed!")