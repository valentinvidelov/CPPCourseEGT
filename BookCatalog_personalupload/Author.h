#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
using namespace std;

class Author{
public:
    // Author();
    Author(string="Default entry", string="Default entry", string="Default entry");
    void setName(string);
    void setsurName(string);
    void setNationality(string);
    string getName();
    string getSurname();
    string getNationality();
    void print();
private:
    string name, surname, nationality;
};

#endif // AUTHOR_H