#include "Drinks.h"

Drinks::Drinks(string usrname, string drinkname, string type, double quantity, double price) 
{
    setUsername(usrname);
    setName(drinkname);
    setType(type);
    setQuantity(quantity);
    setPrice(price);
}

void Drinks::setName(string drinkname)
{
    this->drinkName = drinkname;
}

void Drinks::setUsername(string usrname)
{
    this->username = usrname;
}

void Drinks::setType(string type)
{
    this->type = type;
}

void Drinks::setQuantity(double qty)
{
    this->quantity = qty;
}

void Drinks::setPrice(double price)
{
    this->price = price;
}

void Drinks::calcFinSum(double sum)
{
    this-> finSum = sum;
}

string Drinks::getName()
{
    return this->drinkName;;
}

string Drinks::getUsrName()
{
    return this->username;
}

string Drinks::getType()
{
    return this->type;
}

double Drinks::getQuantity()
{
    return this->quantity;
}

double Drinks::getPrice()
{
    return this->price;
}

double Drinks::getFinSum()
{
    return this->finSum;
}

void Drinks::print()
{
    cout << "Printout of drink + info here. " << endl;
}

double Drinks::calcPrice()
{
    cout << "Drinks calcPrice called" << endl;
    return 0.0;
}
