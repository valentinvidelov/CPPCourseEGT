#ifndef TWODIMSHAPE_H
#define TWODIMSHAPE_H

#include "Shape.h"

class TwoDimShape:public Shape{
public:
    TwoDimShape(int a = 0, int size = 1, int position = 0 , string shape = "defaultshape", char = 'a');
    virtual double getArea();
    virtual void print();

    virtual void draw();
    void setSize(int);
    void setPosition(int);
    void setShape(string);
    void setChr(char);
    int getSize();
    int getPosition();
    string getShape();
    char getChr();

private:
  
    int size, position;
    string shape;
    char chr;
};


#endif //TWODIMSHAPE_H