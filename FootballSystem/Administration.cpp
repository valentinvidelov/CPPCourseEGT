#include "Administration.h"

Administration::Administration(string name, string pw)
{
    User(name, pw);
}

void Administration::addTeam(Teams t)
{
    this->teams.push_back(t);
}

void Administration::removeTeam(Teams t)
{
    string teamName = t.getName();
    for (int i=0; i< teams.size(); i++){
        if (teams.at(i).getName() == teamName){
            teams.erase(teams.begin() + i);
            break;
        }
    }
}

void Administration::updateTeam(Teams t)
{
    string teamName = t.getName();
    for (int i=0; i< teams.size(); i++){
        if (teams.at(i).getName() == teamName){
            teams.at(i) = t;
            break;
        }
    }
}

vector<Teams> Administration::getTeams()
{
    return this->teams;
}
