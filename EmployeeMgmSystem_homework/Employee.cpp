#include "Employee.h"

Employee::Employee(string n, string e, string p)
{
    this->name = n;
    this->employeeID = e;
    this->position = p;
}

void Employee::display()
{
    cout << this->name << " ID: " ;
    cout << this->employeeID << " Position: ";
    cout << this->position << endl;
}
