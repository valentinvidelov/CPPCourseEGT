/*
 Polymorphism: Implement a function printArea() that takes a pointer to 
 the base class Shape as an argument and calls a method area() that should 
 be defined in both derived classes Circle and Rectangle. The area() method 
 should return the area of the shape, assuming Circle has an attribute 
 radius and Rectangle has width and height.
*/

#include <iostream>
using namespace std;

class Shape{

public:
    Shape(string c){
        color = c;
    };
    virtual double area() = 0;
    ~Shape();     //destructor since we are using virt method

protected:
    string color;
};

class Circle: public Shape{     //inheritance
public:
    Circle(double r, string c): Shape(c){
        radius = r;
    }
    double area() override{      //overridng virt func
        return 3.14 * radius * radius;
    }

private:
    double radius;
};
class Rectangle: public Shape{   //inheritance
public:
    Rectangle(int w, int h, string c): Shape(c){
        width = w;
        height = h;
    }
    double area() override{
        return width * height;
    }

private:
    int width, height;
};

void printArea(Shape *shp){
    cout << "Area: " << shp->area() << endl;
}

int main(){
    Shape *c1 = new Circle(5,"Blue");  //polymorphism happens here
    Shape *r1 = new Rectangle(20,10,"Red");

    printArea(c1);                    //and here
    printArea(r1);

    return 0;
}