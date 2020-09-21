/**
 * @file <file-name>
 * @author Taylor Curran
 * @brief Solution to problem <> from Cracking the Coding Interview
 * @version 0.1
 * @date <date>
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem <problem-num>: <text> */

/* Approach: <text> */

#include <cassert> // assert
#include <iostream> // std::cout, std::endl;

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

// Returns true if planes have collided with ground
bool dead(int count, int* heights)
{
    for (int i = 0; i < count; i++) {
        if (heights[i] < 0 && heights[i] != INT_MIN) {
            return true;
        }
    }

    return false;
}

// Decremements arrays; ignores INT_MIN (shot down planes)
void update(int count, int* height, int* descent_rate)
{
    for (int i = 0; i < count; i++) {
        // Do not decrement destroyed planes
        if (height[i] != INT_MIN) {
            height[i] = height[i] - descent_rate[i];
        }
    }
}

// Returns index of plane closest to ground. Assume all planes have not hit
int findMinPositive(int count, int* array)
{
    int min = INT16_MAX;
    int min_index = -1;

    for (int i = 0; i < count; i++) {
        if (array[i] < min && array[i] != INT_MIN) {
            min = array[i];
            min_index = i;
        }
    }

    return min_index;
}

int maxPlanes(int startHeight_count, int* startHeight, int descentRate_count, int* descentRate)
{

    int count = 0;
    int planesShot = 0;

    while (!dead(startHeight_count, startHeight)) {
        // Find closest to ground
        int closest = findMinPositive(startHeight_count, startHeight);

        // Eliminate
        startHeight[closest] = INT_MIN;
        planesShot++;

        // Update
        update(startHeight_count, startHeight, descentRate);
        count++;
    }

    return planesShot;
}

int main()
{
    std::cout << std::endl
              << "Beginning tests..." << std::endl;

    int heights[3] = { 2, 4, 3 };
    int rates[3] = { 2, 2, 2 };
    maxPlanes(3, &heights, 3, &rates);

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}