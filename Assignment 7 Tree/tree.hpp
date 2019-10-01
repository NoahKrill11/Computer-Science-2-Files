/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  noah krill
            nlk34@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ...
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

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

   // get the depth of the tree
   int getDepth()  {
      int totalDepth{0};
      int currentDepth{0};

      determineDepth(rootPtr, & totalDepth, & currentDepth);
      return totalDepth;
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val)  {
      return binarySearchHelper(rootPtr, val);
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
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
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

//This section will take the root, the depth, and the current depth
//while the root doesnt equal nullpoiter it will search both sides of
//the tree until it reaches null ptr and returns the biggest sides depth

 void determineDepth(TreeNode<NODETYPE>* RootPtr,int*totalDepth,int *currentDepth)
{
if(RootPtr != nullptr)
    {
        int *current = new int;
        *current= *currentDepth;

        if (*current > *totalDepth)//if the current is bigger then the total make total eqaul to the current depth
        {
            *totalDepth = *current;
        }
        ++(*current);
        determineDepth(RootPtr->leftPtr, totalDepth, current);//recursivly calling the function to search the left side

        *current = *currentDepth;
        if (*current > *totalDepth)
        {
            *totalDepth = *current;
        }
        ++(*current);
        determineDepth(RootPtr->rightPtr, totalDepth, current);//recursivly calling the function to search the right side
    }


}
//This section will take the root, the depth, and the current depth
//once the item is found it will return the ptr
//and if its not found it will check if its less
//if it is it will call the left side of the tree
//and if its not found it will check if its right
//if it is it will call the right side of the tree

  TreeNode<NODETYPE>*binarySearchHelper(TreeNode<NODETYPE> * ptr, int val)
     {
    if(ptr==nullptr)
    {
        return ptr;
    }
    if (ptr->data < val){
        std::cout << "Comparing "<< val << " to "<<ptr->data <<"; Larger, walk right" <<std::endl;
       return binarySearchHelper(ptr->rightPtr, val);
    }
    if (ptr->data > val)
    {
    std::cout << "Comparing "<< val << " to "<<ptr->data <<"; Less, walk left" <<std::endl;
       return binarySearchHelper(ptr->leftPtr, val);
    }
    else
    {
        std::cout << "Comparing "<< val << " to "<<ptr->data <<"; Search complete" <<std::endl;
        return ptr;
    }
}

};

#endif // TREE_HPP
