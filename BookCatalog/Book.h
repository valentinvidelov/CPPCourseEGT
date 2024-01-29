#ifndef BOOK_H
#define BOOK_H

#include "Author.h"

class Book{
public:
    Book(string , Author, string, int);
    void setName(string);
    void setGenre(string);
    void setYear(int);
    void setAuthor(Author);
    string getName();
    string getGenre();
    int getYear();
    Author getAuthor();
    void print();

private:
    string name, genre;
    int year;
    Author author;
};

#endif // BOOK_H