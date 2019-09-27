//Noah Krill
//cs2
//February 5 2019
//Section:includes different libraries and different hpps
#include "TaxDataType.hpp"
#include "TaxConstants.hpp"
#include "Tax.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace TAXCONSTANTS;
//Section: This function will get the users information and calculate the tax
void taxTaker(float TaxesP[SIZE])
{

    for(int i=0;i<SIZE;++i)
    {
    taxPayer tax;
    cout << "Enter this year's income for tax payer " << i+1 << " ";
    cin >> tax.income;
    tax.income=validation(tax.income);//calls validation function to make sure that its in range
    cout << "Enter the tax rate for payer # "<<i+1<<" ";
    cin >>tax.taxRate;
    cout << endl;
    tax.taxRate=validation2(tax.taxRate);
    tax.taxes=tax.income*tax.taxRate*0.01;
    TaxesP[i]=tax.taxes;
    }
}
//Section: This function will output the users tax amount
void taxPrint(float TaxesP[SIZE])
{
    cout << "Taxes due for this year: ";
    cout <<endl;
    for(int i=0;i<SIZE;++i)
        {
            cout << std::fixed<<std::setprecision(2) <<"Tax Payer # "<<i+1<<" $ " <<TaxesP[i] <<endl;
        }
}
//Section: This function test if the income is valid
float validation(float income)
{
    while(cin.fail()||income<1)
    {
        cin.clear();//clearing info
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//ignores numbers that are bigger then the streamsize
        cout <<"Invalid income. Please try again " ;//asking user to input info again
        cin>>income;
    }
return income;
}
//Section: This function will test if the tax rate is valid
float validation2(float taxRate)
{
    while(cin.fail()||taxRate<0.01||taxRate>9.9)
    {
        cin.clear();//clearing info
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout <<"Tax rate was not in bounds. Please try again " ;
        cin >> taxRate;
    }
return taxRate;
}
