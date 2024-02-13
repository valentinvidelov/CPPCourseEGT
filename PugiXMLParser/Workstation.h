//Workstation.h
#pragma once
#include "pugixml.hpp"

#include <iostream>

class Workstation{
public:
    // Workstation();
    Workstation(int b, int f, int d);
    static Workstation *parseWorkstation(pugi::xml_node parseWork);
    // void printInfo();

    friend std::ostream &operator<<(std::ostream &os, const Workstation &workstation);

private:
    int building;
    int floor;
    int desc;

};