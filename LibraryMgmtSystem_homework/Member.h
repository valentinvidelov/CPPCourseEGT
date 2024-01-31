#ifndef MEMBER_H
#define MEMBER_H

#include "Book.h"

class Member{
public:
    Member(string, int, string);
    void display();
    void borrowBook(Book *book);


private:
    string name;
    int age;
    string memberID;

};

#endif // MEMBER_H