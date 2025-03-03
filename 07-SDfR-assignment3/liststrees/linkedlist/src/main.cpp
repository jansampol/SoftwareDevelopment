//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "List.h"

int main() {  
    // Create and fill the first two lists
    List<char> list1;
    List<char> list2;
    fillList("singlylinkedlist", list1);
    fillList("abcdefg", list2);

    // Print lists before concatenation

    std::cout << "List 1: ";
    list1.print();
    std::cout << "List 2: ";
    list2.print();

    // Create two new lists
    List<char> list3;
    List<char> list4;

    // Fill them with "hijklmnop" and "qrstuvw"
    fillList("hijklmnop", list3);
    fillList("qrstuvw", list4);

    // Print before second concatenation
    std::cout << "Before concatenation:\n";
    std::cout << "List 2: ";
    list2.print();
    std::cout << "List 3: ";
    list3.print();
    std::cout << "List 4: ";
    list4.print();

    // Concatenate list3 and list4 into list2 (which initially had "abcdefg" but was emptied)
    list2.concatenate(list3);
    list2.concatenate(list4);

    // Print the final appended list
    std::cout << "After concatenation:\n";
    std::cout << "List 2: ";
    list2.print();

    return 0;
}