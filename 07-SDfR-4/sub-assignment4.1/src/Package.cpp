//==============================================================
// Filename    : Package.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the Package class, which serves as a 
//               base class for different shipping package types.
//==============================================================

#include "Package.h"

using namespace std;

// Constructor initializes package details and ensures weight is non-negative
Package::Package(string s, string sAddr, string r, string rAddr, double w)
    : sender(s), senderAddress(sAddr), receiver(r), receiverAddress(rAddr), weight(w), valid(true) {
    if (w <= 0) {
        valid = false;  // Mark the package as invalid
    }}

// Getter methods to access private attributes
string Package::getSender() const { return sender; }
string Package::getSenderAddress() const { return senderAddress; }
string Package::getReceiver() const { return receiver; }
string Package::getReceiverAddress() const { return receiverAddress; }
double Package::getWeight() const { return weight; }
bool Package::isValid() const {return valid; }

// Prints package details
void Package::print() const {
    if (!valid) {
        cout << "Invalid Package (Weight: " << weight << "kg) from " << sender 
        << " to " << receiver << endl;
    } else {
        cout << "Package from " << sender << " to " << receiver
             << ", Weight: " << weight << "kg" << endl;
    }
}