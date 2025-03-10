//==============================================================
// Filename    : 
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include <vector>
using namespace std;

void printCosts(const vector<Package*>& packages) {
    for (const auto& package : packages) {
        package->print();
        cout << " - Shipping Cost: €" << package->calculateCost() << endl;
    }
}

int main() {
    vector<Package*> packages = {
        new TwoDayPackage("Alice", "123 Main St", "Bob", "456 Elm St", 3),
        new OvernightPackage("Charlie", "789 Oak St", "David", "101 Pine St", 2),
        new TwoDayPackage("Eve", "202 Maple St", "Frank", "303 Cedar St", 5)
    };

    printCosts(packages);

    // Clean up memory
    for (auto package : packages) {
        delete package;
    }

    return 0;
}
