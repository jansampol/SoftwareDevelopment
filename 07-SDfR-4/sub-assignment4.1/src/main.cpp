//==============================================================
// Filename    : main.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Demonstrates the use of Package, TwoDayPackage, 
//               and OvernightPackage by calculating and displaying 
//               shipping costs for different packages.
//==============================================================

#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include <vector>

using namespace std;

// Prints package details and corresponding shipping cost
void printCosts(const vector<Package*>& packages) {
    for (const auto& package : packages) {
        package->print();
        cout << " - Shipping Cost: €" << package->calculateCost() << endl;
    }
}

int main() {
    // Create a list of packages with different shipping types
    vector<Package*> packages = {
        new TwoDayPackage("Alice", "123 Main St", "Bob", "456 Elm St", 3),
        new OvernightPackage("Charlie", "789 Oak St", "David", "101 Pine St", 2),
        new TwoDayPackage("Eve", "202 Maple St", "Frank", "303 Cedar St", 5)
    };

    // Print the cost of each package
    printCosts(packages);

    // Free allocated memory
    for (auto package : packages) {
        delete package;
    }

    return 0;
}
