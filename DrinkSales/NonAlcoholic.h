#ifndef NONALCOHOLIC_H
#define NONALCOHOLIC_H

#include "Drinks.h"

class NonAlcoholic:public Drinks{
public:
    NonAlcoholic(string, string, string, double, double, double, double);
    double calcPrice();
    virtual void print();
    void setLitrVol(double);
    void setCityTax(double);
    double getLitrVol();
    double getCityTax();

private:
    double litrVol;
    double cityTax;
};

#endif // NONALCOHOLIC_H