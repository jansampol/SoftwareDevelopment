//==============================================================
// Filename    : Tree.h
// Authors     : Teresa Edo and Jan Sampol
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

// Fig. 19.22: Tree.h
// Tree class-template definition.
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value); 
   } 

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr); 
   } 

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr); 
   } 

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr); 
   } 
   
   // Public search function
    TreeNode<NODETYPE>* search(const NODETYPE& value) const {
        return searchHelper(rootPtr, value);
    }

   // Display the tree
   void outputTree(int space = 0, int spacingFactor = 5) const {
      outputTreeHelper(rootPtr, space, spacingFactor);
   }


private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(
      TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value < (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            // data to insert is greater than data in current node
            if (value > (*ptr)->data) { 
               insertNodeHelper(&((*ptr)->rightPtr), value);
            }
            else { // duplicate data value ignored
               std::cout << value << " dup" << std::endl;
            }
         } 
      } 
   } 

    // Recursive search helper function
    TreeNode<NODETYPE>* searchHelper(TreeNode<NODETYPE>* ptr, const NODETYPE& value) const {
        if (ptr == nullptr || ptr->data == value) {
            return ptr; // Found or reached null (not found)
        }

        if (value < ptr->data) {
            return searchHelper(ptr->leftPtr, value);
        } else {
            return searchHelper(ptr->rightPtr, value);
        }
    }

      void outputTreeHelper(TreeNode<NODETYPE>* ptr, int space, int spacingFactor) const {
      if (ptr == nullptr) {
         return;
      }
      // Increase distance for the next level
      space += spacingFactor;

      // Print right subtree first
      outputTreeHelper(ptr->rightPtr, space, spacingFactor);

      // Print current node after space indentation
      std::cout << std::string(space, ' ') << ptr->data << "\n";

      // Print left subtree
      outputTreeHelper(ptr->leftPtr, space, spacingFactor);
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node               
         preOrderHelper(ptr->leftPtr); // traverse left subtree  
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      } 
   } 

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree  
         std::cout << ptr->data << ' '; // process node              
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      } 
   } 

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) { 
         postOrderHelper(ptr->leftPtr); // traverse left subtree  
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node                
      } 
   } 
}; 

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
