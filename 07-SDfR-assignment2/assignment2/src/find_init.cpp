//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Defines the maze and calls the print_maze function to print the 2D array
//==============================================================

#include <iostream>
#include <array>
#include <string>
#include "../include/maze.h"

// Function to find the initial position ("x") in the maze
std::pair<int, int> find_init(const std::array<std::array<std::string, COLS>, ROWS>& maze) {

    // Loop through the maze (fix row-column order)
    for (int i = 0; i < ROWS; i++) {  // Loop through rows
        for (int j = 0; j < COLS; j++) {  // Loop through columns
            if (maze[i][j] == "x") {
                return std::make_pair(i, j);  // Return the position of 'x'
            }
        }
    }

    // If 'x' is not found, return an invalid position (-1, -1)
    std::cout << "Not found\n";
    return std::make_pair(-1, -1);  // Return invalid position
}
