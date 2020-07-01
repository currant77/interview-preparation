"""
@file: cci_1-7.py
@author: Taylor Curran
@brief: Solution to problem 1.7 from Cracking the Coding Interview
@version 0.1
@date 2020-06-22

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
Problem 1.7: "Rotate Matrix: 
(a) Given an image represented by an NxN matrix, where each 
pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.
(b) Can you do this in place?" 
"""

""" 
Approach: Assume that the rotation is clockwise. This problem is equivalent to 
rotating any 2d array of numbers. Array is m (rows) x n (columns)

(a) Create new array and fill values across. Value at (r, s) moves to (s, m-r) 
[I actually accidentally wrote this algorithm for the general m x n case, not
the specific n x n case from the problem...]

(b) Rotating in place only makes sense for a square matrix - otherwise the shape 
of the matrix will change. We can do this in place by proceeding 'layer by layer`, 
from outside to inside, and rotating each `layer` about the centre of the square
matrix"""

# Imports
import numpy as np

# (a)
def rotate_array(arr):
    """ Returns a copy of the 2d array rotate 90 degrees clockwise """
    
    # Special case: empty array
    if arr.size == 0:
        return arr
    
    m, n = arr.shape
    rotated = np.empty([n,m])

    for row in range(m):
        for col in range(n):
            rotated[col][m - row - 1] = arr[row][col]

    return rotated    

# (b)
def rotate_inplace(arr):
    """ Rotates the n x n (square) array in place by 90 degrees clockwise
    and returns it """

    # Base case: array if empty or 1 x 1
    if arr.size < 2:
        return arr

    # Check that array is square
    m,n = arr.shape
    assert(m == n)

    # Rotate the outside layer
    for i in range(n-1):
        
        # top = arr[0,i]
        # right = arr[i,n-1]
        # bottom = arr[n-1,n-1-i]
        # left = arr[n-1-i,0]

        temp = arr[i,n-1]               # save right
        arr[i,n-1] = arr[0,i]           # top to right
        arr[0,i] = arr[n-1-i,0]         # left to top
        arr[n-1-i,0] = arr[n-1,n-1-i]   # bottom to left
        arr[n-1,n-1-i] = temp           # right to bottom
       
    # Recursively rotate the other layers
    rotate_inplace(arr[1:n-1,1:n-1])

    return arr

print("Beginning tests...")

# Test rotate_array
assert(np.array_equal(np.array([[]]), rotate_array(np.array([[]]))))
assert(np.array_equal(np.array([[1]]), rotate_array(np.array([[1]]))))
assert(np.array_equal(np.array([[1],[2]]), rotate_array(np.array([[1,2]]))))
assert(np.array_equal(np.array([[2,1]]), rotate_array(np.array([[1],[2]]))))
assert(np.array_equal(np.array([[5,3,1],[6,4,2]]), rotate_array(np.array([[1,2],[3,4],[5,6]]))))

# Test rotate_inplace
assert(np.array_equal(np.array([[1]]), rotate_inplace(np.array([[1]]))))
assert(np.array_equal(np.array([[3,1],[4,2]]), rotate_inplace(np.array([[1,2],[3,4]]))))
assert(np.array_equal(np.array([[7,4,1],[8,5,2],[9,6,3]]), rotate_inplace(np.array([[1,2,3],[4,5,6],[7,8,9]]))))

print("All tests passed!")