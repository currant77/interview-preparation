# File: 01_02_left-rotation.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Arrays > Left Rotation

"""
Problem: A left rotation operation on an array shifts each of the array's 
elements 1 unit to the left. For example, if 2 left rotations are performed on 
array [1,2,3,4,5], then the array would become [3,4,5,1,2].

Given an array 'a' of 'n' integers and a number 'd', perform 'd' left rotations
on the array. 

Parameters:
    - 'a': array of integers
    - 'd': number of rotation

Returns:
    - array: final state of the array

Contraints:
    - 1 <= n <= 10^5
    - 1 <= d <= n
    - 1 <= a[i] <= 10^6
"""

# Complete the rotLeft function below.


def rotLeft(a, d):
    rot = [0 for i in range(len(a))]
    for old_index in range(len(a)):
        new_index = (old_index + len(a) - d) % len(a)
        rot[new_index] = a[old_index]
    return rot
