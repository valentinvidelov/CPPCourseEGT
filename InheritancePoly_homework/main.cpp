#include <iostream>
#include <vector>
using namespace std;

class Door{
public:
    virtual void open();   //virtual so it can get overriden later in similar funcs
    virtual void close(){
        cout << "Closing door." << endl;
    };
};
void Door::open()   //can be declared here as well
{
    cout << "Opening Door" << endl;
}
class CarDoor: public Door{
    virtual void open(){
    cout << "Opening car door" << endl;
};
    virtual void close(){
    cout << "Closing car door." << endl;
    };
};

class GarageDoor: public Door{
    virtual void open(){
    cout << "Opening garage door" << endl;
};
    virtual void close(){
        cout << "Closing garage door." << endl;
    };
};

int main() {
    vector<Door *> doors;
    Door* d1 = new Door(); // segfaults if you dont declare this way
    //Door* d1;   // this segfaults
    // d1->open();
    // d1->close();
    Door* gd1 = new GarageDoor();
    Door* cd1 = new CarDoor();

    doors.push_back(d1);
    doors.push_back(cd1);
    doors.push_back(gd1);

    for (int i = 0; i < doors.size(); i++){
        doors.at(i)->open();
        doors.at(i)->close();
    }

    return 0;
}


