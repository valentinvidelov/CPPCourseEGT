#include "Shape.h"
#include "TwoDimShape.h"
#include "ThreeDimShape.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>

//demonstrates use of the term virtual in header files to override funcs, something something polymorphism

int main() {
    vector<Shape *> shapes;
    Shape* shap1 = new Shape(2); // thyese 
    Shape* shap2 = new TwoDimShape(2,2);
    Shape* shap3 = new ThreeDimShape(2,3,4);
    Shape* shap4 = new Square(2);
    Shape* shap5 = new Circle(5);
    Shape* shap6 = new Rectangle(2,6,5,"rectangle",'r',3);
    Shape* shap7 = new Triangle(5);

    shapes.push_back(shap1);
    shapes.push_back(shap2);
    shapes.push_back(shap3);
    shapes.push_back(shap4);
    shapes.push_back(shap5);
    shapes.push_back(shap6);
    shapes.push_back(shap7);

    for (int i=0; i<shapes.size(); i++){
        shapes.at(i)->print();
        shapes.at(i)->getArea();
        shapes.at(i)->draw();

    }

    // // cout << "Hello worldo!" << endl;
    return 0;
}