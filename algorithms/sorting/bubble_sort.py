"""
@file: bubble_sort.py
@author: Taylor Curran
@brief: Python implementation of bubble sort
@version 0.1
@date 2020-06-28

@copyright Copyright (c) 2020
"""

def bubble_sort(list):

    sorted = False

    while not sorted:
        sorted = True

        # Iterate over list
        for i in range(0,len(list)-1):
            
            #Swap values
            if list[i+1] < list[i]:
                temp = list[i]
                list[i] = list[i+1]
                list[i+1] = temp 
                sorted = False

    return list


print("Beginning tests...")

assert [] == bubble_sort([])
assert [1] == bubble_sort([1])
assert [1,2,3] == bubble_sort([1,2,3])
assert [1,2,3] == bubble_sort([1,3,2])
assert [1,2,3] == bubble_sort([3,1,2])
assert [1,2,3,4,5] == bubble_sort([1,5,4,2,3])

print("All tests passed!")
