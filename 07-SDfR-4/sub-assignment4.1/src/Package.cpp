//==============================================================
// Filename    : Package.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "Package.h"
using namespace std;

Package::Package(string s, string sAddr, string r, string rAddr, double w)
    : sender(s), senderAddress(sAddr), receiver(r), receiverAddress(rAddr), weight(w > 0 ? w : 0) {}

string Package::getSender() const { return sender; }
string Package::getSenderAddress() const { return senderAddress; }
string Package::getReceiver() const { return receiver; }
string Package::getReceiverAddress() const { return receiverAddress; }
double Package::getWeight() const { return weight; }

void Package::print() const {
    cout << "Package from " << sender << " to " << receiver << ", Weight: " << weight << "kg";
}

