//==============================================================
// Filename    : PrivateCustomer.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the PrivateCustomer class
//==============================================================

#include "../include/PrivateCustomer.h"
using namespace std;

PrivateCustomer::PrivateCustomer(string n, string addr) : Customer(addr), name(n) {}

string PrivateCustomer::getInfo() const {
    return "Private Customer: " + name + ", Address: " + getAddress();
}