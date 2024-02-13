#include "EmployeeService.h"

pugi::xml_document EmployeeService::doc;
std::vector<Employee*> EmployeeService::employeeList;

void EmployeeService::parseEmployeesData()
{
    //open file
    //go to Employees node
    //loop thru all Employee
    //read Employee node -> parseEmployee ; returns employee
    // add eployee object to vector
    
    if (!doc.load_file("Employees.xml")) return;
    pugi::xml_node employees = doc.child("EmployeesData").child("Employees");

    // for (pugi::xml_node employee = employees.child("Employee"); employee;
    //             employee = employee.next_sibling("Employee"));  //loops thru employee nodes


    for (auto employee: employees){    // same as above

        Employee *ePtr = Employee::parseEmployee(employee);
        employeeList.push_back(ePtr);
    }
}

std::vector<Employee *> EmployeeService::getEmployeesList()
{
    
    return employeeList;
}
