#ifndef FAMILYCAR_H
#define FAMILYCAR_H

#include "Car.h"

class FamilyCar:public Car{
public:
    FamilyCar(string, string, string, string, string, int);
    double calcTax(int);
    void setDistanceTravelled(int); 
    int getDistanceTravelled();
    void print() override;

private:
    int distanceTravelled;
};

#endif // FAMILYCAR_H