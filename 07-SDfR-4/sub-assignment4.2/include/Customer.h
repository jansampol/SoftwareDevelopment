//==============================================================
// Filename    : Customer.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Base class for different types of customers.
//==============================================================

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
private:
    // Customer address
    string address;

public:
    // Constructor to initialize customer details
    explicit Customer(string addr);

    // Getter method to retrieve customer address
    string getAddress() const;

    // Pure virtual function to enforce customer info retrieval in derived classes
    virtual string getInfo() const = 0;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Customer() {}
};

#endif
