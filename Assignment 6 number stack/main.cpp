//Noah Krill
//3/12/2019
//cs2


// This program demonstrates the MathStack class.
#include <iostream>
#include "Stack.hpp"

int main()
{
    int catchInteger;   // To hold values
    double catchDouble;
    // Create a MathStack object.

    Stack<int> stackInt(5);
    Stack<double> stackDB(5);
    // Push 3 and 6 onto the stack.

    std::cout << "\nPushing 3\n";
    stackInt.push(3);
    std::cout << "Pushing 6\n";
    stackInt.push(6);

    // Add values.
    stackInt.add();

    // Pop the sum off the stack.
    std::cout << "The sum is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger << std::endl << std::endl;

    // Push 7 and 10 onto the stack
    std::cout << "Pushing 7\n";
    stackInt.push(7);
    std::cout << "Pushing 10\n";
    stackInt.push(10);

    // Subtract numbers on the stack
    stackInt.sub();

    // Pop the difference off the stack and display it.
    std::cout << "The difference is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger << std::endl;

    //Push ints  to the stack
    std::cout << "\nPushing 4\n";
    stackInt.push(4);
    std::cout << "Pushing 2\n";
    stackInt.push(2);

    //Multiply the 2 values
    stackInt.mult();

    //Pop the product off the stack
    std::cout << "The product is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger << std::endl;//displays the info to the user

    //Push two doubles to the stack
    std::cout << "\nPushing 45\n";
    stackInt.push(45);
    std::cout << "Pushing 2\n";
    stackInt.push(2);

    //Divide the 2 values
    stackInt.div();

    //Pop the quotient off the stack
    std::cout << "The quotient is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger << std::endl;//outputs info

    //Push 3 Values to the stackInt
    std::cout << "\nPushing 6\n";
    stackInt.push(6);
    std::cout << "Pushing 3\n";
    stackInt.push(3);
    std::cout << "Pushing 24\n";
    stackInt.push(24);
    //Add all values
    stackInt.addAll();

    std::cout << "The sum of all is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger <<std::endl;//outputs info to the user

    //Push 3 Values to the stack
    std::cout << "\nPushing 3\n";
    stackInt.push(3);
    std::cout << "Pushing 10\n";
    stackInt.push(10);
    std::cout << "Pushing 4\n";
    stackInt.push(4);

    //Add all values
    stackInt.multAll();

    //Display the product of all and pop it off the stack
    std::cout << "The product of all is ";
    stackInt.pop(catchInteger);
    std::cout << catchInteger <<std::endl;

    //Pushing doubles
    std::cout << "\nPushing 23.23\n";
    stackDB.push(23.23);
    std::cout << "Pushing 3.21\n";
    stackDB.push(3.21);

    // Add the two values.
    stackDB.add();

    // Pop the sum off the stack
    std::cout << "The sum is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble << std::endl;//outputs info to the user

    // Push more doubles onto the stack
    std::cout << "\nPushing 44.442\n";
    stackDB.push(44.442);
    std::cout << "Pushing 143.11\n";
    stackDB.push(143.11);


    // Subtract two values.
    stackDB.sub();

    // Pop the difference off the stack and display it.
    std::cout << "The difference is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble << std::endl;

    //Push two doubles to the stack
    std::cout << "\nPushing 10.34\n";
    stackDB.push(10.34);
    std::cout << "Pushing 34.3424\n";
    stackDB.push(34.3424);

    //Multiply the 2 values
    stackDB.mult();

    //Pop the product off the stack and display it
    std::cout << "The product is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble << std::endl;

    //Push two doubles to the stacks
    std::cout << "\nPushing 3.4\n";
    stackDB.push(3.4);
    std::cout << "Pushing 7.1\n";
    stackDB.push(7.1);

    //Divide the 2 values in FILO fashion
    stackDB.div();

    //Pop the quotient off the stack and display it
    std::cout << "The quotient is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble << std::endl;

    //Push 3 Values to the stackDB
    std::cout << "\nPushing 3.21\n";
    stackDB.push(3.21);
    std::cout << "Pushing 5.32\n";
    stackDB.push(5.32);
    std::cout << "Pushing 2.43\n";
    stackDB.push(2.43);
    //Add all values
    stackDB.addAll();

    //Display the sum of all and pop it off the stack
    std::cout << "The sum of all is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble <<std::endl;

    //Push 4 Values to the stack
    std::cout << "\nPushing 10.42\n";
    stackDB.push(10.42);
    std::cout << "Pushing 9.21\n";
    stackDB.push(9.21);
    std::cout << "Pushing 3.42\n";
    stackDB.push(3.42);

    //Add all values
    stackDB.multAll();

    //Display the product of all and pop it off the stack
    std::cout << "The product of all is ";
    stackDB.pop(catchDouble);
    std::cout << catchDouble <<std::endl;
    return 0;

}
