#ifndef SQUARE_H
#define SQUARE_H

#include "TwoDimShape.h"

class Square:public TwoDimShape{
public:
    Square(int );
    virtual void print();
    virtual double getArea();
    virtual void draw();
    void setSide();
    int getSide();

private:
    int sideLength;
};

#endif // SQUARE_H