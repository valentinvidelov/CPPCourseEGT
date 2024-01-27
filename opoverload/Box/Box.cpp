#include "Box.h"

Box::Box(int l, int w, int h)
{
    setLength(l);
    setWidth(w);
    setHeight(h);
}

void Box::setLength(int l)
{
    this->length = l;
}

void Box::setWidth(int w)
{
    this->width = w;
}

void Box::setHeight(int h)
{
    this->height = h;
}

int Box::getLength()
{
    return this->length;
}

int Box::getWidth()
{
    return this->width;
}

int Box::getHeight()
{
    return this->height;
}
