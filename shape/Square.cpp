#include "Square.h"

Square::Square(int x):TwoDimShape(x)
{
}

void Square::print()
{
    cout << "print() called from Square" << endl;
}

double Square::getArea()
{
    cout << "getArea() called from Square" << endl;
    return 0;
}

void Square::draw()
{
    cout << "draw() called from Square" << endl;
}
