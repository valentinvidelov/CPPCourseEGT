#include "ThreeDimShape.h"

ThreeDimShape::ThreeDimShape(int x, int y, int z):Shape(x)
{
    setY(y);
}

double ThreeDimShape::getArea()
{
    cout << "getArea() called from 3DIM shape" << endl;
    return 0;
}

void ThreeDimShape::print()
{
    cout << "print() called from 3DIM shape" << endl;
}

void ThreeDimShape::getVolume()
{
    cout << "getVolume() called from 3DIM shape" << endl;
}

void ThreeDimShape::setY(int y)
{
    y = y;
}

void ThreeDimShape::draw()
{
     cout << "draw() called from 3DIMShape" << endl;
}
