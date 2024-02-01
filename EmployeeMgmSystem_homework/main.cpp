
#include "Department.h"

int main(){
    Department d1("Accounting");
    Employee* e1 = new Employee("Ben Employay", "JD3425", "Junior Accountant");
    Employee* e2 = new Employee("Ricky Shaw", "IK543623", "Manager");
    Employee* e3 = new Employee("Shaun White", "LD525434", "Senior Accountant");

    d1.addEmployee(e1);
    d1.addEmployee(e2);
    d1.addEmployee(e3);

    d1.displayEmployees();
    return 0;   // stack smashing detected, GG tf is stack smashing? error occurs at the end, past ln15..?
}