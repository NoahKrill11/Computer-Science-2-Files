//Noah Krill
//CSII
//Program will sort the array indexs and removes the repeated characters
//from the array
#include <iostream>//include libraries
#include <memory>
#include "functions.hpp"
using namespace cs2;//using made namespace

	int main()
	{
        int counter=1;
		char originalArray[SIZE];
		originalArray[0] = 'a';
		originalArray[1] = 'b';
		originalArray[2] = 'b';
		originalArray[3] = 'c';
		originalArray[4] = 'a';
		originalArray[5] = 'c';
		originalArray[6] = 'a';
		originalArray[7] = 'c';
		originalArray[8] = 'b';
		originalArray[9] = 'c';
		char * noRepeats = deleteRepeats(originalArray,counter);
		for (int i=0;i<counter;++i)
        {
            std::cout << noRepeats[i];
        }
        std::cout <<std::endl;
         std::cout << "Number of repeats removed " << counter << std::endl;
		return 0;
	}
