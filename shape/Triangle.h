#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "TwoDimShape.h"


class Triangle:public TwoDimShape{
public:
    Triangle(int);
    virtual void draw();
    virtual void print();
    virtual double getArea();

private:
    int x;

};

#endif // TRIANGLE_H