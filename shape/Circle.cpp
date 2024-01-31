#include "Circle.h"

Circle::Circle(int x):TwoDimShape(x)
{

}

void Circle::print()
{
    cout << "print() called from Circle" << endl;

}

double Circle::getArea()
{
    cout << "getArea() called from Circle" << endl;
    return 0;

}

void Circle::draw()
{
    cout << "draw() called from Circle" << endl;

}
