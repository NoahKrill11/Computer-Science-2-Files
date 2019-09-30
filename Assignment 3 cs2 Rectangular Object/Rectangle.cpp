//Noah Krill
//CS2
//2/11/19
#include <iostream>
#include <stdexcept>
#include "Rectangle.hpp"
#include <math.h>


Rectangle::Rectangle(Point w,Point x,Point y,Point z)
{
//Section: Determines if the point is in the first quadrant and within the 20 size
if(!(w.xcoordinate<0.0||w.ycoordinate<0.0) || (w.xcoordinate<= 20) || (w.ycoordinate <=20))
        a=w;
    
    else
    {
        std::cout<< "Error one of the points is too big try again "<<std::endl;
        exit(0);
    }
if (!(x.xcoordinate<0.0||x.ycoordinate<0.0)||(x.xcoordinate<= 20) ||(x.ycoordinate <=20))
        b=x;
    else
    {
        std::cout<< "Error one of the points is too big try again "<<std::endl;
         exit(0);
    }
if(!(y.xcoordinate<0.0||y.ycoordinate<0.0)||(y.xcoordinate<= 20) || (y.ycoordinate <=20))
        c=y;
    else
    {
        std::cout<< "Error one of the points is too big try again "<<std::endl;
         exit(0);
    }
if(!(z.xcoordinate<0.0||z.ycoordinate<0.0)||(z.xcoordinate<= 20) || (z.ycoordinate <=20))
        d=z;
    
    else
    {
        std::cout<< "Error one of the points is too big try again "<<std::endl;
         exit(0);
    }
}
//Section:This function determines the length of the object and determines if the length of both sides are equal
double Rectangle::Length()
{
     double lengths,lengths2;
     lengths = sqrt(pow(b.xcoordinate-a.xcoordinate,2)+pow(b.ycoordinate-a.ycoordinate,2));//using distance formula to get length
     lengths2= sqrt(pow(d.xcoordinate-c.xcoordinate,2)+pow(d.ycoordinate-c.ycoordinate,2));
    if(lengths!=lengths2)
    {
        std::cout << "One of the sides is not like the other. This means it is not a rectangle nor a square."
        <<std::endl;
        std::cout <<"Please make sure that it is a rectangle or square "<<std::endl;
        exit(0);
    }
    else
     return lengths;
}
//Section:This function determines the width of the rectangle and returns it back to main
double Rectangle::Width()
{
    double widths;
    widths=sqrt(pow(c.xcoordinate-b.xcoordinate,2)+pow(c.ycoordinate-b.ycoordinate,2));
    return widths;

}
//Section:This function will determine the perimeter of the rectangle and return it to main
double Rectangle::Perimeter()
{
    double perimeters;
    double lengths,widths;
    lengths = sqrt(pow(b.xcoordinate-a.xcoordinate,2)+pow(b.ycoordinate-a.ycoordinate,2));
    widths=sqrt(pow(c.xcoordinate-b.xcoordinate,2)+pow(c.ycoordinate-b.ycoordinate,2));
    perimeters=(2*lengths)+(2*widths);
    return perimeters;
}
//Section:This function will determine the area of the rectangle and return it to main
double Rectangle::area()
{
    double length,width;
    length=sqrt(pow(b.xcoordinate-a.xcoordinate,2)+pow(b.ycoordinate-a.ycoordinate,2));
    width=sqrt(pow(c.xcoordinate-b.xcoordinate,2)+pow(c.ycoordinate-b.ycoordinate,2));
    double area =length*width;
    return area;
}
//Section:This function will determine the rectangle is a square and will return it back to main
bool Rectangle::square()
{
    double length,width;
    length=sqrt(pow(b.xcoordinate-a.xcoordinate,2)+pow(b.ycoordinate-a.ycoordinate,2));
    width=sqrt(pow(c.xcoordinate-b.xcoordinate,2)+pow(c.ycoordinate-b.ycoordinate,2));
    if(length==width)
        return true;
    else
        return false;
}




