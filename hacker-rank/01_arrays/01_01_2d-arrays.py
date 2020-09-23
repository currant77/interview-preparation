# File: 01_01_2d-arrays.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Arrays > 2D array

"""
Problem: Given a 6 x 6 2D array 'arr'. An "hourglass" is a subset of indices in a 
pattern with three values in the top row, one middle value in the middle row,
and three values in the bottom row:

a b c
  d
e f g

There are 16 hourglasses in arr. An hourglass sum is the sum of its values. 
Calculate the hourglass sum for every hourglass in 'arr' and return the maximum
hourglass sum. The array will always be 6 x 6.

Parameters:
    - 'arr': a 6 x 6 2D integer array

Returns:
    - int: maximum hourglass sum

Contraints:
    - -9 <= arr[i][j] <= 9
    - o <= i, j <= 5


"""

# Calculates hourglass sum for valid middle index


def sum_helper(arr, mid_index):

    sum = 0
    mid_row, mid_col = mid_index

    # Top row
    sum += arr[mid_row - 1][mid_col - 1]
    sum += arr[mid_row - 1][mid_col]
    sum += arr[mid_row - 1][mid_col + 1]

    # Middle
    sum += arr[mid_row][mid_col]

    # Bottom row
    sum += arr[mid_row + 1][mid_col - 1]
    sum += arr[mid_row + 1][mid_col]
    sum += arr[mid_row + 1][mid_col + 1]

    return sum

# Complete the hourglassSum function below.


def hourglassSum(arr):
    max = (-9 * 7) - 1
    for row in range(1, 5):
        for col in range(1, 5):
            sum = sum_helper(arr, (row, col))
            if max < sum:
                max = sum

    return max
