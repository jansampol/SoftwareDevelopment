//==============================================================
// File name   : main.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Manages customers and packages, ensuring different 
//               types of customers are properly linked to packages.
//==============================================================

#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include "PrivateCustomer.h"
#include "BusinessCustomer.h"
#include "PackagePrinter.h" 
#include <vector>
#include <set>

using namespace std;

int main() {
    // Create customers
    vector<Customer*> customers = {
        new PrivateCustomer("Alice", "123 Main St"),
        new PrivateCustomer("Bob", "456 Elm St"),
        new PrivateCustomer("Charlie", "789 Oak St"),
        new BusinessCustomer("TechCorp", "101 Pine St", "David"),
        new BusinessCustomer("LogiTrans", "202 Maple St", "Eve"),
        new BusinessCustomer("MegaMart", "303 Cedar St", "Frank"),
        new BusinessCustomer("Mercadona", "Avenida Madrid, 28", "Maria Jose")
    };

    // Create packages
    vector<Package*> packages = {
        new TwoDayPackage(*customers[0], *customers[1], 3),  // Alice to Bob
        new OvernightPackage(*customers[3], *customers[2], 2), // TechCorp to Charlie
        new TwoDayPackage(*customers[4], *customers[5], 5),   // LogiTrans to MegaMart
        new OvernightPackage(*customers[3], *customers[5], 4), // TechCorp to MegaMart (Multiple packages)
        new TwoDayPackage(*customers[3], *customers[1], 0)
    };

    printCosts(packages);  // Print the costs of the packages
    printCustomerInfo(customers);  // Print customer information
    printChristmasCardContactPersons(packages);  // Print Christmas card contact list

    // Cleanup memory
    for (auto package : packages) delete package;
    for (auto customer : customers) delete customer;

    return 0;
}
