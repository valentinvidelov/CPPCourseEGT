#include "TwoDimShape.h"

TwoDimShape::TwoDimShape(int a, int size, int pos, string shp, char ch):Shape(a)
{
    
}

double TwoDimShape::getArea()
{
    cout << "getArea() called from 2DIM shape" << endl;
    return 0;
}

void TwoDimShape::print()
{
    cout << "print called from 2DIM shape" << endl;
}


void TwoDimShape::draw()
{
    cout << "draw() called from 2DimShape" << endl;
}

void TwoDimShape::setSize(int size)
{
    this->size = size;
}

void TwoDimShape::setPosition(int pos)
{
    this->position = pos;
}

void TwoDimShape::setShape(string shp)
{
    this->shape = shp;
}

void TwoDimShape::setChr(char chr)
{
    this->chr = chr;
}

int TwoDimShape::getSize()
{
    return size;;
}

int TwoDimShape::getPosition()
{
    return position;
}

string TwoDimShape::getShape()
{
    return shape;
}

char TwoDimShape::getChr()
{
    return chr;
}
