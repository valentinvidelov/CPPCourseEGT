#include "Rectangle.h"

int main(){

    Rectangle r1(2,4);
    Rectangle r2(3,5);
    Rectangle r3(1,8);
    if (r1==r3){
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }
    cout << (r1 > r2) << endl;  //should return false or 0
    cout << (r1 < r2) << endl;  //should return true or 1
    cout << (r1 == r2) << endl;
    cout << (r1 == r3) << endl;
    cout << (r2 == r3) << endl;
    cout << r1.getArea() << endl;

    return 0;
}