//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Testing of the package delivery system.
//==============================================================

#include "Customer.h"
#include "PrivateCustomer.h"
#include "BusinessCustomer.h"
#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include "PackagePrinter.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <sstream>

using namespace std;

// Test creating Private Customers
void testPrivateCustomer() {
    cout << "\nTesting Private Customer..." << endl;
    PrivateCustomer p1("Alice", "123 Main St");
    // Check if name and address are correctly assigned
    assert(p1.getInfo().find("Alice") != string::npos);
    assert(p1.getAddress() == "123 Main St");
    // If the test successfully pass, print the message
    cout << "Private Customer creation Tests Passed Successfully!" << endl;
}

// Test creating Business Customers
void testBusinessCustomer() {
    cout << "\nTesting Business Customer..." << endl;
    BusinessCustomer b1("Tech Corp", "789 Oak St", "John Doe");
    // Check if business name, address, and contact person are correctly assigned
    assert(b1.getInfo().find("Tech Corp") != string::npos);
    assert(b1.getAddress() == "789 Oak St");
    assert(b1.getContactPerson() == "John Doe");  // Ensure contact person is correctly set
    // If the test successfully pass, print the message
    cout << "Business Customer creation Tests Passed Successfully!" << endl;
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

    cout << "\nCheck the output above manually to ensure it matches the expected format." << endl;
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

void testPrintCustomerInfo() {
    cout << "\nTesting printCustomerInfo..." << endl;

    // Create customers
    vector<Customer*> customers = {
        new PrivateCustomer("Alice", "123 Main St"),
        new PrivateCustomer("Bob", "456 Elm St"),
        new BusinessCustomer("TechCorp", "101 Pine St", "David")
    };

    // Call function
    printCustomerInfo(customers);

    cout << "\nCheck the output above manually to ensure it matches the expected format.\n" << endl;

    // Cleanup
    for (auto customer : customers) delete customer;
}

void testPrintChristmasCardContactPersons() {
    cout << "\nTesting printChristmasCardContactPersons..." << endl;

    // Create customers
    BusinessCustomer* business1 = new BusinessCustomer("TechCorp", "101 Pine St", "David");
    BusinessCustomer* business2 = new BusinessCustomer("LogiTrans", "202 Maple St", "Eve");
    PrivateCustomer* private1 = new PrivateCustomer("Alice", "123 Main St");
    BusinessCustomer* business3 = new BusinessCustomer("Mercadona", "Avenida Madrid, 20", "Maria Jose"); // Business customer that doesn't send or receive

    // Create packages linking them
    vector<Package*> packages = {
        new TwoDayPackage(*business1, *private1, 3), // TechCorp -> Alice
        new OvernightPackage(*private1, *business2, 2) // Alice -> LogiTrans
    };

    // Redirect cout to a string stream
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    // Call function
    printChristmasCardContactPersons(packages);

    // Restore cout
    cout.rdbuf(old);

    // Expected output
    string expectedOutput =
        "=== Christmas Card Contact List ===\n"
        "David\n"
        "Eve\n"
        "===================================\n\n";

    // Generated output
    cout << "\nGenerated Output:\n" << buffer.str() << endl;

    // Verify
    assert(buffer.str() == expectedOutput);

    cout << "printChristmasCardContactPersons Test Passed Successfully!\n" << endl;

    // Cleanup
    for (auto package : packages) delete package;
    delete business1;
    delete business2;
    delete private1;
}


// Main function
int main() {
    testPrivateCustomer();
    testBusinessCustomer(); 
    testInvalidPackageWeights(); 
    testValidPackages();
    testBusinessCustomerMultiplePackages(); 
    testPackagePrinting();
    testLargePackageWeights(); 
    testPrintCustomerInfo();
    testPrintChristmasCardContactPersons();

    cout << "\nAll tests passed successfully!\n" << endl;
    return 0;
}