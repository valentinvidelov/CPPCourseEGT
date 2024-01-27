#ifndef DRINKS_H
#define DRINKS_H

#include <iostream>
using namespace std;

class Drinks{
public:
    Drinks(string, string, string, double, double);
    void setName(string);
    void setUsername(string);
    void setType(string);
    void setQuantity(double);
    void setPrice(double);
    void calcFinSum(double);
    string getName();
    string getUsrName();
    string getType();
    double getQuantity();
    double getPrice();
    double getFinSum();
    virtual void print();
    double calcPrice();



private:
    string drinkName;
    string username;
    double price;
    double quantity;
    string type;
    double finSum;
    int orderNo;
};

#endif //DRINKS_H