/*
 Inheritance: Create a base class Shape with a protected attribute color and 
 a public method draw(). Derive two classes from it: Circle and Rectangle. 
 Override the draw() method to print the shape's color and what shape it is 
 (e.g., "Drawing a red circle").
*/

#include <iostream>

using namespace std;

class Shape{
public:
    Shape(string c){
        color = c;
    };
    virtual void draw() = 0;
    ~Shape();  //destructor since we have a virtual function
protected:
    string color;

};

class Circle: public Shape{    //inheritance
public:
    Circle(string c): Shape(c){}
    void draw() override{
        cout << "Drawing a " << color << " Circle" << endl;
    }
};
class Rectangle: public Shape{    //inheritance
public:
    Rectangle(string c): Shape(c){}
    void draw() override{
        cout << "Drawing a " << color << " Rectangle" << endl;
    }
};

int main(){
    Shape *c1 = new Circle("Blue");  
    Shape *r1 = new Rectangle("Red");

    c1->draw();
    r1->draw();

    return 0;
}