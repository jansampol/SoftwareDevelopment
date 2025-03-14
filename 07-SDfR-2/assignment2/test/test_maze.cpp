//==============================================================
// Filename : test_maze.cpp
// Authors : Jan Sampol and Teresa Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Checks the correct working of the program for different maze cases
//==============================================================

#include <iostream>
#include <array>
#include <cassert>
#include "maze.h"

// Test 1: Maze with a valid exit
void test_maze_with_exit() {
    std::array<std::array<std::string, COLS>, ROWS> maze = {{ // Maze with several possible exits
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"x", ".", ".", ".", "#", ".", "#", "#", "#", "#", ".", "."},
        {"#", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"},
        {".", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    assert(find_init(maze) != std::make_pair(-1, -1)); // Ensure there's a starting position
    assert(place_exit(maze) == true);  // An exit should be placed

    std::cout << "Test 1 passed: Maze with exit and starting point correctly detected.\n";
}

// Test 2: Maze without an initial point ("x")
void test_maze_no_start() {
    std::array<std::array<std::string, COLS>, ROWS> maze = {{ // A maze without initial point
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", ".", ".", "#", ".", ".", ".", ".", ".", ".", "#"},
        {".", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    assert(find_init(maze) == std::make_pair(-1, -1));  // No start position should be found
    std::cout << "Test 2 passed: Maze without start correctly detected.\n";
}

// Test 3: Maze with no valid exit
void test_maze_no_exit() {
    std::array<std::array<std::string, COLS>, ROWS> maze = {{ // A maze without exit
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"x", ".", ".", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}, 
        {"#", ".", ".", ".", ".", ".", ".", "#", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
    }};

    assert(place_exit(maze) == false);  // No exit should be placed
    std::cout << "Test 3 passed: Maze without exit correctly detected.\n";
}

// Test 4: Maze with an exit but not reachable
void test_maze_unreachable_exit() {
    std::array<std::array<std::string, COLS>, ROWS> maze = {{ // A maze with a not reachable exit
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"x", ".", ".", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", ".", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"},
        {"#", "#", "#", ".", "#", ".", ".", ".", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", "#", "#", "#", ".", "#", ".", "#"},
        {"#", "#", "#", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", "#", ".", "#", ".", "#", ".", "#", ".", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#", "#", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", ".", "#"}
    }};

    assert(find_init(maze) != std::make_pair(-1, -1)); // Ensure there's a start
    assert(place_exit(maze) == true); // Exit exists
    assert(traverseMaze(maze, find_init(maze).first, find_init(maze).second) == false); // Unreachable exit

    std::cout << "Test 4 passed: Unreachable exit correctly detected.\n";
}

int main() {
    test_maze_with_exit();
    test_maze_no_start();
    test_maze_no_exit();
    test_maze_unreachable_exit();

    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}
