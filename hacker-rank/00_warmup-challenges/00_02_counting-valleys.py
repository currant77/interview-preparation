# File: 00_02_counting-valleys.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Warm-up Challenges > Counting Valleys

"""
Problem: An avid hiker keeps meticulous records of their hikes. During the last 
hike that took exactly 'steps' steps, for every step it was noted if it was an 
uphill, 'U' , or a downhill, 'D' step. Hikes always start and end at sea level, 
and each step up or down represents a 1 unit change in altitude. We define 
the following terms:
    - A mountain is a sequence of consecutive steps above sea level, starting 
    with a step up from sea level and ending with a step down to sea level.
    - A valley is a sequence of consecutive steps below sea level, starting with
    a step down from sea level and ending with a step up to sea level.

Given the sequence of up and down steps during a hike, find and print the number
of valleys walked through.

Example: steps = [DDUUUUDD] -> valleys = 1

Parameters:
    - int 'steps': number of steps on hike
    - string 'path'L string describing the path

Returns: int: the number of valleys traversed

Constraints:
    - 2 <= steps <= 10^6
    - path[i] in {U,D}
"""


def countingValleys(steps, path):
    valleys_count = 0
    elevation = 0
    for i in range(steps):
        if path[i] == 'D':
            if elevation == 0:
                valleys_count += 1
            elevation -= 1
        else:
            elevation += 1

    return valleys_count
