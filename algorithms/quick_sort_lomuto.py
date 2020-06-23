"""
@file: merge_sort.py
@author: Taylor Curran
@brief: Implementation of quick sort using Lomuto partitioning approac
@version 0.1
@date 2020-06-23

@copyright Copyright (c) 2020
"""

#Import
import math

def merge_sort(list):
    """ Sorts the list in acsending order and return it """

    # TODO

    return list

print("Beginning tests...")

assert [] == merge_sort([])
assert [1] == merge_sort([1])
assert [1,2,3] == merge_sort([1,2,3])
assert [1,2,3] == merge_sort([1,3,2])
assert [1,2,3] == merge_sort([3,1,2])
assert [1,2,3,4,5] == merge_sort([1,5,4,2,3])

print("All tests passed!")
