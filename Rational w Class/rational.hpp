// COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
struct rationalNumber
{
    int number;
    int num;
    double den;
};


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
    // TODO: Define the following:
    //Rational();// 1. A default constructor
    //Rational(int&);// 2. A constructor that takes an integer value
    // 3. A constructor that takes a pair of values

    rationalNumber a,b;//declaring two different objects
    /*
    Section This section defines overloaded functions until it reaches the public
    */
    friend std::ostream& operator<<(std::ostream& os, Rational r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend bool operator ==(Rational &r, Rational &k);
    friend bool operator !=(Rational &r, Rational &k);
    friend bool operator >(Rational &r, Rational &k);
    friend bool operator < (Rational &r, Rational &k);
    friend bool operator >=(Rational &r, Rational &k);
    friend bool operator <=(Rational &r, Rational &k);
    friend std::string operator +(Rational &r, Rational &k);
    friend std::string operator -(Rational &r, Rational &k);
    friend std::string operator *(Rational &r, Rational &k);
    friend std::string operator /(Rational &r, Rational &k);



public:
    Rational();// 1. A default constructor
    Rational(int);//defining int constructor
    Rational(const int,const int);//defining another constructor that takes two values
    // Returns the numerator.
    int num() const
    {
        return a.num;
    }

    // Returns the denominator
    int den() const
    {
        return a.den;
    }

};


// TODO: Implement support for
// 1. Comparing two rational numbers for equality:
//    - r1 == t2
//    - r1 != r2
// 2. Ordering rational numbers
//    - r1 < r2
//    - r1 > r2
//    - r1 <= r2
//    - r1 >= r2
// 3. The standard arithmetic operators
//    - r1 + r2
//    - r1 - r2
//    - r1 * r2
//    - r1 / r2

// These are provided for you.
//
// NOTE: They are defined in rational.cpp.


#endif
