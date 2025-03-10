//==============================================================
// Filename    : PrivateCustomer.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Represents an individual customer with a name and address.
//==============================================================

#ifndef PRIVATECUSTOMER_H
#define PRIVATECUSTOMER_H

#include "Customer.h"

class PrivateCustomer : public Customer {
private:
    // Customer name
    string name;

public:
    // Constructor to initialize private customer details
    PrivateCustomer(string n, string addr);

    // Retrieves customer info
    string getInfo() const override;
};

#endif
