# File: 01_03_new-year-chaos.py
# Name: Taylor Curran
# Date: September 22, 2020
# Description:
# HackerRank > Interview Preparation Kit > Arrays > New Year Chaos

"""
Problem: It's New Year's Day and everyone's in line for the Wonderland 
rollercoaster ride! There are a number of people queued up, and each person 
wears a sticker indicating their initial position in the queue. Initial 
positions increment by 1 from 1 at the front of the line to 'n' at the back.

Any person in the queue can bribe the person directly in front of them to swap 
positions. If two people swap positions, they still wear the same sticker 
denoting their original places in line. One person can bribe at most two others.
For example, if n = 8 and Person 5 bribes Person 4, the queue will look like 
this: [1,2,3,5,4,6,7,8]

Fascinated by this chaotic queue, you decide you must know the minimum number 
of bribes that took place to get the queue into its current state!

Parameters:
    - 'q': an array on integers

Returns:
    - int: minimum number of brides required

Contraints:
    - 1 <= n <= 10^5
"""

# Complete the minimumBribes function below.


def minimumBribes(q):
    swaps = 0
    exp_first = 1
    exp_second = 2
    exp_third = 3

    for i in range(len(q) - 1):
        if q[i] == exp_first:
            exp_first = exp_second
            exp_second = exp_third

        elif q[i] == exp_second:
            swaps += 1
            exp_second = exp_third

        elif q[i] == exp_third:
            swaps += 2
        else:
            print('Too chaotic')
            return

        exp_third += 1

    print('{}'.format(swaps))
