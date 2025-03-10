//==============================================================
// Filename    : Customer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the base class for Customer
//==============================================================

#include "Customer.h"
using namespace std;

Customer::Customer(string addr) : address(addr) {}

string Customer::getAddress() const {
    return address;
}
