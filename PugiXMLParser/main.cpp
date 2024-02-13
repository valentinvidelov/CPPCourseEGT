#include <iostream>
using namespace std;

#include "EmployeeService.h"

using namespace pugi;


//HW - make employtee class with the 3 member vars, make a display method, throw in a vector and read from there
//clean up main, make it a func that creates vector of employee objs
int main()
{
/*     
    xml_document doc;
    
    if (!doc.load_file("Employees.xml")) {
        cout << "problem is at loadfile" << endl;
        return -1;
    }
    
    xml_node empls = doc.child("EmployeesData").child("Employees");

    for (xml_node_iterator it = empls.begin(); it != empls.end(); it++) {
        cout << "Employees: ";
        for (xml_attribute_iterator ait = it ->attributes_begin(); ait != it -> attributes_end(); ++ait)
        {
            cout << " " << ait->name() << "= " << ait->value();
        }
        cout << endl;
    } */
    EmployeeService::parseEmployeesData();

    for (auto employee: EmployeeService::getEmployeesList()){
        cout << employee << endl;
    }

    return 0;
}