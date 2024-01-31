#include "Shape.h"

Shape::Shape(int x)
{
    
}



void Shape::setShape(string shp){
    shape = shp;
}

void Shape::getShape(){
    cout << "get shape called" << endl;
}

void Shape::print()
{
    cout << "print called from Shape" << endl;
}

double Shape::getArea()
{
    cout << "print getArea() called from Shape" << endl;
    return 0;
}

void Shape::draw()
{
    cout << "draw() called from Shape" << endl;
}

void Shape::getPrivateFunc()
{
    cout << "will this be accessible by inherited shapes?" << endl;
}
