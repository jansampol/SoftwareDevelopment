//==============================================================
// Filename    : Package.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the base class for Package
//==============================================================

#include "../include/Package.h"
using namespace std;

Package::Package(const Customer& s, const Customer& r, double w)
    : sender(s), receiver(r), weight(w > 0 ? w : 0) {}

const Customer& Package::getSender() const {
    return sender;
}

const Customer& Package::getReceiver() const {
    return receiver;
}

double Package::getWeight() const {
    return weight;
}

void Package::print() const {
    cout << "Package from " << sender.getInfo() << " to " << receiver.getInfo()
         << ", Weight: " << weight << "kg";
}