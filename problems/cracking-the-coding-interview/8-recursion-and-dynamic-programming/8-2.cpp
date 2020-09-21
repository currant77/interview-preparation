/**
 * @file 8-2.cpp
 * @author Taylor Curran
 * @brief Solution to problem 8.2 from Cracking the Coding Interview
 * @version 0.1
 * @date August 29, 2020
 * 
 * @note McDowell, Gayle Lakkmann. Cracking the Coding Interview. 
 * 6th ed. Palo Alto, CA: CareerCup, 2016.
 * 
 * @copyright Copyright (c) 2020
 */

/* Problem 8.2: "Robot in a Grid: Imagine a robot sitting on the upper left 
corner of a grid with r rows and c columns. The robot can only move in two 
directions, right and down, but certain cells are 'off limits' such that the
robot cannot step on them. Design an algorithm to find a path for the robot from
the top left to the bottom right.

Assume: Because the robot can only move down and right, the path to cell (i,j)
is either a path to cell (i-1,j) followed by a move down, or a path to cell
(i,j-1) followed by a move right. A recursive algorithm to solve this problem
would recursively search for a path to cells (i-1,j) and (i,j-1).

Assume: there is a set that contains all of the off-limit indices. 
Store indices in std::pairs and store a path as a list of indices. Let (0,0) be
the origin (zero-based indices).

Approach: use dynamic programming and recursion. Create a 2D array. Each cell 
will initially contain a dummy value. If there is a path to a cell, store the
index of that cell at the corresponding position; if there is not, store a
invalid index.
*/

#include <cassert> // assert
#include <iostream> // std::cout, std::endl;
#include <set> // std::set
#include <utility> // std::pair
#include <vector> // std::vector

using namespace std;
typedef std::pair<int, int> Index;
typedef std::vector<Index> Path;

Path getPath(Index index, set<Index> inaccessible)
{
    // Invalid index
    if (index.first < 0 || index.second < 0)
        return Path();

    // Inaccessible index
    else if (inaccessible.find(index) != inaccessible.end())
        return Path();

    // Origin
    else if (index.first == 0 && index.second == 0) {
        return Path({ Index(0, 0) });
    }

    Path p;

    // Path above
    p = getPath(Index { index.first - 1, index.second }, inaccessible);

    if (!p.empty()) {
        p.push_back(index);
        return p;
    }

    // Path to left
    p = getPath(Index { index.first, index.second - 1 }, inaccessible);

    if (!p.empty()) {
        p.push_back(index);
        return p;
    }

    // No path
    inaccessible.insert(index);
    return Path();
}

void print_path(Path path)
{
    if (path.empty()) {
        std::cout << "Empty\n";
        return;
    }

    for (int i = 0; i < path.size(); i++) {
        std::cout << "(" << path[i].first << "," << path[i].second << ")";

        if (i != path.size() - 1)
            std::cout << " -> ";
    }

    std::cout << std::endl;
}

int main()
{
    std::cout << "\nBeginning tests..." << std::endl;

    // No obstacles
    set<Index> off_limits = set<Index>();

    print_path(getPath(Index(0, 0), off_limits));
    print_path(getPath(Index(1, 1), off_limits));
    print_path(getPath(Index(3, 3), off_limits));

    // Obstacle at start (should return empty)
    off_limits.insert(Index(0, 0));
    print_path(getPath(Index(3, 3), off_limits));
    off_limits.erase(Index(0, 0));

    // Obstacles at end (should return empty)
    off_limits.insert(Index(3, 3));
    print_path(getPath(Index(3, 3), off_limits));
    off_limits.erase(Index(3, 3));

    // Obstacles in middle
    // Path: (0,0) -> (1,0) -> (1,1) -> (1,2) -> (2,2) -> (2,3) -> (3,3)
    off_limits.insert(Index(0, 1));
    off_limits.insert(Index(2, 1));
    off_limits.insert(Index(3, 2));
    off_limits.insert(Index(1, 3));

    print_path(getPath(Index(3, 3), off_limits));

    std::cout << "All tests passed!" << std::endl;
    exit(0);
}