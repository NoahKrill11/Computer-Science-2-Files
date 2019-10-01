// Noah Krill
// This program will append,insert, and delete nodes
// on a linked list.
#include <iostream>//including library
#include "charList.hpp"//including user defined hpp file

int main()
{
   // Define a NumberList object.
   CharList list;
   list.appendNode('t');// Append characters values to the list.
   list.appendNode('s');
   list.appendNode('n');
   list.appendNode('m');
   list.appendNode('j');
   list.appendNode('f');
   list.appendNode('c');
   list.appendNode('a');
   list.insertNode('y');//Insert characters values in order from least to greatest
   list.insertNode('0');
   list.insertNode('9');
   list.insertNode('o');
   list.insertNode('p');
   list.insertNode('@');
   list.insertNode('Q');
   list.deleteNode('t');//delete the value/s
   list.displayList();//displays the list
   return 0;
}
