#ifndef TEAMS_H
#define TEAMS_H

#include <iostream>
using namespace std;

class Teams{
public:
    Teams(string, string); // name, city, (points) // we initialize without knowing points
    void setName(string);
    void setCity(string);
    string getName();
    string getCity();
    void setPoints(int);
    void updatePoints(int);
    int getPoints();

private:
    string name, city, trainer, qualificationStatus;
    int wins, losses, ties, points;

};

#endif // TEAMS_H