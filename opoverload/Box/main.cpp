#include "Box.h"

int main(){

    Box b1(10,20,30);
    Box b2(1,40,3);
    Box b3;  //default constructor creates it as (1,1,1), doesnt affect operations though, just for initializing
    b1.print();
    b2.print();
    b3.print();

    b3 = b1 + b2;

    b1.print();
    b2.print();
    b3.print();

    return 0;
}