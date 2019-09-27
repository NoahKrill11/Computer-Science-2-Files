// COPYRIGHT (C) 2017 Noah Krill (UANET ID ) All rights reserved.
//
// rational.hpp: Definition of rational class and its interace.

#include "rational.hpp"//including library
#include <iostream>

//This function will take the numerator and the denominator and reduce them and pass them back to
//the function to which its called by reference
void reduce (int &numerator, int &denominator)
{
    for (int i = denominator * numerator; i > 1; i--)
    {
        if ((denominator % i == 0) && (numerator % i == 0))
        {
            denominator /= i;
            numerator /= i;
        }

    }
}
//This function will take the two variables and store them to a value
Rational::Rational()
{
    a.num=0;
    a.den=1;
}
//This function stores the objects numerator to the value passed to the function
//and the denominator = to 1
Rational::Rational(int r)
{
    a.num=r;
    a.den=1;
}
//This function stores the numerator = to the first number passed to the function
//and it stores the denominator = to the second number passed to the function
//if the second number passed doesnt eqaul 0
Rational::Rational(int r,int p)
{
    a.num=r;
    if(p!=0)
    {
        a.den=p;
    }
}
//This function will overload the ostream operator and will return the numerator over the denominator
std::ostream& operator<<(std::ostream& os, Rational r)
{
    if(r.num()!=0&& r.den()!=1)
    {
        return os << r.num() << '/' << r.den();//returns numerator over denominator if the numerator doesnt = 0
        //and the denominator doesn =1
    }
    else
    {
        return os << r.num();//else return numerator
    }
}

//DO NOT CHANGE operators >> overloading function
std::istream& operator>>(std::istream& is, Rational& r)
{
    // Read the first integer, return on error.
    int p;
    is >> p;
    if (!is)
        return is;

    // Check for the divider. Assuming no spaces.
    if (is.peek() != '/')
    {
        r = Rational(p);
        return is;
    }
    is.get();

    int q;
    is >> q;
    if (!is)
        return is;
    if (q == 0)
    {
        is.setstate(std::ios::failbit);
        return is;
    }
    r = Rational(p, q);
    return is;

#if 0
    int p, q;
    char c;
    is >> p >> c >> q;
    if (!is)
        return is;
    // Require that the divider to be a '/'.
    if (c != '/')
    {
        is.setstate(std::ios::failbit);
        return is;
    }

    // Make sure that we didn't read p/0.

    r = Rational(p, q);
    return is;
#endif
}
//overloading the eqauls operator and this function will determine if the rational numbers are equal
bool operator==(Rational &r, Rational &k)

{
    double number,number2,num,den;
    num=r.a.num;
    den=r.a.den;
    number=r.a.num/r.a.den;//creating a variable to store the decimal form of the rational number
    num=k.a.num;
    den=k.a.den;
    number2=k.a.num/k.a.den;
    if(number==number2)//determining if the numerators are eqaul to each other
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This function will take both numbers and return true when the numerators or denominators of a and
// b differ.
bool operator!=( Rational &r, Rational &k)
{

    return !(r==k);
}
//This function will take both rational numbers and compare them to see if the right number is greater then
//the left one and will return true if so and false otherwise
bool operator > (Rational &r, Rational &k)
{
    double number,number2;
    number = r.a.num/r.a.den;//creating a variable to store the decimal form of the rational number
    number2 = k.a.num/k.a.den;
    if (number>number2)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//This function will take both rational numbers and compare them to see if the right number is less then
//the left one and will return true if so and false otherwise
bool operator < (Rational &r, Rational &k)
{
    double  number,number2;
    number = r.a.num/r.a.den;//creating a variable to store the decimal form of the rational number
    number2 = k.a.num/k.a.den;
    if (number<number2)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//This function will take both rational numbers and compare them to see if the right number is less than or eqaul to
//the left one and will return true if so and false otherwise
bool operator <= (Rational &r, Rational &k)
{
    double  number,number2;
    number=r.a.num/r.a.den;//creating a variable to store the decimal form of the rational number
    number2 = k.a.num/k.a.den;
    if (number<=number2)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//This function will take both rational numbers and compare them to see if the right number is greater than or eqaul to
//the left one and will return true if so and false otherwise
bool operator >= (Rational &r, Rational &k)
{
    double  number,number2;
    number=r.a.num/r.a.den;//creating a variable to store the decimal form of the rational number
    number2 = k.a.num/k.a.den;
    if (number>=number2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//This function overloads the plus operator. It takes both of the rational numbers and adds them together and returns
// it back to main.
std::string operator +(Rational &r, Rational &k)
{
    int number1, number2;
    number1=(r.a.num*k.a.den)+(k.a.num*r.a.den);//multipling numertor by the denomintor of the other twice and adding them together
    number2 =(r.a.den*k.a.den);//multiplying the denominators together
    reduce(number1,number2);//calls the reduce function
//This section makes it in rational form and returns it back to main
    if(number2!=1&& number1!=0)
    {
        std::string add = std::to_string(number1);
        add += "/";
        add += std::to_string(number2);
        return add;
    }
    else
    {
        std::string add = std::to_string(number1);
        return add;
    }

}
//This function overloads the minus operator. It takes both of the rational numbers and subtracts them and returns
// it back to main.
std::string operator -(Rational &r, Rational &k)
{
    int number1, number2;
    number1=(r.a.num*k.a.den)-(k.a.num*r.a.den);//multipling numertor by the denomintor of the other twice and subtracting them
    number2 =(r.a.den*k.a.den);//multiplying the denominators together
    reduce(number1,number2);
//making the number to rational form and returning it back to main
    if(number2!=1&&number1!=0)
    {
        std::string subtract = std::to_string(number1);
        subtract += "/";
        subtract += std::to_string(number2);
        return subtract;
    }
    else
    {
        std::string subtract = std::to_string(number1);
        return subtract;
    }

}
//This function overloads the multiply operator. It takes both of the rational numbers and multiplies them together and returns
// it back to main.
std::string operator *(Rational &r, Rational &k)
{
    int number1, number2;
    number1 = r.a.num * k.a.num;//multiplying the numerator by denominator
    number2= r.a.den * k.a.den;//multiplying the numerator by denominator
    reduce(number1,number2);
    if(number1!=0&&number2!=1)
    {
        std::string multiply = std::to_string(number1);
        multiply += "/";
        multiply += std::to_string(number2);
        return multiply;
    }
    else
    {
        std::string multiply = std::to_string(number1);
        return multiply;
    }
}
//This function overloads the divide operator. It takes both of the rational numbers and divides them and returns
// it back to main.
std::string operator /(Rational &r, Rational &k)
{
    int number1, number2;
    number1=r.a.num * k.a.den;//multiplying the numerator by denominator
    number2=r.a.den*k.a.num;//multiplying the numerator by denominator
    reduce(number1,number2);
    if(number1!=0&&number2!=1)
    {
        std::string divison = std::to_string(number1);
        divison += "/";
        divison+= std::to_string(number2);
        return divison;
    }
    else
    {
        std::string divison = std::to_string(number1);
        return divison;
    }

}

