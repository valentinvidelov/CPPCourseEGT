#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimShape.h"

class Circle:public TwoDimShape{
public:
    Circle(int );
    virtual void print();
    virtual double getArea();
    virtual void draw();

private:
    int radius;
};

#endif // CIRCLE_H