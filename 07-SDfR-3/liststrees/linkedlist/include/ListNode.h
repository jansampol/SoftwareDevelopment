//==============================================================
// Filename    : ListNode.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : Definition of ListNode class
//==============================================================

// Fig. 19.4: ListNode.h
// ListNode class-template definition.
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 12
template<typename NODETYPE> class List;                            

template<typename NODETYPE> 
class ListNode {
   friend class List<NODETYPE>; // make List a friend

public:
    // constructor
    explicit ListNode(const NODETYPE& info) 
      : data{info}, nextPtr{nullptr} {   
          // empty body
    } // end ListNode constructor

    // return copy of data in node
   NODETYPE getData() const {return data;} 
   
private:
   NODETYPE data; // data
   ListNode<NODETYPE>* nextPtr; // pointer to next node in list
   
};    // end class ListNode

#endif

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
