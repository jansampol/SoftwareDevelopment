//==============================================================
// Filename    : BusinessCustomer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the BusinessCustomer class
//==============================================================

#include "BusinessCustomer.h"
using namespace std;

// Constructor
BusinessCustomer::BusinessCustomer(string cName, string addr, string contact)
    : Customer(addr), companyName(cName), contactPerson(contact) {}

// Define the virtual getInfo function for this class
string BusinessCustomer::getInfo() const {
    return "Business Customer: " + companyName + ", Contact Person: " + contactPerson + ", Address: " + getAddress();
}

// Define the getContactPerson() function by returning the variable contactPerson
string BusinessCustomer::getContactPerson() const {
    return contactPerson;
}