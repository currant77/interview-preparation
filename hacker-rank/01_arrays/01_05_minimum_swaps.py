# File: 01_05_minimum_swaps.py
# Name: Taylor Curran
# Date: September 22, 2020
# Description:
# HackerRank > Interview Preparation Kit > Arrays > Minumum Swaps

"""
Problem: You are given an unordered array consisting of consecutive integers in 
[1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two 
elements. You need to find the minimum number of swaps required to sort the 
array in ascending order.

For example, given the array arr = [7,1,3,2,4,5,6] we perform the following 
steps:

index   array               swap (indices)
--------------------------------------------------
0       [7,1,3,2,4,5,6]     swap (0,3)
1       [2,1,3,7,4,5,6]     swap (0,1)
2       [1,2,3,7,4,5,6]     swap (3,4)
3       [1,2,3,4,7,5,6]     swap (4,5)
4       [1,2,3,4,5,7,6]     swap (5,6)
5       [1,2,3,4,5,6,7]

Result: it took 5 swaps to sort the array.

Parameters: 'arr' - an unordered array of integers
Constraints: 1 <= n <= 10^5


"""

# Discussion:
#   - This algorithm relies on the fact that each number in [1,N] is present
#     exactly once. As a result, we know that any value v must end up at index
#     v - 1.
#   - If we start at index 0, the value there will 'point' to another index:
#     the index where that value must end up. The value at that index will, in
#     turn, point to another index, and so on
#   - If we follow this chain, we will always get a loop. Why? Because each
#     number in [1,N] occurs exactly once, so there cannot be more than one
#     value that 'points' to each cell
#   - We can use these loops to swap values into place. Suppose we start at an
#     index 0. If the value at 0 is in the 'right place' (if arr[0] == 1), then
#     we can move to the next index. If not, we are at the start of a loop.
#   - We can now swap the value at index 0 to its 'proper place' (at index
#     arr[0] - 1) to 'move' through the list. We now have a new value at index
#     0. We can continue in this way until we get arr[0] == 1, meaning that we
#     have reached the end of the list.
#   - Once we have reached the end of the list, we can move onto the next index
#     in the array. Because we are always swapping values into their 'correct'
#     place, if we encounter a cell that was part of a loop we've already
#     traversed, we will just skip it
#   - Okay, this might work: but why is it the minimal number of swaps? At each
#     step, we are swapping at least one value into the correct place. And, if
#     there are two values that can be swapped and *both* end up in the correct
#     place, they will form their own loop and we will be guaranteed to find it.
#     As a result, this must be the minimum number of swaps.


def minimumSwaps(arr):
    swaps = 0
    for i in range(len(arr)):
        while i + 1 != arr[i]:
            swaps += 1
            temp = arr[i]
            arr[i] = arr[temp - 1]
            arr[temp - 1] = temp

    return swaps


print(minimumSwaps([5, 2, 4, 1, 7, 6, 3]))
