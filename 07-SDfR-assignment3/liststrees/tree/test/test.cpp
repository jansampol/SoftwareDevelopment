//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       :
// License     : N.A. or opensource license like LGPL
// Description : Exhaustive test suite for Tree implementation
//==============================================================

#include "Tree.h"
#include "isValidInteger.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

// Test the correct display of the structure
void testTreeConstruction() {

    // Create tree1
    Tree<int> tree1;
    int values1[] = {27, 42, 48, 50, 47, 33, 13, 17, 20, 6, 11, 1};

    for (int value : values1) {
        tree1.insertNode(value);
    }

    //Create tree2
    Tree<int> tree2;
    int values2[] = {50, 40, 30, 20, 10, 5, 1};  // Inserting in descending order

    for (int value : values2) {
        tree2.insertNode(value);
    }

    //Create tree3
    Tree<int> tree3;
    int values3[] = {1, 5, 10, 20, 30, 40, 50};  // Inserting in ascending order

    for (int value : values3) {
        tree3.insertNode(value);
    }

    std::cout << "\nTree Structure 1:\n\n";
    tree1.outputTree();

    std::cout << "\nLeft-Skewed Tree Structure:\n\n";
    tree2.outputTree();

    std::cout << "\nRight-Skewed Tree Structure:\n\n";
    tree3.outputTree();

    std::cout << "\nTest 1: Visually check if the structures are correctly represented.\n";
}

// Test the search function
void testSearchFunction() {
    Tree<int> tree;
    int values[] = {27, 42, 48, 50, 47, 33, 13, 17, 20, 6, 11, 1};

    for (int value : values) {
        tree.insertNode(value);
    }

    // Test that all inserted values can be found
    for (int value : values) {
        assert(tree.search(value) != nullptr);
    }

    // Test searching for non-existing values
    assert(tree.search(100) == nullptr);
    assert(tree.search(-10) == nullptr);
    assert(tree.search(30) == nullptr);

    std::cout << "\nTest 2: Search function passed all tests.\n";
}

void testCountNodes() {
    Tree<int> tree;
    assert(tree.countNodes() == 0); // Initially, tree should be empty
    
    tree.insertNode(10);
    assert(tree.countNodes() == 1);
    
    tree.insertNode(20);
    tree.insertNode(5);
    assert(tree.countNodes() == 3);
    
    tree.insertNode(5); // Duplicate, should not be counted
    assert(tree.countNodes() == 3);
    
    tree.insertNode(15);
    tree.insertNode(25);
    assert(tree.countNodes() == 5);
    
    std::cout << "\nTest 3: Count nodes test passed.\n";
}

//Test Edge cases (duplicate values and string inputs)
void testEdgeCases() {
    Tree<int> tree;
    
    // Test inserting duplicate values
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(5);  // Duplicate, should be ignored 
    tree.insertNode(10); // Duplicate, should be ignored
    tree.insertNode(15); // Duplicate, should be ignored

    // Check if tree structure remains correct
    assert(tree.search(10) != nullptr);
    assert(tree.search(5) != nullptr);
    assert(tree.search(15) != nullptr);
    assert(tree.search(20) == nullptr); // Ensure 20 is not present
    
    // Check that duplicates were not added
    assert(tree.countNodes() == 3); // Only 3 unique nodes should exist
    
    // Testing inserting a string input

    try {
        tree.insertNode(std::stoi("string")); // Converting string to int should fail
        assert(false); // If this line is reached, test should fail
    } catch(...){}

    // Test boundary values
    tree.insertNode(std::numeric_limits<int>::max());
    tree.insertNode(std::numeric_limits<int>::min());
    tree.insertNode(0);
    assert(tree.search(std::numeric_limits<int>::max()) != nullptr);
    assert(tree.search(std::numeric_limits<int>::min()) != nullptr);
    assert(tree.search(0) != nullptr);

    std::cout << "\nTest 4: Edge case tests passed.\n";
}

// Test different possible user input
void testIsValidInteger() {
    assert(isValidInteger("123") == true);
    assert(isValidInteger("-123") == true);
    assert(isValidInteger("0") == true);
    assert(isValidInteger("1 2") == false);
    assert(isValidInteger("abc") == false);
    assert(isValidInteger("12.3") == false);
    assert(isValidInteger("123abc") == false);
    assert(isValidInteger("") == false);
    assert(isValidInteger("   ") == false);

    std::cout << "\nTest 5: isValidInteger tests passed.\n";
}

// Test user input function
void testUserInputValidation() {
    std::istringstream input("hello\n3.14\ninvalid\n5 4\n27\n"); // Fixed invalid escape sequence
    std::cin.rdbuf(input.rdbuf());

    std::string inputStr;
    int searchValue = 0;
    bool validInputFound = false;

    while (std::getline(std::cin, inputStr)) {
        if (inputStr.empty()) continue;

        if (isValidInteger(inputStr)) {
            searchValue = std::stoi(inputStr);
            validInputFound = true;
            break;
        }
    }

    // Ensure we actually found a valid integer before asserting
    assert(validInputFound && searchValue == 27);
    std::cout << "\nTest 6: User input validation test passed.\n";
}

int main() {
    testTreeConstruction();
    testSearchFunction();
    testCountNodes();
    testEdgeCases();
    testIsValidInteger();
    testUserInputValidation();

    std::cout << "\nAll tests passed successfully!\n\n";
    return 0;
}