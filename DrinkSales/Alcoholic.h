#ifndef ALCOHOLIC_H
#define ALCOHOLIC_H

#include "Drinks.h"

class Alcoholic:public Drinks{
public:
    Alcoholic(string, string, string, double, double, double, double);
    void setVolAlcohol(double);
    void setAlcTax(double);
    double getVolAlcohol();
    double getAlcTax();
    virtual void print();
    double calcPrice();

private:
    double volumeAlcohol;
    double alcTax;

};


#endif // ALCOHOLIC_H