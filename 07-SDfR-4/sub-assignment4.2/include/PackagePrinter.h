//==============================================================
// Filename    : Package.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or open-source license like LGPL
// Description : 
//==============================================================

#ifndef PACKAGE_PRINTER_H
#define PACKAGE_PRINTER_H

#include "../include/Package.h"
#include "../include/Customer.h"
#include <vector>

void printCosts(const std::vector<Package*>& packages);
void printCustomerInfo(const std::vector<Customer*>& customers);
void printChristmasCardContactPersons(const std::vector<Package*>& packages);

#endif // PACKAGE_PRINTER_H
