//==============================================================
// Filename : place_exit.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Finds and marks the exit points in the maze
//==============================================================

#include "maze.h"

bool place_exit(std::array<std::array<std::string, COLS>, ROWS>& maze) {
    bool exitPlaced = false; // Track if at least one "E" is placed

    // Check first and last row
    for (size_t j = 0; j < COLS; ++j) {
        if (maze[0][j] == ".") {maze[0][j] = "E"; exitPlaced = true;}
        if (maze[ROWS - 1][j] == ".") {maze[ROWS - 1][j] = "E"; exitPlaced = true;}
    }
    
    // Check first and last column
    for (size_t i = 0; i < ROWS; ++i) {
        if (maze[i][0] == ".") {maze[i][0] = "E"; exitPlaced = true;}
        if (maze[i][COLS - 1] == ".") { maze[i][COLS - 1] = "E"; exitPlaced = true; }
    }

    return exitPlaced; // Return true if at least one "E" was placed
}