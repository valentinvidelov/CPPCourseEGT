#include "Alcoholic.h"

Alcoholic::Alcoholic(string uname, string dname, string type, double quantity, double price, double alcVol, double alcTax)
:Drinks(uname, dname, type, quantity, price)
{
    setVolAlcohol(alcVol);
    setAlcTax(alcTax);
}

void Alcoholic::setVolAlcohol(double volAlc)
{
    this->volumeAlcohol = volAlc;
}

void Alcoholic::setAlcTax(double alcTax)
{
    this->alcTax = alcTax;
}

double Alcoholic::getVolAlcohol()
{
    return this->volumeAlcohol;
}

double Alcoholic::getAlcTax()
{
    return this->alcTax;
}

void Alcoholic::print()
{
    cout <<"Product: " << getName() << " " << getType() << " " << getQuantity() << ". Price per unit: " << getPrice() << endl;
    cout << getVolAlcohol() << " % alcohol, pays a tax of: "<< getAlcTax() << endl;
    cout << "Total due: " << calcPrice() << endl;
}

double Alcoholic::calcPrice()
{
    return getQuantity() * getPrice() * (getAlcTax()+1);
}
