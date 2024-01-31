#include "Member.h"

Member::Member(string n, int a, string m)
{
    this->name = n;
    this->age = a;
    this->memberID = m;
}

void Member::display()
{
    cout << endl << this->name  << endl;
    cout << this->age << endl;
    cout << "ID: "<<this->memberID << endl;
}

void Member::borrowBook(Book *book)
{
    display();
    cout << "\n borrowed book: \n" << endl;
    book->display();
}
