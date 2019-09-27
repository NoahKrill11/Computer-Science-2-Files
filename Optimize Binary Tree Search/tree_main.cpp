//Noah Krill
//cs2
//project 3
//This project optimizes the trees functionality to make
//the depth the smallest it can be to make searching the tree
//and other things easier
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<vector>
#include "tree.hpp"

int main()
{
    Tree<int> optTree;
    for (int i=1; i<=31; ++i)
        optTree.insertNode(i);
    optTree.inOrderTraversal();
    std::cout <<std::endl;
    std::cout << "The depth of the tree is "<< optTree.getDepth()<<std::endl;
    optTree.optimize();
    optTree.inOrderTraversal();
    std::cout <<std::endl;
    std::cout << "The depth of the tree is "<< optTree.getDepth()<<std::endl;
}
