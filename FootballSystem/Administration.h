#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <iostream>
#include "Teams.h"
#include <vector>
#include "User.h"

using namespace std;

class Administration:public User{
public:
    Administration(string, string);
    void addTeam(Teams);
    void removeTeam(Teams);
    void updateTeam(Teams);
    void print();
    vector<Teams> getTeams(); 

private:
    string usrname, passwd;
    vector<Teams> teams;
    User usr;
};

#endif // ADMINISTRATION_H