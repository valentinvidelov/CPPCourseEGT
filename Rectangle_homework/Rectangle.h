#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle{
    friend bool operator>(Rectangle &, Rectangle &);
    friend bool operator<(Rectangle &, Rectangle &);
    friend bool operator==(Rectangle &, Rectangle &);
public:
    Rectangle(int, int);
    void setLength(int);
    void setWidth(int);
    int getLength();
    int getWidth();
    int getArea();
 

private:
    int length;
    int width;
       
};

#endif // RECTANGLE_H