//==============================================================
// Filename : maze.h
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Declares the print_maze function and the maze dimensions
//==============================================================

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <array>
#include <string>

constexpr size_t ROWS = 12;  // Define maze dimensions
constexpr size_t COLS = 12;

// Function declaration (without template)
void print_maze(const std::array<std::array<std::string, COLS>, ROWS>& maze);

#endif