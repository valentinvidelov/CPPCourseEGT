#include "User.h"

User::User(string name, string pw)
{
    setName(name);
    setPW(pw);
}

void User::setName(string name)
{
    this->name = name;
}

void User::setPW(string pw)
{
    if (pw.length() >4 && pw.length() <20){
        this->password = pw; 
    } else {  
        while (!(pw.length() > 4 && pw.length() < 20)){
            cout << "Incorrect password, try again. " << endl;
            cin >> pw;
        } 
        this->password = pw;


    }
}

string User::getName()
{
    return this->name;
}

string User::getPW()
{
    return this->password;
}
