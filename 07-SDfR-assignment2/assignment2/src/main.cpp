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
#include "../include/maze.h"

int main(){

    array<array<string, 12>, 12> maze
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#",
        "#", ".", ".", ".", "#", ".", ".", ".", ".", ".", ".", "#",
        ".", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#",
        "#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#",
        "#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "x",
        "#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#",
        "#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#",
        "#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#",
        "#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#",
        "#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#",
        "#", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "#",
        "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"};


 print_maze(maze);
    }