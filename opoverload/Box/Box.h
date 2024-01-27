#ifndef BOX_H
#define BOX_H

#include <iostream>
using namespace std;

class Box{
    friend Box &operator+(Box &, Box &);
public:
    Box(int l = 1, int w = 1, int h = 1);
    void setLength(int);
    void setWidth(int);
    void setHeight(int);
    int getLength();
    int getWidth();
    int getHeight();
    // Box &operator+(Box &);
    void print();
private:
    int length;
    int width;
    int height;
};

#endif // BOX_H