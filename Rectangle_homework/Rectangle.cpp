#include "Rectangle.h"

Rectangle::Rectangle(int l, int w)
{
    setLength(l);
    setWidth(w);
}


void Rectangle::setLength(int l)
{
    this->length = l;
}

void Rectangle::setWidth(int w)
{
    this->width = w;
}

int Rectangle::getLength()
{
    return this->length;
}


int Rectangle::getWidth()
{
    return this->width;
}

int Rectangle::getArea()
{

    return (getLength() * getWidth());
}

bool operator==(Rectangle &r1, Rectangle &r2)
{
    // if (r1.getArea() == r2.getArea()){
    //     return true;  //returns seg fault if u try initializing as &operator
    // } else {
    //     return false;
    // }   // all this can be replaced by next line
    return (r1.getArea() == r2.getArea());

}

bool operator>(Rectangle &r1, Rectangle &r2)
{
    return (r1.getArea() > r2.getArea());
}

bool operator<(Rectangle &r1, Rectangle &r2)
{
    return (r1.getArea() < r2.getArea());
}
