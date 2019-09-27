//Noah Krill
#include "functions.hpp"//including the header
#include <iostream>
namespace cs2
{
	char *deleteRepeats(char originalArray[],int &counter)
	{
	    char *newArray= new char[SIZE];
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				char temp = originalArray[i];//getting temp to keep value of the original array
				if (originalArray[j] > originalArray[i])
				{
                    //Swaping the values from one array to the next
					temp = originalArray[j];
					originalArray[j] = originalArray[i];
					originalArray[i] = temp;
				}
			}
		}
		newArray[0]=originalArray[0];//setting one index to the other array
		for (int k = 0; k < SIZE-1; ++k)
		{
			int j=k+1;//adding one to index k and setting it to k
			if(originalArray[k]!=originalArray[j])//if indexs arent the same
            {
                newArray[counter]=originalArray[j];//setting new array at the index to the char
                counter++;//adding one to the counter
            }
		}
		return newArray;//return new array
		}

	}

