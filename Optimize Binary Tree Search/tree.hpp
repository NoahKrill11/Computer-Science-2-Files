//Noah Krill
//cs2
//project 3
//This project optimizes the trees functionality to make
//the depth the smallest it can be to make searching the tree
//and other things easier
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>
#include "treenode.hpp"
#include <cmath>

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   int count() //tell how many nodes within the tree
    {
        return numberOfNode(rootPtr);
    }

    void clear() //clear the tree
    {
        clearTree(rootPtr); //delete memory
        rootPtr = nullptr;
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

   void optimize()
   {
       optimizePrime(rootPtr);
   }

      int getDepth() const {
      int totalDepth{0};
      int currentDepth{0};
      determineDepth(rootPtr, &totalDepth, &currentDepth);
      return totalDepth;
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
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
         std::cout << ptr->data << ' ';
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' ';
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' ';
      }
   }

   // calculate the depth of the tree
   void determineDepth(TreeNode<NODETYPE>* rootPtr, int* totalDepth, int* currentDepth) const
   {
        // checks if node is null
      if (rootPtr != nullptr) {

         int* branch = new int;

         //sets branch == to current depth
         *branch = *currentDepth;

         if (*branch > *totalDepth)
         {
             *totalDepth = *branch;
         }
         ++(*branch);
         //left ptr recursion
         determineDepth(rootPtr->leftPtr, totalDepth, branch);

        //sets branch == to current depth
         *branch = *currentDepth;

         //sets totalDepth to branch if branch is larger
         if (*branch > *totalDepth)
         {
             *totalDepth = *branch;
         }
         ++(*branch);
         //right ptr recursion
         determineDepth(rootPtr->rightPtr, totalDepth, branch);
      }



   }
    //section returns number of nodes in the tree
    int numberOfNode(TreeNode<NODETYPE>* rootNode)
    {
        if(rootNode == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + numberOfNode(rootNode->leftPtr) + numberOfNode(rootNode->rightPtr);
        }
    }


    //clear the tree by recursively calling itself. Traverse through post-order
    void clearTree(TreeNode<NODETYPE>* rootNode)
    {
        if(rootNode != nullptr)
        {
            //using post-order to traverse all nodes of the from-tree
            clearTree(rootNode->leftPtr); //delete left subtree
            clearTree(rootNode->rightPtr); //delete right subtree
            delete rootNode; //delete the root node
            rootNode = nullptr;
        }
    }

   void inOrderOpt(TreeNode<NODETYPE>* ptr, int* n, int i) const {
      if (ptr != nullptr) {
         ++i;
         inOrderOpt(ptr->leftPtr, n, i); // traverse left subtree
         n[i] = ptr->data;
         inOrderOpt(ptr->rightPtr, n, i); // traverse right subtree
      }
   }

   void insertOptimize (int* arr, int size, int j)
    {
        int orig = size;
        if ((size % 2) == 1)// if the remainder after / by 2 equals 1 add one to the size
            ++size;
        int mid = size/2;
        insertNode(arr[mid]);
        for(int i = 1; i < j; ++i)
        {
            for(int k = 0; k < pow(2.0, i); ++k)
            {
                int insert = (size/(pow(2.0, i+1)))*(k*2 + 1);
                insertNode(arr[insert]);
            }
        }

        for(int i = 1; i <= orig; ++i)//inserting the numbers into the tree
        {
            //This function is virtually the same as "BinarySearchTree"
            //but it doesnt output the lines go left, go right etc
            if(!binaryTreeSearch(arr[i]))
            {
                insertNode(arr[i]);
            }

        }

    }

   void optimizePrime(TreeNode<NODETYPE>* rootNode)
   {
       //making an array with the size of the tree
       int counts= count();
       int temp[counts];
       inOrderOpt(rootNode, temp, 0);
       clear();//clears the tree
       int size = counts;
       if(size & 0x1)//using the and comparison to compare the size with bitwise
       {
           ++size;
       }
        int w = 0;
        while(size != 1)
        {
            ++w;
            size = size/2;
        }
       insertOptimize(temp, counts, w);

   }


   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* rootPtr, int val) const
   {
       // checks if node is null
        if (rootPtr == nullptr)
        {
            return rootPtr;
        }
        else if (rootPtr->data == val)
        {
            return rootPtr;
        }
        else if(rootPtr->data > val)
        {
            return binarySearchHelper(rootPtr->leftPtr, val);
        }
        else
        {
            return binarySearchHelper(rootPtr->rightPtr, val);
        }

   }


};

#endif // TREE_HPP

