//==============================================================
// Filename    : main.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Manages customers and packages, ensuring different 
//               types of customers are properly linked to packages.
//==============================================================

#include "../include/TwoDayPackage.h"
#include "../include/OvernightPackage.h"
#include "../include/PrivateCustomer.h"
#include "../include/BusinessCustomer.h"
#include <vector>
#include <set>

using namespace std;

void printCosts(const vector<Package*>& packages) {
    for (const auto& package : packages) {
        package->print();
        cout << " - Shipping Cost: €" << package->calculateCost() << endl << endl;
    }
}

// Print all customer information
void printCustomerInfo(const vector<Customer*>& customers) {
    cout << "=== Customer Information ===" << endl;
    for (const auto& customer : customers) {
        cout << customer->getInfo() << endl;  // Calls getInfo() dynamically
    }
    cout << "============================\n " << endl;
}
 
// Print Contact Names from active senders or receivers (Business customers)
void printChristmasCardContactPersons(const vector<Package*>& packages) {
    set<string> printedContacts;  // Track unique names

    cout << "=== Christmas Card Contact List ===" << endl;
    for (const auto& package : packages) {
        // Check sender
        const BusinessCustomer* sender = dynamic_cast<const BusinessCustomer*>(&package->getSender());
        if (sender) {
            string contact = sender->getContactPerson();
            if (printedContacts.find(contact) == printedContacts.end()) {
                cout << contact << endl;
                printedContacts.insert(contact);
            }
        }

        // Check receiver
        const BusinessCustomer* receiver = dynamic_cast<const BusinessCustomer*>(&package->getReceiver());
        if (receiver) {
            string contact = receiver->getContactPerson();
            if (printedContacts.find(contact) == printedContacts.end()) {
                cout << contact << endl;
                printedContacts.insert(contact);
            }
        }
    }
    cout << "===================================\n" << endl;
}

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
        new OvernightPackage(*customers[3], *customers[5], 4) // TechCorp to MegaMart (Multiple packages)
    };

    printCosts(packages);
    printCustomerInfo(customers);
    printChristmasCardContactPersons(packages);

    // Cleanup memory
    for (auto package : packages) delete package;
    for (auto customer : customers) delete customer;

    return 0;
}
