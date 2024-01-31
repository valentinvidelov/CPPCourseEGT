#include "Box.h"



Box::Box(int l, int w, int h)
{
    setLength(l);
    setWidth(w);
    setHeight(h);
}

void Box::setLength(int l)
{
    this->length = l;
}

void Box::setWidth(int w)
{
    this->width = w;
}

void Box::setHeight(int h)
{
    this->height = h;
}

int Box::getLength()
{
    return this->length;
}

int Box::getWidth()
{
    return this->width;
}

int Box::getHeight()
{
    return this->height;
}

// Box &Box::operator+(Box &b)
// {
//     // TODO: insert return statement here
//     b.height += b.height;
//     return *this;
// }

void Box::print()
{
    cout << "Box info:" << endl;    
    cout << "Length: " << getLength() << endl;
    cout << "Width: " << getWidth() << endl;
    cout << "Height: " << getHeight() << endl; 
}

Box &operator+(Box &b1, Box &b2)  //has to be friend in header or it wont allow 2 parameters
{     //would look waaay cleaner if we throw the getters inside vars and maybe use the funky if-else
    Box b3;
    b3.setHeight(b1.getHeight() + b2.getHeight());
    if (b1.getWidth() >= b2.getWidth()){ //we determine which box has a larger width and length to apply to sum box
        b3.setWidth(b1.getWidth());
    } else {
        b3.setWidth(b2.getWidth());
    }
    if (b1.getLength() >= b2.getLength()){ 
        b3.setLength(b1.getLength());
    } else {
        b3.setLength(b2.getLength());
    }
    b1 = b3; //doesnt allow us to return b3 since its local but allows us to pass b1, 
    return b1;  //we lose original b1 this way but it works
}
