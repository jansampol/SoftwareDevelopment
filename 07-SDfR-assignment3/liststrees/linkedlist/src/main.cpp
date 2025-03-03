//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include "List.h"

int main() {  

    // Instantiate two empty linked lists of type char
    List<char> list1;
    List<char> list2;

    // Fill the lists with strings
    fillList("singlylinkedlist", list1);
    fillList("abcdefg", list2);

    // Print the lists to verify contents
    std::cout << "List 1: ";
    list1.print();

    std::cout << "List 2: ";
    list2.print();

    return 0;
}
