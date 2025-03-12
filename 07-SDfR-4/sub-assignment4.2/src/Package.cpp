//==============================================================
// Filename    : Package.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Implements the base class for Package
//==============================================================

#include "../include/Package.h"

Package::Package(const Customer& s, const Customer& r, double w) 
    : sender(s), receiver(r), weight(w), valid(true) {
    if (w <= 0) {
        valid = false;  // Mark the package as invalid
    }
}

// Define the getter methods
const Customer& Package::getSender() const {return sender;}
const Customer& Package::getReceiver() const {return receiver;}
double Package::getWeight() const {return weight;}
double Package::getCostPerKg() {return COST_PER_KG;}
double Package::getFlatFee() {return FLAT_FEE;}

// Define the isValid method
bool Package::isValid() const {return valid;}


// Define the print() method. We do it here because is commot to all type of packages
void Package::print() const {
    if (!valid) {
        cout << "Invalid Package (Weight: " << weight << "kg) from " << sender.getInfo() 
        << " to " << receiver.getInfo() << endl;
    } else {
        cout << "Package from " << sender.getInfo() << " to " << receiver.getInfo()
             << ", Weight: " << weight << "kg" << endl;
    }
}