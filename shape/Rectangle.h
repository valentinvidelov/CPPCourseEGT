#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "TwoDimShape.h"

class Rectangle:public TwoDimShape{
public:
    Rectangle(int , int, int, string, char, int);
    virtual void print();
    virtual double getArea();
    virtual void draw();
 
    void setBase(int);
    void setHeight(int);


    int getBase();
    int getHeight();

private:
    int base, height;

};

#endif // RECTANGLE_H