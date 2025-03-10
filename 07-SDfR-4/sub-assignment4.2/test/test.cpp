//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Testing of the package delivery system.
//==============================================================

#include "../include/Customer.h"
#include "../include/PrivateCustomer.h"
#include "../include/BusinessCustomer.h"
#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept> // For handling exceptions

using namespace std;

// Test creating Private Customers
void testPrivateCustomer() {
    cout << "\nTesting Private Customer..." << endl;
    PrivateCustomer p1("Alice", "123 Main St");
    // Check if name and address are correctly assigned
    assert(p1.getInfo().find("Alice") != string::npos);
    assert(p1.getAddress() == "123 Main St");
}

// Test creating Business Customers
void testBusinessCustomer() {
    cout << "\nTesting Business Customer..." << endl;
    BusinessCustomer b1("Tech Corp", "789 Oak St", "John Doe");
    // Check if business name, address, and contact person are correctly assigned
    assert(b1.getInfo().find("Tech Corp") != string::npos);
    assert(b1.getAddress() == "789 Oak St");
    assert(b1.getContactPerson() == "John Doe");  // Ensure contact person is correctly set
}

// Test handling zero and negative weight
void testInvalidPackageWeights() {
    cout << "\nTesting Invalid Package Weights...\n" << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    // Test zero weight - this should trigger a check that the package is invalid
    TwoDayPackage packageZero(sender, receiver, 0);
    assert(!packageZero.isValid());  // Package is invalid due to zero weight
    packageZero.print();

    // Test negative weight - this should trigger a check that the package is invalid
    OvernightPackage packageNegative(sender, receiver, -3);
    assert(!packageNegative.isValid());  // Package is invalid due to negative weight
    packageNegative.print();

    cout << "\nInvalid Package Weight Tests Passed Successfully!" << endl;
}

// Test valid package creation and cost calculation
void testValidPackages() {
    cout << "\nTesting Valid Packages..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    // Create a valid TwoDayPackage with 3 kg weight
    TwoDayPackage package1(sender, receiver, 3);
    assert(package1.getWeight() == 3);
    assert(package1.calculateCost() == (3 * 2.5) + 5);

    // Create a valid OvernightPackage with 2 kg weight
    OvernightPackage package2(receiver, sender, 2);
    assert(package2.getWeight() == 2);
    assert(package2.calculateCost() == (2 * 2.5) + 5 + (2 * 2 * 1.1));

    cout << "Valid Package Tests Passed Successfully!\n" << endl;
}

// Test a business customer sending multiple packages
void testBusinessCustomerMultiplePackages() {
    cout << "\nTesting Business Customer with Multiple Packages..." << endl;
    BusinessCustomer sender("Tech Corp", "789 Oak St", "John Doe");
    PrivateCustomer receiver1("Alice", "123 Main St");
    BusinessCustomer receiver2("Marketing Ltd", "555 Pine St", "Sarah Lee");

    // Create multiple packages
    TwoDayPackage package1(sender, receiver1, 3); // sender -> receiver1
    OvernightPackage package2(sender, receiver2, 2); // sender -> receiver2

    // Verify if the cost is correctly computed for both packages
    assert(package1.calculateCost() == (3 * 2.5) + 5);
    assert(package2.calculateCost() == (2 * 2.5) + 5 + (2 * 2 * 1.1));

    // Verify sender details are correct
    assert(&package1.getSender() == &sender);
    assert(&package2.getSender() == &sender);

    // Verify receiver details are correct
    assert(&package1.getReceiver() == &receiver1);
    assert(&package2.getReceiver() == &receiver2);

    cout << "Business Customer Multiple Packages Tests Passed Successfully!\n" << endl;
}

// Print package details for manual verification
void testPackagePrinting() {
    cout << "\nTesting Package Printing..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    TwoDayPackage package1(sender, receiver, 3);
    OvernightPackage package2(receiver, sender, 2);

    // Printing details for verification
    cout << "\nPackage Details:\n" << endl;
    package1.print();
    cout << " - Shipping Cost: €" << package1.calculateCost() << endl;
    package2.print();
    cout << " - Shipping Cost: €" << package2.calculateCost() << endl;

    cout << "\nPackage Printing Test Passed Successfully!" << endl;
}

// Test very large weights
void testLargePackageWeights() {
    cout << "\nTesting Large Package Weights..." << endl;
    PrivateCustomer sender("Alice", "123 Main St");
    BusinessCustomer receiver("Tech Corp", "789 Oak St", "John Doe");

    // Test large weight
    TwoDayPackage package(sender, receiver, 1000); // 1000kg package
    assert(package.getWeight() == 1000); 
    cout << "Large weight package test passed successfully!" << endl;
}

// Test empty customer names or addresses
void testEmptyCustomerFields() {
    cout << "\nTesting Empty Customer Fields...\n" << endl;
    PrivateCustomer emptyNameCustomer("", "123 Main St");
    BusinessCustomer emptyAddressCustomer("Tech Corp", "", "John Doe");

    // Verify empty fields are correctly handled
    assert(emptyNameCustomer.getInfo().empty()); // Expecting empty name
    assert(emptyAddressCustomer.getAddress().empty()); // Expecting empty address

    cout << "\nEmpty Customer Fields Test Passed Successfully!\n" << endl;
}

// Main function
int main() {
    testPrivateCustomer(); // Ok
    testBusinessCustomer(); // Ok
    testInvalidPackageWeights(); // Ok
    testValidPackages(); // Ok
    testBusinessCustomerMultiplePackages(); // Ok
    testPackagePrinting(); // Ok
    testLargePackageWeights(); // Ok
    //testEmptyCustomerFields(); // Ok

    cout << "\nAll tests passed successfully!\n" << endl;
    return 0;
}
