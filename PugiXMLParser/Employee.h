//Employee.h
#pragma once
#include <iostream>
#include "Workstation.h"
using namespace std;

class Employee{

public:
    Employee(string name, string type, int age, Workstation* w);
    static Employee *parseEmployee(pugi::xml_node employeeNode);
    friend ostream &operator<<(ostream &os, const Employee &employee);
private:
    string name, type;
    int age;
    Workstation* workstation;

};