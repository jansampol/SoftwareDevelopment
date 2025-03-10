//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Exhaustive testing of the package delivery system.
//==============================================================

#include "../include/Customer.h"
#include "../include/PrivateCustomer.h"
#include "../include/BusinessCustomer.h"
#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Test creating Private Customers
void testPrivateCustomer() {
    cout << "Testing Private Customer..." << endl;
    PrivateCustomer p1("Alice", "123 Main St");
    assert(p1.getInfo().find("Alice") != string::npos);
    assert(p1.getAddress() == "123 Main St");
}

// Test creating Business Customers
void testBusinessCustomer() {
    cout << "Testing Business Customer..." << endl;
    BusinessCustomer b1("Tech Corp", "789 Oak St", "John Doe");
    assert(b1.getInfo().find("Tech Corp") !=string::npos);
    assert(b1.getAddress() == "789 Oak St");
}

// Test handling zero and negative weight
void testInvalidPackageWeights() {
    cout << "Testing Invalid Package Weights..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    TwoDayPackage packageZero(sender, receiver, 0);
    assert(packageZero.getWeight() == 0);
    assert(packageZero.calculateCost() == 5.0); // Only flat fee applies

    TwoDayPackage packageNegative(sender, receiver, -3);
    assert(packageNegative.getWeight() == 0);
    assert(packageNegative.calculateCost() == 5.0); // Only flat fee applies
}

// Test valid package creation and cost calculation
void testValidPackages() {
    cout << "Testing Valid Packages..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    TwoDayPackage package1(sender, receiver, 3);
    assert(package1.getWeight() == 3);
    assert(package1.calculateCost() == (3 * 2.5) + 5);

    OvernightPackage package2(receiver, sender, 2);
    assert(package2.getWeight() == 2);
    assert(package2.calculateCost() == (2 * 2.5) + 5 + (2 * 2 * 1.1));
}

// Test a business customer sending multiple packages
void testBusinessCustomerMultiplePackages() {
    cout << "Testing Business Customer with Multiple Packages..." << endl;
    BusinessCustomer sender("Tech Corp", "789 Oak St", "John Doe");
    PrivateCustomer receiver1("Alice", "123 Main St");
    BusinessCustomer receiver2("Marketing Ltd", "555 Pine St", "Sarah Lee");

    TwoDayPackage package1(sender, receiver1, 3); // sender -> receiver1
    OvernightPackage package2(sender, receiver2, 2); // sender -> receiver2

    // Verify if the cost is correclt computed
    assert(package1.calculateCost() ==(3 * 2.5) + 5);
    assert(package2.calculateCost() == (2 * 2.5) + 5 + (2 * 2 * 1.1));

    // Verify sender details
    assert(&package1.getSender() == &sender);
    assert(&package2.getSender() == &sender);

    // Verify receiver details
    assert(&package1.getReceiver() == &receiver1);
    assert(&package2.getReceiver() == &receiver2);
}

// Print package details for manual verification
void testPackagePrinting() {
    cout << "Testing Package Printing..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    TwoDayPackage package1(sender, receiver, 3);
    OvernightPackage package2(receiver, sender, 2);

    cout << "Package Details:" << endl;
    package1.print();
    cout << " - Shipping Cost: €" << package1.calculateCost() << endl;
    package2.print();
    cout << " - Shipping Cost: €" << package2.calculateCost() << endl;
}

// Main function
int main() {
    testPrivateCustomer(); // Ok
    testBusinessCustomer(); // Ok
    testInvalidPackageWeights();
    testValidPackages(); // Ok
    testBusinessCustomerMultiplePackages(); // Ok
    testPackagePrinting();
    cout << "All tests passed successfully! ✅" << endl;
    return 0;
}
