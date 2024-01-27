#include "NonAlcoholic.h"

NonAlcoholic::NonAlcoholic(string uname, string dname, string type, double qty, double price, double litrVol, double cityTax)
:Drinks(uname, dname, type, qty, price)
{
    setLitrVol(litrVol);
    setCityTax(cityTax);
}

double NonAlcoholic::calcPrice()
{
    // cout <<"calcing price in nonalcoholic cpp" << endl;
    return getQuantity() * getPrice() * (getCityTax()+1);
}

void NonAlcoholic::print()
{
    cout <<"Product: " << getName() << " " << getType() << " " << getQuantity() << ". Price per unit: " << getPrice() << endl;
    cout << getLitrVol() << " litres requested, owes a city tax of: " << getCityTax() << endl;
    cout << "Total due: " << calcPrice() << endl;
}

void NonAlcoholic::setLitrVol(double vol)
{
    this->litrVol = vol;
}

void NonAlcoholic::setCityTax(double ctTax)
{
    this->cityTax = ctTax;
}

double NonAlcoholic::getLitrVol()
{
    return this->litrVol;
}

double NonAlcoholic::getCityTax()
{
    return this->cityTax;
}
