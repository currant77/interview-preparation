"""
@file: cci_10-5.py
@author: Taylor Curran
@brief: Solution to problem 10.5 from Cracking the Coding Interview
@version 0.1
@date 2020-07-01

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
Problem 10.5: "Sparse Search: Given a sorted array of strings
that is interspersed with empty strings, write a method to find the 
location of a given string" 
 """

""" 
Approach: Use a modifed binary search. Query the middle index. If
it is empty, linearly for the first non-empty string; the search
the appropriate half recursively
"""

import math as m

def find_string(list, value):
    """ Returns the index of `value` in `list`; if value
    is not in the list, returns -1. """

    return find_string_recursive(list, value, 0, len(list) - 1)

def find_string_recursive(list, value, start, end):

    # Base cases
    if end < start: 
        return -1

    elif end == start:
        if list[start] == value:
            return start
        else: 
            return -1

    else:

        # Find mid
        mid = m.floor((start + end) / 2)

        if list[mid] == '':

            # Search both direction 
            left = mid - 1
            right = mid + 1
            
            while True:

                # (1) Only empty strings left
                if start > left and right > end:
                    return -1
                
                # (2) Non-empty string at left
                elif start <= left and list[left] != '':
                    mid = left
                    break
                
                # (3) Non-empty string at right
                elif right <= end and list[right] != '':
                    mid = right
                    break

                # (4) Increment value
                else:
                    left -= 1
                    right += 1
            
        # Recursive binary search
        if list[mid] > value:
            return find_string_recursive(list, value, start, mid - 1)
        elif list[mid] < value:
            return find_string_recursive(list, value, mid + 1, end)
        else:
            return mid

print("Beginning tests...")

list = ['at','','','','ball','','','car','','','dad','','']

assert find_string(list, 'at') == 0
assert find_string(list, 'am') == -1
assert find_string(list, 'ball') == 4
assert find_string(list, 'base') == -1
assert find_string(list, 'car') == 7
assert find_string(list, 'dad') == 10
assert find_string(list, 'dog') == -1
assert find_string([], 'dad') == -1

print("All tests passed!")