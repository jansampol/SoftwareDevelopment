//==============================================================
// Filename : exit_finder.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Finds and marks the exit points in the maze
//==============================================================

#include "../include/maze.h"

void place_exit(std::array<std::array<std::string, COLS>, ROWS>& maze) {
    // Check first and last row
    for (size_t j = 0; j < COLS; ++j) {
        if (maze[0][j] == ".") maze[0][j] = "E";
        if (maze[ROWS - 1][j] == ".") maze[ROWS - 1][j] = "E";
    }
    
    // Check first and last column
    for (size_t i = 0; i < ROWS; ++i) {
        if (maze[i][0] == ".") maze[i][0] = "E";
        if (maze[i][COLS - 1] == ".") maze[i][COLS - 1] = "E";
    }
}