#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;


class Book{
public:
    Book(string, string, string);       //constructor

    void display();

private:
    string title;           // member vars
    string isbn;
    string author;
};

#endif // BOOK_H