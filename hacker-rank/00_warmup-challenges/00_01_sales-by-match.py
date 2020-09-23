# File: 00_01_sales-by-match.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Warm-up Challenges > Sales by Match

"""
Problem: Alex works at a clothing store. There is a large pile of socks that 
must be paired by color for sale. Given an array of integers representing the 
color of each sock, determine how many pairs of socks with matching colors 
there are. 

For example, there are n = 7 socks with colors ar = [1,2,1,2,1,3,2]. There is 
one pair of color 1 and one of color 2. There are three odd socks left, one of 
each color. The number of pairs is 2.

Function Description: Complete the sockMerchant() function in the editor below. 
It must return an integer representing the number of matching pairs of socks 
that are available. sockMerchant has the following parameter(s):
    - n: the number of socks in the pile
    - ar: the colors of each sock

Input Format: The first line contains an integer n, the number of socks 
represented in ar. The second line contains n space-separated integers 
describing the colors ar[i] of the socks in the pile.

Constraints: 1 <= n <= 100 and 1 <= ar[i] <= 100 where 0 <= i < n

Output Format: Return the total number of matching pairs of socks that Alex can 
sell.
"""


def sockMerchant(n, ar):
    dict = {}
    for i in range(n):
        sock = ar[i]
        if not dict.get(sock):
            dict[sock] = 1
        else:
            dict[sock] += 1

    sock_count = 0
    for val in dict.values():
        sock_count += (val // 2)

    return sock_count
