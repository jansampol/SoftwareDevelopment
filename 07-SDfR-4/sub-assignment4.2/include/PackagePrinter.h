//==============================================================
// Filename    : Package.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : Declaration of all printer functions
//==============================================================

#ifndef PACKAGE_PRINTER_H
#define PACKAGE_PRINTER_H

#include "../include/Package.h"
#include "../include/Customer.h"
#include <vector>

// Declare the diffrenet printer functions of PackagePrinter.cpp
void printCosts(const std::vector<Package*>& packages);
void printCustomerInfo(const std::vector<Customer*>& customers);
void printChristmasCardContactPersons(const std::vector<Package*>& packages);

#endif
