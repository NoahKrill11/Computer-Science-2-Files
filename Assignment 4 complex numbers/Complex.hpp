//Noah Krill
//2/26/19
//cs2

#ifndef COMPLEX_HPP//Defining the hpp file
#define COMPLEX_HPP
#include <string>//including libraries
#include<iostream>

class Complex//Defining the class
{
public:
   Complex(double = 0.0, double = 0.0); // default constructor
   Complex add(const Complex&) const;	// function add
   Complex operator +(Complex &r);//overloading the + operators
   Complex subtract(const Complex&) const;
   Complex operator -(Complex &r);//overloading the - operators
   Complex multiply(const Complex&) const;
   Complex operator *(Complex &r);//overloading the * operators
   void setComplexNumber(double, double); // set complex number


 private:
    double realPart;
    double imaginaryPart;
    friend std::istream& operator >>(std::istream&,Complex&);//overloading the operator
    friend std::ostream& operator <<(std::ostream&,const Complex&);//overloading the operator
    friend bool operator ==(Complex &r, Complex &k);//overloaded == operator
    friend bool operator !=(Complex &r, Complex &k);//overloaded != operator
};

#endif

