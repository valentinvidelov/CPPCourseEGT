#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;


class Employee{
public:
    Employee(string, string, string);
    void display();

private:
    string name, employeeID, position;

};

#endif // EMPLOYEE_H