#ifndef FAMILYCAR_H
#define FAMILYCAR_H

#include "Car.h"

class FamilyCar:public Car{
public:
    FamilyCar(string, string, string, string, string, int);
    virtual double calcTax(int);
    void setDistanceTravelled(int); 
    int getDistanceTravelled();
    virtual void print();

private:
    int distanceTravelled;
};

#endif // FAMILYCAR_H