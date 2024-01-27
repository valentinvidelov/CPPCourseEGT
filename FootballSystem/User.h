#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;


class User{
public:
    User(string defaultUsr = "defaultUsr", string defaultPW = "defaultpw");
    void setName(string);
    void setPW(string);
    string getName();
    string getPW();
    
private:
    string name, password;
};

#endif // USER_H