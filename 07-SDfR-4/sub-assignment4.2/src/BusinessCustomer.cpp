//==============================================================
// Filename    : BusinessCustomer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the BusinessCustomer class
//==============================================================

#include "../include/BusinessCustomer.h"
using namespace std;

BusinessCustomer::BusinessCustomer(string cName, string addr, string contact)
    : Customer(addr), companyName(cName), contactPerson(contact) {}

string BusinessCustomer::getInfo() const {
    return "Business Customer: " + companyName + ", Contact Person: " + contactPerson + ", Address: " + getAddress();
}