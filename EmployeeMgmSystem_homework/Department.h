#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.h"

class Department{
public:
    Department(string);
    void addEmployee(Employee *employee);
    void displayEmployees();


private:
    string name;
    int numEmployees;
    Employee* employees[];

};

#endif // DEPARTMENT_H