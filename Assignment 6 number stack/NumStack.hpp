//Noah Krill
//3/12/2019
//cs2
#ifndef NUMSTACK_HPP_INCLUDED
#define NUMSTACK_HPP_INCLUDED

template<class R>
class NumStack
{
private:
   R *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int top;          // Indicates the top of the stack

public:
   // Constructor
   NumStack<R>(int);

   // Copy constructor
   NumStack<R>(const NumStack<R> &);

   // Destructor
   ~NumStack();

   // Stack operations
   void push(R);
   void pop(R &);
   bool isFull() const;
   bool isEmpty() const;

};

#endif // NUMSTACK_HPP_INCLUDED
