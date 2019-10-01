/*
   COPYRIGHT (C) 2017 Noah Krill (nlk34) All rights reserved.
   CSII assignment
   Author.  Noah Krill
           nlk34@zips.uakron.edu
   Version. 1.01 09.09.2017
*/
// Implementation file for the NumStack class
#include <iostream>
#include "NumStack.hpp"
// Constructor                                  
// This constructor creates an empty stack. The
// size parameter is the size of the stack.
template<class R>
NumStack<R>::NumStack(int size)
{
   stackArray = new R[size];
   stackSize = size;
   top = -1;
}
// Copy constructor

template<class R>
NumStack<R>::NumStack(const NumStack &obj)
{
   // Create the stack array.
   if (obj.stackSize > 0)
      stackArray = new R[obj.stackSize];
   else
      stackArray = nullptr;

   // Copy the stackSize attribute.
   stackSize = obj.stackSize;

   // Copy the stack contents.
   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];

   // Set the top of the stack.
   top = obj.top;
}
// Destructor
template<class R>
NumStack<R>::~NumStack()
{
   delete [] stackArray;
}
// Member function push pushes the argument onto
// the stack.

template<class R>
void NumStack<R>::push(R num)
{
   if (isFull())
   {
      std::cout << "The stack is full.\n";
   }
   else
   {
      top++;
      stackArray[top] = num;
   }
}
// Member function pop pops the value at the top
// of the stack off, and copies it into the variable
// passed as an argument.

template<class R>
void NumStack<R>::pop(R &num)
{
   if (isEmpty())
   {
      std::cout << "The stack is empty.\n";
   }
   else
   {
      num = stackArray[top];
      top--;
   }
}


// Member function isFull returns true if the stack
// is full, or false otherwise.

template<class R>
bool NumStack<R>::isFull() const
{
   bool status;

   if (top == stackSize - 1)
      status = true;
   else
      status = false;

   return status;
}

// Member function isEmpty returns true if the stack
// is empty, or false otherwise.

template<class R>
bool NumStack<R>::isEmpty() const
{
   bool status;

   if (top == -1)
      status = true;
   else
      status = false;

   return status;
}
template class NumStack <int>;
template class NumStack <double>;
