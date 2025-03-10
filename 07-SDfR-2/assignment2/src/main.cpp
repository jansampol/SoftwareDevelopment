//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Initializes a maze, finds the start and end points, 
//               and attempts to solve the maze using backtracking. 
//               Displays results based on the maze solution status.
//==============================================================

#include <iostream>
#include <array>
#include "maze.h"

int main() {
    // Declare position variable
    std::pair<int, int> position;

    // Define a 12x12 maze
    std::array<std::array<std::string, COLS>, ROWS> maze = {{
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", ".", ".", "#", ".", ".", ".", ".", ".", ".", "#"},
        {".", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "x"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    // Print the maze
    print_maze(maze);

    // Find the initial position and exit
    position = find_init(maze);
    bool exit = place_exit(maze);

    // Try to solve the maze and show the user the result
    if (position != std::make_pair(-1, -1) && exit) {
        bool solved = traverseMaze(maze, position.first, position.second);
        if (solved)
            std::cout << "Maze solved! Reached the exit.\n";
        else
            std::cout << "No exit found :(\n";
    } else {
        if (position == std::make_pair(-1, -1))
            std::cout << "No initial point found\n";
        else
            std::cout << "No possible end found\n";
    }

    return 0;
}
