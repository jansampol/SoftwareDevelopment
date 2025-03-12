//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Testing for Package, TwoDayPackage, and OvernightPackage.
//==============================================================

#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Test creating a TwoDayPackage
void testTwoDayPackage() {
    cout << "\nTesting TwoDayPackage..." << endl;
    TwoDayPackage package("Alice", "123 Main St", "Bob", "456 Elm St", 5);

    // Check if attributes are correctly assigned
    assert(package.getSender() == "Alice");
    assert(package.getReceiver() == "Bob");
    assert(package.getWeight() == 5);
    assert(package.isValid());

    // Check cost calculation: (weight * base rate) + fixed fee
    assert(package.calculateCost() == (5 * 2.5) + 5);

    cout << "TwoDayPackage test passed successfully!\n";
}

// Test creating an OvernightPackage
void testOvernightPackage() {
    cout << "\nTesting OvernightPackage..." << endl;
    OvernightPackage package("Charlie", "789 Oak St", "David", "101 Pine St", 2);

    // Check if attributes are correctly assigned
    assert(package.getSender() == "Charlie");
    assert(package.getReceiver() == "David");
    assert(package.getWeight() == 2);
    assert(package.isValid());

    // Check cost calculation: (weight * base rate) + fixed fee + (weight * overnight fee)
    assert(package.calculateCost() == (2 * 2.5) + 5 + (2 * 2 * 1.1));

    cout << "OvernightPackage test passed successfully!\n";
}

// Test invalid package weights
void testInvalidPackageWeights() {
    cout << "\nTesting Invalid Package Weights..." << endl;

    TwoDayPackage package1("Alice", "123 Main St", "Bob", "456 Elm St", 0);
    OvernightPackage package2("Charlie", "789 Oak St", "David", "101 Pine St", -3);

    assert(!package1.isValid()); // Should be invalid
    assert(!package2.isValid()); // Should be invalid

    cout << "Invalid Package Weights test passed successfully!\n";
}

// Test printing package details
void testPackagePrinting() {
    cout << "\nTesting Package Printing..." << endl;

    TwoDayPackage package1("Alice", "123 Main St", "Bob", "456 Elm St", 3);
    OvernightPackage package2("Charlie", "789 Oak St", "David", "101 Pine St", 2);

    package1.print(); // Print package 1
    package2.print(); // Print package 2

    cout << "Visually check if package printing test passed successfully\n";
}

// Main function to execute all tests
int main() {

    // Call all tester functions
    testTwoDayPackage();
    testOvernightPackage();
    testInvalidPackageWeights();
    testPackagePrinting();

    cout << "\nAll tests passed successfully!\n" << endl;
    return 0;
}