//==============================================================
// Filename    : test.cpp
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     : N.A. or opensource license like LGPL
// Description : Tests the correct functioning of the program
//==============================================================

#include "List.h"
#include "fillList.h"
#include <iostream>
#include <sstream>
#include <cassert>

void testListInitialization() {
    List<char> list;
    assert(list.isEmpty() && "Test 1 failed: List is not empty after initialization.");
    std::cout << "\nTest 1: List initialization passed.\n";
}

void testFillList() {
    List<char> list;
    fillList("test", list);
    assert(!list.isEmpty() && "Test 2 failed: List is still empty after fillList.");
    std::cout << "Test 2: fillList function passed.\n";
}

void testPrintList() {
    List<char> list;
    fillList("abc", list);

    // Capture output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); 

    list.print();  

    std::cout.rdbuf(oldCout);  // Restore cout

    // Trim trailing whitespace
    std::string actual = buffer.str();
    actual.erase(actual.find_last_not_of(" \n\r\t") + 1);

    std::string expected = "The list is: a b c";
    assert(actual == expected && "Test 3 failed: List printing output incorrect.");

    std::cout << "Test 3: List printing passed.\n";
}

void testConcatenate() {
    List<char> list1;
    List<char> list2;
    fillList("abc", list1);
    fillList("def", list2);

    list1.concatenate(list2);

    // Ensure list2 is emptied
    assert(list2.isEmpty() && "Test 4 failed: list2 is not empty after concatenation.");

    // Capture output of list1.print()
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    list1.print();

    std::cout.rdbuf(oldCout);  // Restore cout

    // Trim trailing whitespace
    std::string actual = buffer.str();
    actual.erase(actual.find_last_not_of(" \n\r\t") + 1);

    std::string expected = "The list is: a b c d e f";
    assert(actual == expected && "Test 4 failed: Concatenation output incorrect.");

    std::cout << "Test 4: Concatenation passed.\n";
}

void testEdgeCases() {
    List<char> list1, list2;
    fillList("x", list1);
    list1.concatenate(list2);
    assert(!list1.isEmpty() && "Test 5 failed: Non-empty list became empty after concatenating with an empty list.");
    assert(list2.isEmpty() && "Test 5 failed: Empty list2 is not empty after concatenation.");

    List<char> list3, list4;
    list3.concatenate(list4);
    assert(list3.isEmpty() && list4.isEmpty() && "Test 5 failed: Concatenation of two empty lists should remain empty.");

    std::cout << "Test 5: Edge cases passed.\n";
}

int main() {
    testListInitialization();
    testFillList();
    testPrintList();
    testConcatenate();
    testEdgeCases();

    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}
