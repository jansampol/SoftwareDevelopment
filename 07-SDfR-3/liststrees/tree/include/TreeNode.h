//==============================================================
// Filename    : TreeNode.h
// Authors     : Teresa Edo and Jan Sampol
// Group       : 7
// License     :  N.A. or opensource license like LGPL
// Description : Definition of TreeNode class
//==============================================================

// Fig. 19.21: TreeNode.h
// TreeNode class-template definition.
#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
template<typename NODETYPE> class Tree;

// TreeNode class-template definition
template<typename NODETYPE>
class TreeNode {
   friend class Tree<NODETYPE>;

public:
   // constructor
    TreeNode(const NODETYPE &d)   
      : leftPtr(nullptr), // pointer to left subtree
        data(d), // tree node data
        rightPtr(nullptr) { // pointer to right substree
      // empty body 
    } // end TreeNode constructor

   // return copy of node's data
   NODETYPE getData() const {return data;}
   
private:
   TreeNode<NODETYPE>* leftPtr{nullptr}; // pointer to left subtree
   NODETYPE data; // the data
   TreeNode<NODETYPE>* rightPtr{nullptr}; // pointer to right subtree
   
}; // end class TreeNode

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
