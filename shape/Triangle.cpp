#include "Triangle.h"

Triangle::Triangle(int x):TwoDimShape(x)
{
}

void Triangle::draw()
{
    cout << "draw() called from Triangle" << endl;
}

void Triangle::print()
{
       cout << "print() called from Triangle" << endl;
}

double Triangle::getArea()
{
       cout << "getArea() called from Triangle" << endl;
       return 0;
}
