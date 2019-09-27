//Noah Krill
//CS2
//5/2/19
//This program uses objects, recursion and everything learned in cs2 to make a working tower of hanoi.

#include <iostream>
#include "towers.h"
#include "mystack.h"
#include <cstdlib>

//This is a destructor to free up the memory
Towers::~Towers()
{
    delete peg1;
    delete peg2;
    delete peg3;
}
//This function constructs the towers/stacks
Towers::Towers(int diskSize)
{

    MyStack<int> temp(diskSize);//making a temp stack with the size of disk size
    MyStack<int> temp2(diskSize);
    MyStack<int> temp3(diskSize);

    peg1 = &temp;
    peg2 = &temp2;
    peg3 = &temp3;

    setDisks();//calling the function to set up the disks and start the game off right
    move(diskSize,peg1,peg2,peg3);
}

//This function is the copy constructor and
//it copies all the elements from the obj
//into a new obj
Towers::Towers(const Towers& obj)
{
    numDisk = obj.numDisk;
}

Towers& Towers::operator=(const Towers& obj)
{
    this->numDisk = obj.numDisk;
    return *this;
}
//Section this function sets up the pegs in the proper starting positions
void Towers::setDisks()
{
//This sets up every peg in order from 4 at the base
//to 1 at the top
    for(int i = 4; !peg1->isFull(); --i)
    {
        peg1->push(i);
    }
//These functions say while peg2/3 are not empty
//pop every element on the stack
    while(!peg2->isEmpty())
    {
        peg2->pop();
    }

    while(!peg3->isEmpty())
    {
        peg3->pop();
    }

    plotPegs();

}
//This section is the standard move function for the pegs
void Towers::move(int diskSize, MyStack<int>* a, MyStack<int>* b, MyStack<int>* c)
{
    if(diskSize== 0)//If the disksize is  = 0
    {
        moveOne(a,b);
        plotPegs();//calls the plot (Which basically is a glorified print function)
        if(b->isFull())//If the peg 3 is full you won
            exit(0);
    }

    if(diskSize >= 1)
    {
        move(diskSize-1, a, c, b);//call the move function recursivly and switch peg 2 and peg 3
        moveOne(a,b);
        plotPegs();
        move(diskSize-1,c, b, a);//calls the move function again and swaps them all around
    }


}
//This functions removes an item from one stack/peg and moves it to another
void Towers::moveOne(MyStack<int>* a, MyStack<int>* b)
{
    //moving the value from one stack/tower to another by
    //popping/removing the value from one/tower
    //and pushing/adding the value to another
    b->push(a->pop());
}


//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
    if (peg1==NULL || peg2==NULL || peg3==NULL) return;


    int n1=peg1->size();
    int n2=peg2->size();
    int n3=peg3->size();
    int numDisk = n1+n2+n3;

    MyStack<int> tmp1(*peg1);
    MyStack<int> tmp2(*peg2);
    MyStack<int> tmp3(*peg3);


    //plot
    for (int i=0; i<numDisk; i++) {
        //peg1
        if (numDisk-n1-i>0) {
            for (int j=0; j<numDisk; j++)
                std::cout << " ";
        }
        else {
            int m1 = tmp1.top();
            tmp1.pop();
            for (int j=0; j<m1; j++)
                std::cout << "*";
            for (int j=m1; j<numDisk; j++)
                std::cout << " ";
        }
        std::cout <<" | ";

        //peg2
        if (numDisk-n2-i>0) {
            for (int j=0; j<numDisk; j++)
                std::cout << " ";
        }
        else {
            int m2 = tmp2.top();
            tmp2.pop();
            for (int j=0; j<m2; j++)
                std::cout << "*";
            for (int j=m2; j<numDisk; j++)
                std::cout << " ";
        }
        std::cout <<" | ";

        //peg3
        if (numDisk-n3-i>0) {
            for (int j=0; j<numDisk; j++)
                std::cout << " ";
        }
        else {
            int m3 = tmp3.top();
            tmp3.pop();
            for (int j=0; j<m3; j++)
                std::cout << "*";
            for (int j=m3; j<numDisk; j++)
                std::cout << " ";
        }
        std::cout<<std::endl;
    }
    std::cout << "_________________________________________\n";

}

