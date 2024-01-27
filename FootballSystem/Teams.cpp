#include "Teams.h"

Teams::Teams(string name, string city)
{
    setName(name);
    setCity(city);
    setPoints(0); //initiate team creation with 0
}

void Teams::setName(string name)
{
    this->name = name;
}

void Teams::setCity(string city)
{
    this->city = city;
}

string Teams::getName()
{
    return this->name;
}

string Teams::getCity()
{
    return this->city;
}

void Teams::setPoints(int pts)
{
    this->points = pts;
}

void Teams::updatePoints(int pts)
{
    this->points +=pts;
}

int Teams::getPoints()
{
    return this->points;
}
