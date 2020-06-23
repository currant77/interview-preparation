"""
@file: merge_sort.py
@author: Taylor Curran
@brief: Implementation of quick sort using Lomuto partitioning approach
@version 0.1
@date 2020-06-23

@copyright Copyright (c) 2020
"""

#Import
import math

def quick_sort(list):
    """ Sorts the list in ascending order using quick sort
    and returns it. Uses Lomuto partitioning approach and
    always selects the middle element as the new pivot"""

    return quick_sort_segment(list, 0, len(list) - 1)

def quick_sort_segment(list, start, end):
    """ Sorts the segment of the list been start and
    end in ascending order with quick sort and returns
    the list"""

    n = end - start + 1

    # Base case
    if n < 2: return list

    # Partition the list
    p = partition(list, start, end)

    # Sort each half about partition index
    quick_sort_segment(list, start, p - 1)
    quick_sort_segment(list, p + 1, end)

    return list

def partition(list, start, end):
    """ Partitions the list between start and end
    about a pivot, which is chosen as the middle 
    value, and returns the index of the pivot element
    in the resulting list (with all values less than
    the pivot to its left and all values greater or
    equal to it to its right)"""

    # Select pivot
    mid = math.floor((end + start) / 2)
    pivot = list[mid]

    # Swap pivot with last element
    list[mid] = list[end]
    list[end] = pivot

    # Iterate over elements to create partition
    pi = start # partition index

    for j in range(start, end):

      if list[j] < pivot:
          temp = list[j]
          list[j] = list[pi]
          list[pi] = temp
          pi = pi + 1

    # Swap pivot into index
    list[end] = list[pi]
    list[pi] = pivot

    return pi

print("Beginning tests...")

assert [] == quick_sort([])
assert [1] == quick_sort([1])
assert [1,2,3] == quick_sort([1,2,3])
assert [1,2,3] == quick_sort([1,3,2])
assert [1,2,3] == quick_sort([3,1,2])
assert [1,2,3,4,5] == quick_sort([1,5,4,2,3])

print("All tests passed!")
