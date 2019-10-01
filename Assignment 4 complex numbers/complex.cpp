//Noah Krill
//2/26/19
//cs2
#include <iostream>//include library
#include <stdexcept>
#include "Complex.hpp"

//Section: this function will sets the real number and imaginary number to zero
Complex::Complex(double rp, double ip)
{
realPart=rp;
imaginaryPart=ip;
}

//Section: this function will get the the numbers from the user
std::istream& operator>>(std::istream& in,Complex &a)
{
    in>>a.realPart;
    in>>a.imaginaryPart;
    return in;
}
//Section: this function will output the numbers being added
std::ostream& operator<< (std::ostream& out, const Complex &b)
{
    out << "(";
    out << b.realPart;
    out << " + ";
    out << b.imaginaryPart;
    out << "i";
    out << ")";
    return out;
}
//Section: this function calls the add function and return it back to main
Complex Complex::operator +(Complex &r)
{
Complex a=Complex(0,0);
a=Complex::add(r);
return a;
}
//Section: this function adds the complex numbers and return it back to the function above
Complex Complex::add(const Complex &r) const
{
Complex temp=Complex (0,0);
temp.realPart=realPart+r.realPart;
temp.imaginaryPart= imaginaryPart+r.imaginaryPart;
return temp;

}
//Section: this function calls the subtract function and return it back to main
Complex Complex::operator -(Complex &r)
{
Complex a=Complex(0,0);
a=Complex::subtract(r);

return a;
}
//Section: this function will subtract the complex numbers and return it back to the function above
Complex Complex::subtract(const Complex &r) const
{
Complex temp=Complex (0,0);
temp.realPart=realPart-r.realPart;
temp.imaginaryPart= imaginaryPart-r.imaginaryPart;
return temp;

}
//Section: this function calls the multiply function and return it back to main
Complex Complex::operator *(Complex &r)
{
Complex a=Complex(0,0);
a=Complex::multiply(r);
return a;
}
//Section: this function will multiply the complex numbers and return it back to the function above
Complex Complex::multiply (const Complex &r) const
{
Complex temp=Complex (0,0);
temp.realPart=realPart*r.realPart;
temp.imaginaryPart= imaginaryPart*r.imaginaryPart;
return temp;

}
//This function will determine if the real part of the number and the imaginary part of the number are the same

bool operator==(Complex &r, Complex &k)// This function will return when the complex numbers are equal
{
if((r.realPart==k.realPart) && (r.imaginaryPart ==k.imaginaryPart))//determining if the numerators are eqaul to eachother
    return true;
else
    return false;
    
}

// Returns true when the numerators or denominators of a and
// b differ.
bool operator!=( Complex &r , Complex &k)//This function will return when they are not equal
{

return !(r==k);
}

