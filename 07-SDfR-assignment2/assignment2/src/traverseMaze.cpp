//==============================================================
// Filename : traverseMaze.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Defines the maze and calls the print_maze function to print the 2D array
//==============================================================

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "maze.h"

// Define a scoped enumeration for the four directions
enum class Direction { Up, Down, Left, Right };

// Structure to store a decision point
struct Junction {
    int i, j;
    std::vector<std::pair<int, int>> options; // Store all the possible exploring options
    std::vector<std::pair<int, int>> visitedPath; // Coordinates visited from the last decision point
};

std::vector<Junction> stack; // Stack for backtracking

// Helper function to convert direction to coordinate change
std::pair<int, int> directionToOffset(Direction dir) {
    switch (dir) {
        case Direction::Up:    return {-1, 0};
        case Direction::Down:  return {1, 0};
        case Direction::Left:  return {0, -1};
        case Direction::Right: return{0, 1};
        default:               return {0, 0};
    }
}

bool traverseMaze(std::array<std::array<std::string, COLS>, ROWS>& maze, int i, int j) {

    if (maze[i][j] == "E") { // Return True if we find the exit
        return true;
    }

    // Mark the current position as visited
    maze[i][j] = "x";

    // Print the maze
    print_maze(maze);

    // Store all possible directions
    std::vector<std::pair<int, int>> options;
    for (Direction dir : {Direction::Up, Direction::Down, Direction::Left, Direction::Right}) {
        // Get the offset for the current direction
        std::pair<int, int> offset = directionToOffset(dir);
        int offset_i = offset.first;
        int offset_j = offset.second;
        
        int next_i = i + offset_i;
        int next_j = j + offset_j;

        // Check if the new coordinates are within bounds and not blocked
        if (next_i >= 0 && next_i < ROWS && next_j >= 0 && next_j < COLS &&
            (maze[next_i][next_j] == "." || maze[next_i][next_j] == "E")) {
            options.emplace_back(next_i, next_j); // Add valid option
        }
    }

    // If there exist more than one path, it is a decision point
    if (options.size() > 1) {
        stack.push_back({i, j, options, {}}); // Store the coordinates of the decision point + the different possible paths
    }

    // Store the path taken from the last decision point
    if (!stack.empty()) {
        stack.back().visitedPath.emplace_back(i, j);
    }

    // Explore each possible option
    for (auto& option : options) {
        int next_i = option.first;
        int next_j = option.second;
        if (traverseMaze(maze, next_i, next_j)) {
            return true; // If we reach the exit, stop searching
        }
    }

    // If we get stuck, go back to the last decision point and clean the path
    if (!stack.empty()) {
        Junction lastJunction = stack.back();
        stack.pop_back(); // Remove the last decision made

        // Change "x" to "," in the incorrect paths
        for (auto& point : lastJunction.visitedPath) {
            maze[point.first][point.second] = ",";
        }

        return traverseMaze(maze, lastJunction.i, lastJunction.j);
    }

    return false; // No solution found
}