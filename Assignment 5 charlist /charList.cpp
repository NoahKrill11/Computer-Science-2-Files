/*
   COPYRIGHT (C) 2016 Noah Krill (nlk34) All rights reserved.
   CSII assignment 5 A
   Author.  Noah Krill
            nlk34@zips.uakron.edu
   Version. 1.01 09.09.2017

*/
// Implementation file for the NumberList class
//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************
#include <iostream>
#include "charList.hpp"
void CharList::displayList() const
{
   Node *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   short count = 0;

   // While nodePtr points to a node, traverse
   // the list.
    while (nodePtr)
   {
      // Display the value in this node.
      std::cout << "[" << nodePtr->value << "] -> ";
      ++count;
      // Move to the next node.
      nodePtr = nodePtr->next;
      if (count % 10 == 0) {
        std::cout << std::endl;
        count = 0;
      }
   }
   std::cout << std::endl;
}
    //This function will append nodes one right after another
    bool CharList::appendNode(char a)
        {
            Node* p;//create new node
            p=head;
            Node* tmp;
            try
            {
                tmp = new Node;
            }catch (...)
            {
                return false;
            }
            tmp ->value =a;
            tmp->next = nullptr;
            //find the last node
            if(p==nullptr)
            {
                head = tmp;
                //the list is empty
            }
            else
            {
                //loop through until it becomes a nullptr
                while(p->next != nullptr)
                {
                    p = p->next;
                }
                p->next = tmp;
            }
            return true;
        }
//This function inserts the node in order from least to the greatest
bool CharList::insertNode(char a)
{
    //insert the data smaller and a data larger
    Node *NewNode; //creates new nodes
    Node *p;
     try{
        NewNode = new Node();//makes NewNode a new node
    }catch(...)//if something goes wrong it will return false
    {
        return false;
    }
    NewNode->value = a;
    NewNode->next = nullptr;
    p=head;
    if(p==nullptr)
    {
        //the list is empty, just attach a  new node to head
        head = NewNode;
    }
    else
    {
        //loop through loop to find where to insert
        Node *previousP = nullptr;
        while(p != nullptr)
        {
            if(a >= p->value)
            {
                //the position is found
                //the new node will be inserted between previousP
                break; //break from the loop
            }
            previousP = p;
            p = p->next;
        }
        if (previousP == nullptr)
        {
            //need to insert before the first node of the list
            NewNode->next = p;
            head = NewNode;
        }
        else if(p == nullptr)
        {
            //need to insert after the last node
            previousP->next = NewNode;
        }
        else
        {
            previousP->next = NewNode;
            NewNode->next = p;
        }
    }
    return true;
}
//This function will delete a node if it is in the list
bool CharList::deleteNode(char a)
{
                Node *p;
                Node *previousP=nullptr;
                p=head;
                while(p!=nullptr)
                {
                    if(p->value==a)
                    {
                        //first step to assign prior node to node that follows
                        //second step
                        if(previousP==nullptr)
                        {
                            head =p->next;//deletes first node
                        }
                        else
                        {
                        previousP->next=p->next;
                        }
                        delete p;
                        return true;
                    }
                    previousP=p;
                    p=p->next;//move to next node
                }
                return false;
            }


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************

CharList::~CharList()
{
   Node *nodePtr;
   Node *nextNode;
   // Position nodePtr at the head of the list.
   nodePtr = head;
   // While nodePtr is not at the end of the list
   while (nodePtr != nullptr)
   {
      // stores nextNode = nodeptrs  next node.
      nextNode = nodePtr->next;
      // Delete the current node.
      delete nodePtr;
      // Move nodePtr at the next node.
      nodePtr = nextNode;
   }
}
