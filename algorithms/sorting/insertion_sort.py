"""
@file: insertion_sort.py
@author: Taylor Curran
@brief: Python implementation of insertion sort
@version 0.1
@date 2020-06-28

@copyright Copyright (c) 2020
"""

def insertion_sort(list):

    for i in range(1,len(list)):
        j = i
        while j > 0 and list[j-1] > list[j]:
            
            # Swap values
            temp = list[j]
            list[j] = list[j-1]
            list[j-1] = temp

            j = j - 1
    
    return list

print("Beginning tests...")

assert [] == insertion_sort([])
assert [1] == insertion_sort([1])
assert [1,2,3] == insertion_sort([1,2,3])
assert [1,2,3] == insertion_sort([1,3,2])
assert [1,2,3] == insertion_sort([3,1,2])
assert [1,2,3,4,5] == insertion_sort([1,5,4,2,3])

print("All tests passed!")