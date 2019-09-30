//Noah Krill
//CS2
//2/11/19
#include<iostream>
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


//Section:Declaring a structure for the different x and y coordinates

struct Point
{
   double xcoordinate;
   double ycoordinate;
};
//Section:Declaring a class for the object
class Rectangle
{
private:
    //Section:Declaring points a,b,c,d to be used in other functions
    Point a,b,c,d;

public:
    //Section:Declaring functions to be used in other cpp files
    Rectangle (Point,Point,Point,Point);
    double Length();
    double Width();
    double Perimeter();
    double area();
    bool square();




};

#endif // RECTANGLE_HPP
