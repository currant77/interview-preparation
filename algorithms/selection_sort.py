"""
@file: selection_sort.py
@author: Taylor Curran
@brief: Python implementation of selection sort
@version 0.1
@date 2020-06-28

@copyright Copyright (c) 2020
"""

def merge_sort(list):

    n = len(list)

    for start in range(0, n):

        # Search for min index
        min = start
        for i in range(start + 1, n):
            if list[i] < list[min]:
                min = i

        # Swap to start
        temp = list[min]
        list[min] = list[start]
        list[start] = temp
                     
    return list


print("Beginning tests...")

assert [] == merge_sort([])
assert [1] == merge_sort([1])
assert [1,2,3] == merge_sort([1,2,3])
assert [1,2,3] == merge_sort([1,3,2])
assert [1,2,3] == merge_sort([3,1,2])
assert [1,2,3,4,5] == merge_sort([1,5,4,2,3])

print("All tests passed!")
