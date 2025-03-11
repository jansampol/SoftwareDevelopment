//==============================================================
// Filename    : BusinessCustomer.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Represents a business customer with a company name, 
//               address, and a contact person.
//==============================================================

#ifndef BUSINESSCUSTOMER_H
#define BUSINESSCUSTOMER_H

#include "Customer.h"

using namespace std;

class BusinessCustomer : public Customer {
private:
    // Business customer details
    string companyName;
    string contactPerson;

public:
    // Constructor to initialize business customer details
    BusinessCustomer(string cName, string addr, string contact);

    string getContactPerson() const;

    // Retrieves customer info
    string getInfo() const override;
};

#endif
