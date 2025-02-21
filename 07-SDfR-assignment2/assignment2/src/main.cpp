//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Defines the maze and calls the print_maze function to print the 2D array
//==============================================================

#include <iostream>
#include <array>
using namespace std;
#include "maze.h"

int main() {
    // Declare position variable
    std::pair<int, int> position;

    // Define several 12x12 mazes to test the program

    array<array<string, 12>, 12> maze = {{ // A correct maze
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

    print_maze(maze); // Print the maze

    position = find_init(maze);  // Assign the result of find_init
    bool exit = place_exit(maze); // Look if there exist some possible exit
    
     if (position != std::make_pair(-1, -1) && exit) {
        bool solved = traverseMaze(maze, position.first, position.second);
        if (solved) std::cout << "Maze solved! Reached the exit.\n";
        else std::cout << "No exit found :(\n";
    } else {
        if (position == std::make_pair(-1, -1))
            std::cout << "No initial point found\n";
        else
            std::cout << "No possible end found\n";
    }

    return 0;
}
