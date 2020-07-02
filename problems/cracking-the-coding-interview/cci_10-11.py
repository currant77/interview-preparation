"""
@file: cci_10-11.py
@author: Taylor Curran
@brief: Solution to problem 10.11 from Cracking the Coding Interview
@version 0.1
@date 2020-07-01

@note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
6th ed. Palo Alto, CA: CareerCup, 2016.

@copyright Copyright (c) 2020
"""

""" 
roblem 10.11: "Peaks and Valleys: In an array of integers, a 'peak' 
is an element which is greater than or equal to the adjacent integers 
and a 'valley' is an element which is less than or equal to the adjacent 
integers. For example, in the array [5,8,6,2,3,4,6], [8,6] are peaks and 
[5,2] are valleys. Given an array of integers, sort the array into an 
alternating sequence of peaks and valleys.

Example: [5,3,1,2,3] -> [5,1,3,2,3]
"""

""" Approach: 
(1) Sort the list in ascending order
(2) Progress from the start and end of the list and work towards the middle.
At every second value, swap the value from the back with the value from the front.
"""

"""
Notes: 
- The problem does not specify any particular way that the peaks and valleys
  must alternate - there is no defined output (that is why the 'tests' below
  simply print the values for manual checking).
- This algorithm does not implement a sorting algorithm, and just relies on 
  Python's built-in implementation.
- The first and second solution are mine and the book's `suboptimal` solutions;
  both a O(nlog(n)) because they require sorting the list; the last one is the
  book's 'optimal' solution, which in O(n)
"""

def peaks_valleys_1(list):
    """ Creates peaks and valleys by inserting from front
    and back of a sorted list """

    # Sort list (ascending by default)
    list.sort()

    # Create peaks and valleys
    front = 0
    back = len(list) - 1
    pv = []

    while front <= back:

        if front == back:
            pv.append(list[front])
            return pv

        pv.append(list[back])
        pv.append(list[front])

        front += 1
        back -= 1

    return pv

def peaks_valleys_2(list):
    """ Creates peaks and valleys by swapping every second 
    adjacent value in a sorted list """

    list.sort()

    for i in range(1, len(list), 2):
        temp = list[i]
        list[i] = list[i-1]
        list[i-1] = temp

    return list

def peaks_valleys_3(list):
    """ Creates peaks and valleys by swapping each second
    value with the largest adjacent value """

    # Empty list
    if list is None or not len(list):
        return list

    # Iterate over 1,3,5,...,
    for i in range(1, len(list) - 1, 2):
        
        # Index is largest
        if list[i] >= list[i-1] and list[i] >= list[i+1]:
            continue

        # Previous is largest
        elif list[i-1] > list[i] and list[i-1] >= list[i+1]:
            temp = list[i]
            list[i] = list[i-1]
            list[i-1] = temp 

        # Next is largest
        else:
            temp = list[i]
            list[i] = list[i+1]
            list[i+1] = temp

    # Even list: swap value if needed
    n = len(list)
    if n % 2 == 0:
        if list[n-2] > list[n-1]:
            temp = list[n-2]
            list[n-2] =  list[n-1]
            list[n-1] = temp

    return list

print("\nBeginning tests...")

list = []                       # Input:    []
print(peaks_valleys_1(list))    # Output:   []
print(peaks_valleys_2(list))    # Output:   []
print(peaks_valleys_3(list))    # Output:   []

list = [1]                      # Input:    [1]
print(peaks_valleys_1(list))    # Output:   [1]
print(peaks_valleys_2(list))    # Output:   [1]
print(peaks_valleys_3(list))    # Output:   [1]

list = [2,1]                    # Input:    [2,1]
print(peaks_valleys_1(list))    # Output:   [2,1]
print(peaks_valleys_2(list))    # Output:   [2,1]
print(peaks_valleys_3(list))    # Output:   [1,2]

list = [1,2]                    # Input:    [1,2]
print(peaks_valleys_1(list))    # Output:   [2,1]
print(peaks_valleys_2(list))    # Output:   [2,1]
print(peaks_valleys_3(list))    # Output:   [1,2]

list = [2,2]                    # Input:    [2,2]
print(peaks_valleys_1(list))    # Output:   [2,2]
print(peaks_valleys_2(list))    # Output:   [2,2]
print(peaks_valleys_3(list))    # Output:   [2,2]

list = [3,3,3]                  # Input:    [3,3,3]
print(peaks_valleys_1(list))    # Output:   [3,3,3]
print(peaks_valleys_2(list))    # Output:   [3,3,3]
print(peaks_valleys_3(list))    # Output:   [3,3,3]

list = [3,3,35,6,3,5,7,1]       # Input:    [3,3,35,6,3,5,7,1]
print(peaks_valleys_1(list))    # Output:   [35,1,7,3,6,3,5,3]
print(peaks_valleys_2(list))    # Output:   [3,1,3,3,6,5,35,7]
print(peaks_valleys_3(list))    # Output:   [1,3,3,6,3,35,5,7]

list = [5,112,7,6,14]           # Input:    [5,112,7,6,14]
print(peaks_valleys_1(list))    # Output:   [112,5,14,6,7]
print(peaks_valleys_2(list))    # Output:   [6,5,14,7,112]
print(peaks_valleys_3(list))    # Output:   [6,14,5,112,7]

print("All tests passed!")