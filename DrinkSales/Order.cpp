#include "Order.h"

Order::Order(Drinks drnk, string date, double finSum):drink(drnk)
{
    setDate(date);
    setFinSum(finSum);
}

void Order::setDate(string date)
{
    this->date = date;
}

void Order::setFinSum(double finSum)
{
    this->finSum = finSum;
}

string Order::getDate()
{
    return this->date;
}

double Order::getFinSum()
{
    return this->finSum;
}

void Order::print()
{
    cout << "Print out order number + date and final sum" << endl;
}
