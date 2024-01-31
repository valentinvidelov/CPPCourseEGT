#include "Rectangle.h"

Rectangle::Rectangle(int b, int h, int size, string shape, char chr, int position)
:TwoDimShape(b,size,position,shape,chr)
{

    setBase(b);
    setHeight(h);
}
void Rectangle::print()
{
    cout << "print() called from Rectangle" << endl;

}
double Rectangle::getArea()
{
    cout << "getArea() called from Rectangle " << getBase() * getHeight() << endl;
    return getBase() * getHeight();

}
void Rectangle::draw()
{
    cout << "draw() called from Rectangle" << endl;

}

void Rectangle::setBase(int b)
{
    this->base = b;
}

void Rectangle::setHeight(int ht)
{
    this->height = ht;
}

int Rectangle::getBase()
{
    return this->base;
}

int Rectangle::getHeight()
{
    return height;
}

