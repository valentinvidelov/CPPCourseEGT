#include "Department.h"

Department::Department(string n)
{
    this->name = n;
}

void Department::addEmployee(Employee *employee)
{
    this->employees[numEmployees] = employee;
    this->numEmployees++;
}

void Department::displayEmployees()
{
    
    for (int i = 0; i < this->numEmployees; i++){
        this->employees[i]->display();
    }
 
    
}


