//Noah Krill
//cs2
//February 5 2018
//Section:includes different libraries and different hpps
#include <iostream>
#include<limits>
#include "Tax.hpp"
#include "TaxDataType.hpp"
#include "TaxConstants.hpp"
using namespace TAXCONSTANTS;//using custom made namespace
int main()
{
    float TaxesP[SIZE];
    taxTaker(TaxesP);
    taxPrint(TaxesP);
    return 0;
}


