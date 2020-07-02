"""
@file: cci_10-9.py
@author: Taylor Curran
@brief: Solution to problem 10.9 from Cracking the Coding Interview
@version 0.1
@date 2020-07-01

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
Problem 10.9: "Sorted Matrix Search: Given an M x N matrix in which 
each row and each column is sorted in ascending order, write a method to 
find an element" 
"""

""" 
Approach: Based on binary search. Choose the 'middle' value in the matrix.
Use it to split the matrix into four quadrants. Recursively search three of 
these.
"""

"""
Notes:
- The minimum value will always be in the top-left corner; the maximum will
  be in the bottom right
- For any value in the matrix: values to the top-left are smaller; values
  to the bottom-right are larger; values elsewhere can be either larger 
  or smaller. 
- This solution is slightly different than the textbook solution, which
  performs binary search on the diagonal to find the first element larger
  than the target, and then searches the top-right and bottom-left quadrants
  recursively, but both are based on binary search, recursion, and the
  properties of the sorted matrix.
"""

# Imports
import math as m
import numpy as np

def search_sorted(matrix, value):
    m,n = matrix.shape
    return search_sorted_recursive(matrix, value, 0, m-1, 0, n-1)

def search_sorted_recursive(matrix, value, top, bottom, left, right):

    # Base case: empty
    if top > bottom or left > right:
        return False
    
    # Base case : one cell
    if top == bottom and left == right:
        if matrix[top,left] == value:
            return (top,left)
        else:
            return False

    # Recursive case
    mid_row = m.floor((top + bottom) / 2)
    mid_col = m.floor((left + right) / 2)

    # Eliminate top-left
    if value > matrix[mid_row, mid_col]:
        
        # Search to right
        right_res = search_sorted_recursive(matrix, value, top, bottom, mid_col + 1, right)

        if right_res is not False: 
            return right_res
        
        # Search to bottom-left
        else: 
            return search_sorted_recursive(matrix, value, mid_row + 1, bottom, left, mid_col)
        
    # Eliminate bottom-right
    elif value < matrix[mid_row, mid_col]:
        
        # Search to left
        left_res = search_sorted_recursive(matrix, value, top, bottom, left, mid_col - 1)

        if left_res is not False:
            return left_res
        
        # To top-right
        else:
            return search_sorted_recursive(matrix, value, top, mid_row - 1, mid_col, right)

    else:
        return (mid_row, mid_col)

print("Beginning tests...")

#0
matrix = np.array([[]])                                     
assert search_sorted(matrix, 1) is False

#1
matrix = np.array([[1]])
assert search_sorted(matrix, 1) in [(0,0)]

#2
matrix = np.array([[2]])
assert search_sorted(matrix, 1) is False

#3
matrix = np.array([[1,2],[4,6]])
assert search_sorted(matrix, 1) in [(0,0)]

#4
matrix = np.array([[0,1],[1,2]])
assert search_sorted(matrix, 1) in [(0,1),(1,0)]

#5
matrix = np.array([[0,0],[0,1]])
assert search_sorted(matrix, 1) in [(1,1)]

#6
matrix = np.array([[0,1],[1,1]])
assert search_sorted(matrix, 1) in [(0,1),(1,0),(1,1)]

#7
matrix = np.array([[0,0],[1,1]])
assert search_sorted(matrix, 1) in [(1,0),(1,1)]

#8
matrix = np.array([[0,1],[0,1]])
assert search_sorted(matrix, 1) in [(0,1),(1,1)]

#9
matrix = np.array([[0,0,0],[0,1,2],[0,2,2]])
assert search_sorted(matrix, 1) in [(1,1)]

#10
matrix = np.array([[0,0,0],[0,0,2],[0,1,2]])
assert search_sorted(matrix, 1) in [(2,1)]

#11
matrix = np.array([[0,0,0],[0,0,1],[0,0,2]])
assert search_sorted(matrix, 1) in [(1,2)]

#12
matrix = np.array([[0,0,1]])
assert search_sorted(matrix, 1) in [(0,2)]

#11
matrix = np.array([[0],[0],[1]])
assert search_sorted(matrix, 1) in [(2,0)]

#11
matrix = np.array([[-1,0],[0,0],[1,1]])
assert search_sorted(matrix, 1) in [(2,0),(2,1)]

print("All tests passed!")