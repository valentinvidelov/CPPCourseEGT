#include "Employee.h"

Employee::Employee(std::string name, std::string type, int age, Workstation w): workstation(w)
{
    this->name = name;
    this->type = type;
    this->age = age;
    // workstation = w;
}

ostream &operator<<(ostream &os, const Employee &employee) {
    os << "Name: " << employee.name << " Type: " << employee.type << " Age: " << employee.age << " Workstation: "
       << employee.workstation;
    return os;
}

Employee *Employee::parseEmployee(pugi::xml_node employeeNode)
{
    string name = employeeNode.attribute("Name").value();
    string type = employeeNode.attribute("Type").value();
    int age = employeeNode.attribute("Age").as_int();

    Workstation *wPtr = Workstation::parseWorkstation(employeeNode.child("Workstation"));

    return new Employee(name, type, age, *wPtr);
}
