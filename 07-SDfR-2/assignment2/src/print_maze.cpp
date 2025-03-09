//==============================================================
// Filename : print_maze.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Definition of the print_maze function, which takes as input the defined maze and prints it.
//==============================================================

#include <iostream>
#include <array>
#include <string>
#include "maze.h"  // Include the header file

// Function definition (no template)
void print_maze(const std::array<std::array<std::string, COLS>, ROWS>& maze) {
    std::cout << '\n';
    for (const auto& row : maze) {
        for (const auto& item : row) {
            std::cout << item << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}