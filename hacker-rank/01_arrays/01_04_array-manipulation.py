# File: 01_04_array-manipulation.py
# Name: Taylor Curran
# Date: September 22, 2020
# Description:
# HackerRank > Interview Preparation Kit > Arrays > Array Manipulation

"""
Problem: Starting with a 1-indexed array of zeros and a list of operations, for
each operation add a value to each of the array element between two given 
indices, inclusive. Once all operations have been performed, return the maximum 
value in the array.

Example: 'n' = 10 and 'queries' = [[1,5,3],[4,8,7],[6,9,1]]

Queries are interpreted as:

a  |  b  |  k  
---------------
1  |  5  |  3
4  |  8  |  7
6  |  9  |  1

Add the values of 'k' between the indices 'a' and 'b' inclusive:

Index ->                        1   2   3   4   5   6   7   8   9   10
(0) Initial:                [   0   0   0   0   0   0   0   0   0   0   ]
(1) Add 3 between 1 and 5:  [   3   3   3   3   3   0   0   0   0   0   ]
(2) Add 7 between 4 and 8:  [   3   3   3   10  10  7   7   7   0   0   ]
(3) Add 1 between 6 and 9:  [   3   3   3   10  10  8   8   8   1   0   ]

Result: max = 10

Contraints:
    - 3 <= n <= 10^7        (number of entries)
    - 1 <= m < 2 * 10^5     (number of operations)
    - 1 <= a <= b <= n
    - 1 <= k <= 10^9        (value to add each time)
"""

# Naive solution - O(n * n * m)


def arrayManipulation_naive(n, queries):
    arr = [0] * n
    for a, b, k in queries:
        for i in range(a-1, b):
            arr[i] += k

    return max(arr)

# Efficient solution - O(mlog(m))


def arrayManipulation(n, queries):

    m = len(queries)
    start_q = sorted(queries, key=lambda q: q[0])
    stop_q = sorted(queries, key=lambda q: q[1])

    cur_val = 0                 # Current value
    max_val = 0                 # Max value

    j = 0                       # start_q index
    k = 0                       # stop_q index

    while j < m:
        next_start = start_q[j][0]
        next_stop = stop_q[k][1] + 1

        if next_start == next_stop:
            while j < m and next_start == start_q[j][0]:
                cur_val += start_q[j][2]
                j += 1
            while next_stop == stop_q[k][1] + 1:
                cur_val -= stop_q[k][2]
                k += 1
            if cur_val > max_val:
                max_val = cur_val

        elif next_start < next_stop:
            while j < m and next_start == start_q[j][0]:
                cur_val += start_q[j][2]
                j += 1
            if cur_val > max_val:
                max_val = cur_val

        else:
            while next_stop == stop_q[k][1] + 1:
                cur_val -= stop_q[k][2]
                k += 1

    return max_val
