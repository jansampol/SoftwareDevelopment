//==============================================================
// Filename    : Package.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : 
//==============================================================

#include "PackagePrinter.h"
#include "BusinessCustomer.h"
#include <iostream>
#include <set>

using namespace std;

// Print package shipping cost
void printCosts(const vector<Package*>& packages) {
    cout << "\n=== Packages cost ===\n" << endl;
    for (const auto& package : packages) {
        package->print();
        if (package->isValid())
            cout << " - Shipping Cost: €" << package->calculateCost() << endl << endl;
    }
}

// Print all customer information
void printCustomerInfo(const vector<Customer*>& customers) {
    cout << "\n=== Customer Information ===" << endl;
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
