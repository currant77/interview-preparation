"""
file: cci_1-8
author: Taylor Curran
brief: Solution to problem 1.8 from Cracking the Coding Interview
version 0.1
date 2020-05-20

note: McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

Copyright (c) 2020
"""

""" Problem 1.8: "Zero Matrix: Write an algorithm that if an element 
in an m x n matrix is zero, its entire row and column is set to zero" 
"""

""" Approach: Iterate through the matrix. If any value is equal to zero,
store its row and column number in two sets. When done, iterate through
both sets and set the corresponding row or column to zero
"""

# Imports
import numpy as np

def set_zeros(array):
    """ For all zero values in the two-dimensional array, sets the 
    corresponding row and column to zeros """

    if array.size == 0:
        return array

    # Add all row and col indexes with zero entries to sets
    rows = set()
    cols = set()

    m,n = array.shape

    for row in range(m):
        for col in range(n):
            if array[row][col] == 0:
                rows.add(row)
                cols.add(col)

    # Set all rows and columns to zero
    for row in rows:
        array[row,:] = np.zeros((1,n))


    for col in cols:
        array[:,col] = np.zeros((1,m))

    return array

print("Beginning tests...")

assert np.array_equal(
    np.array([[1]]), 
    set_zeros(np.array([[1]])))

assert np.array_equal(
    np.array([[0]]), 
    set_zeros(np.array([[0]])))

assert np.array_equal(
    np.array([[0,0]]), 
    set_zeros(np.array([[1,0]])))

assert np.array_equal(
    np.array([[0,0],[0,0]]), 
    set_zeros(np.array([[1,0],[1,0]])))

assert np.array_equal(
    np.array([[0,0,0], [0,4,0],[0,0,0]]), 
    set_zeros(np.array([[1,2,0],[3,4,5],[0,6,7]])))

print("All tests passed!")