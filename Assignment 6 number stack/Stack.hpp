//Noah Krill
//3/12/2019
//cs2

#ifndef STACK_HPP
#define STACK_HPP
#include "NumStack.hpp"
template<class T>
class Stack : public NumStack<T>
{
public:
   // Constructor
   Stack(int s) : NumStack<T>(s) {}
   // MathStack operations
   void add();
   void sub();
   void mult();
   void div();
   void addAll();
   void multAll();
};

#endif // STACK_HPP_INCLUDED
