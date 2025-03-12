//==============================================================
// Filename    : PrivateCustomer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the PrivateCustomer class
//==============================================================

#include "PrivateCustomer.h"
using namespace std;

// Class constructor
PrivateCustomer::PrivateCustomer(string n, string addr) : Customer(addr), name(n) {}

// Getter definition
string PrivateCustomer::getInfo() const {
    return "Private Customer: " + name + ", Address: " + getAddress();
}