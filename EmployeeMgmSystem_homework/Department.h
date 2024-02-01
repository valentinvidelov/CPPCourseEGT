#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.h"

class Department{
public:
    Department(string);
    void addEmployee(Employee *employee);
    void displayEmployees();
    int getNumEmp();

private:
    string name;
    int numEmployees = 0;
    Employee* employees[3];

};

#endif // DEPARTMENT_H