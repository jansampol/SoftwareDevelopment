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
#include "../include/maze.h"

struct Junction {
    int i, j;  // Position in the maze
    std::vector<std::pair<int, int>> options; // Unexplored paths
};

std::vector<Junction> stack; // Stack for backtracking

bool traverseMaze(std::array<std::array<std::string, COLS>, ROWS>& maze, int i, int j) {
    // Base Case: Found Exit
    if (maze[i][j] == "E") {
        std::cout << "Maze solved! Reached the exit.\n";
        return true;
    }

    // Mark current position as visited
    maze[i][j] = "x";
    print_maze(maze);

    // Store available paths
    std::vector<std::pair<int, int>> options;
    if (i > 0 && (maze[i - 1][j] == "." || maze[i - 1][j] == "E")) options.emplace_back(i - 1, j); // Up
    if (i < ROWS - 1 && (maze[i + 1][j] == "." || maze[i + 1][j] == "E")) options.emplace_back(i + 1, j); // Down
    if (j > 0 && (maze[i][j - 1] == "." || maze[i][j - 1] == "E")) options.emplace_back(i, j - 1); // Left
    if (j < COLS - 1 && (maze[i][j + 1] == "." || maze[i][j + 1] == "E")) options.emplace_back(i, j + 1); // Right

    // If at a junction, save it for backtracking
    if (options.size() > 1) {
        stack.push_back({i, j, options});
    }

    // Recursively explore each option
    for (auto& option : options) {
        int next_i = option.first;
        int next_j = option.second;
        if (traverseMaze(maze, next_i, next_j)) {
            return true; // If path leads to exit, stop searching
        }
    }

    // If no valid path, backtrack
    if (!stack.empty()) {
        Junction lastJunction = stack.back();
        stack.pop_back(); // Remove last junction
        return traverseMaze(maze, lastJunction.i, lastJunction.j); // Backtrack
    }

    return false; // No solution found
}