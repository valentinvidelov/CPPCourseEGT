#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

class Car{
public:
    Car(string,string,string,string,string);
    void setBrand(string);
    void setModel(string);
    void setType(string);
    void setVIN(string);
    void setPlateNo(string);
    string getBrand();
    string getModel();
    string getType();
    string getVIN();
    string getPlateNo();
    virtual void print();
    virtual double calcTax();

private:
    string brand, model, type, VIN, plateNo;
    int distance;
};



#endif // CAR_H