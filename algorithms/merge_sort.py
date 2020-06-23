"""
@file: merge_sort.py
@author: Taylor Curran
@brief: Python implementation of merge sort
@version 0.1
@date 2020-06-22

@copyright Copyright (c) 2020
"""

#Import
import math

def merge_sort(list):
    
    # Base case
    if len(list) < 2:
        return list
    
    # Split list in half
    mid = math.floor(len(list) / 2)
    left = list[ : mid]
    right = list[mid : ]

    # Recursively sort each half
    left = merge_sort(left)
    right = merge_sort(right)

    # Merge sorted lists
    return merge(left, right)

def merge(left, right):
    """ Merges two sorted lists and returns
    the result """

    ret = []

    while len(left) != 0 and len(right) != 0:
        if left[0] <= right[0]:
            ret.append(left.pop(0))
        else:
            ret.append(right.pop(0))

    while len(left) != 0:
        ret.append(left.pop(0))
    
    while len(right) != 0:
        ret.append(right.pop(0))
    
    return ret

print("Beginning tests...")

assert [] == merge_sort([])
assert [1] == merge_sort([1])
assert [1,2,3] == merge_sort([1,2,3])
assert [1,2,3] == merge_sort([1,3,2])
assert [1,2,3] == merge_sort([3,1,2])
assert [1,2,3,4,5] == merge_sort([1,5,4,2,3])

print("All tests passed!")
