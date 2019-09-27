//Noah Krill
//CS2
//5/2/19

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "towers.h"

template <class T>
class MyStack
{
private:
    T *stackArray; // Pointer to the stack array
    int stackSize;    // The stack size
    int numElem;       //index of the top element in the stack array

public:
    // Constructor
    MyStack(int);   //pass in an int: tells the maximum size of the stack

    // Copy constructor
    MyStack(const MyStack &);

    //operator= overloading
    MyStack& operator=(const MyStack &);//copy assignment

    // Destructor
    ~MyStack();

    // Stack operations
    void push(T);   //add an item to the stack by passing in a value
    T pop();   //pop a value out by returning the value
    T top();   //return the value at the top position in the stack
    bool isFull() const;   //tell if the stack is full
    bool isEmpty() const;   //tell if the stack is empty
    int size() const;   //tell how many items are in the stack
};

//This function determines if the stack is full
template <class T>
bool MyStack<T>::isFull() const
{
    //if the number of elements in stack is equal to the
    //stack array size return true
    if (numElem == stackSize - 1)
        return true;
    else
        return false;
}
//Section::This function will determine if the stack is full
//if the number of elements on the stack is -1
//then the stack is empty.else its not empty
template<class T>
bool MyStack<T>::isEmpty() const
{
    if (numElem == -1)
        return true;
    else
        return false;
}
//Section::This is a destructor it deletes the
//stack array to free up the memory
template <class T>
MyStack<T>::~MyStack()
{
    delete [] stackArray;
}
//section this is the constructor
//it sets the object up so it can be used
template<class T>
MyStack<T>::MyStack(int size)
{
    stackSize = size;
    stackArray = new int[stackSize];
    numElem = -1;
}
//Section::This is the size function it returns the number of
//items that are in the stack
template <class T>
int MyStack<T>::size() const
{
    if (numElem == -1)
        return 0;
    else
        return (numElem+1);
}
//Section this is a copy constructor
template <class T>
MyStack<T>::MyStack(const MyStack &obj)
{
    if(obj.stackSize > 0)//if object size is greater then 0 then it will copy over the stack size to the new obj
    {
        stackArray = new T[obj.stackSize];
    }
    else
        stackArray = nullptr;

    stackSize = obj.stackSize;//the new stacksize will be the same as the other stack size

    for(int i = 0; i < stackSize; i++)
    {
        stackArray[i] = obj.stackArray[i];
    }

    numElem = obj.numElem;

}
//Section this is the assignment operater it allows
//you to set one obj/stack equal to another
template<class T>
MyStack<T>& MyStack<T>::operator=(const MyStack& obj)
{
    this-> stackSize = obj - stackSize;
    this-> number= obj - numElem;
    return *this;
}
//This section is the pop function
//it pops values off the stack aslong as the stack has items on it
template<class T>
T MyStack<T>::pop()
{
     int disk = stackArray[numElem];//setting disk equal to stackarray element at num element
    if (isEmpty())
    {}
    else
        numElem--;
    
    return disk;
}
//Section::This is the push function and will add things to the stack as long as the stack is not full
template<class T>
void MyStack<T>::push(T disk)
{
    if (isFull())
    { }
    else
    {
        numElem++;
        stackArray[numElem] = disk;//setting the array at the new index of numelement equal to the disk
    }
}
//This is the top function it returns the top of the stack
template<class T>
T MyStack<T>::top()
{
    if(numElem == -1)//if theres nothing on the stack return null
        return NULL;
    else
        return (stackArray[numElem]);//return the item of stack array at index numelm
}




#endif


