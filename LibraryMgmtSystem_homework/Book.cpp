#include "Book.h"

Book::Book(string t, string a, string i)
{
    this->title = t;
    this->author = a;
    this->isbn = i;
}


void Book::display()
{
    cout << "Title: " << this->title << endl;
    cout << "Author: " << this->author << endl;
    cout << "ISBN: " << this->isbn << endl;
}
