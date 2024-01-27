#ifndef ORDER_H
#define ORDER_H

#include "Drinks.h"

class Order{
public:
    Order(Drinks, string, double);
    Order();
    void setDate(string);
    void setFinSum(double);
    string getDate();
    double getFinSum();
    void print();

private:
    Drinks drink;
    string usrName;
    string date;
    double finSum;
    double largestOrder;

};

#endif //ORDER_H