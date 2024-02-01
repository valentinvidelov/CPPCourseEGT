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
    Employee *employees[100]; //returns undefined behavior, always declared array with static size ie 5-10
};

#endif // DEPARTMENT_H