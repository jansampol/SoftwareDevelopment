//==============================================================
// Filename    : main.cpp
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "Tree.h"
#include "isValidInteger.h"
#include <iostream>
#include <string>

int main() {

    // Initialize the tree
    Tree<int> intTree;

    // Include the desired values
    int values[] = {17, 42, 13, 50, 27, 11, 1, 6, 33, 20, 47, 48};

    std::cout << "\nInserting values into the tree: ";
    for (int value : values) {
        std::cout << value << " ";
        intTree.insertNode(value);
    }
    std::cout << "\n\n";

    // A while loop to ask the user to introduce an integer
    std::string input;
    int searchValue;
    while (true) {
        std::cout << "Enter an integer to search in the tree: ";
        if (!std::getline(std::cin, input) || input.empty()) {
            std::cerr << "No valid value. Please, introduce an integer \n";
            continue; // Volver a pedir la entrada
        }

        if (isValidInteger(input)) {
            searchValue = std::stoi(input);
            std::cout << "Valid introduced number: " << searchValue << "\n\n";
            break; // Salir del bucle si es válido
        } else {
            std::cerr << "No integer introduced. Please, introduce an integer \n";
        }
    }

    // Search the introduced integer
    TreeNode<int>* result = intTree.search(searchValue);
    if (result) {
        std::cout << "The integer " << searchValue << " was found in the tree.\n\n";
    } else {
        std::cout << "The integer " << searchValue << " was NOT found in the tree.\n\n";
    }

    // Show the tree structure
    std::cout << "Tree structure:\n\n";
    intTree.outputTree();

    return 0;
}
