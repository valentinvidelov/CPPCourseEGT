#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

//make twodim and threedim shape inherit from shape, use virtual void print(); 

class Shape{
public:
    Shape(int x = 0);
    void setShape(string);
    void getShape();
    virtual void print();
    virtual double getArea();
    virtual void draw();

private:
    void getPrivateFunc();
    int len;
    int size, position; // these should not all be ints
    string shape;
    string fillChars;

};


#endif // SHAPE_H