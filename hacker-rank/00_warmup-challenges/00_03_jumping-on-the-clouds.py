# File: 00_03_jumping-on-the-clouds.py
# Name: Taylor Curran
# Date: September 21, 2020
# Description:
# HackerRank > Interview Preparation Kit > Warm-up Challenges >
#   Jumping on the Clouds

"""
Problem: Emma is playing a new mobile game that starts with consecutively 
numbered clouds. Some of the clouds are thunderheads and others are cumulus. 
She can jump on any cumulus cloud having a number that is equal to the number 
of the current cloud plus 1 or 2. She must avoid the thunderheads. Determine 
the minimum number of jumps it will take Emma to jump from her starting postion 
to the last cloud. It is always possible to win the game.

For each game, Emma will get an array of clouds numbered 0 if they are safe or 1
if they must be avoided. For example, c = [0,1,0,0,0,1,0] indexed from 0 to 6. 
The number on each cloud is its index in the list so she must avoid the clouds 
at indexes 1 and 5. She could follow the following two paths: 0 -> 2 -> 4 -> 6 
or 0 -> 2 -> 3 -> 4 -> 6. The first path takes 3 jumps while the second takes 4.

Complete the jumpingOnClouds function in the editor below. It should return the 
minimum number of jumps required, as an integer.

Parameters:
    - array: n binary integers describing clouds c[i] where i <= i < n.

Contraints:
    - 2 <= n <= 100
    - c[i] in {0, 1}
    - c[0] = c[n-1] = 0

Output: the minimum number of jumps needed to win the game
"""

# Note: probably would have been easier not to solve this recursively...


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
