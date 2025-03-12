//==============================================================
// Filename    : Customer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the base class for Customer
//==============================================================

#include "Customer.h"
using namespace std;

// Class constructor
Customer::Customer(string addr) : address(addr) {}

// Define getter method
string Customer::getAddress() const {
    return address;
}
