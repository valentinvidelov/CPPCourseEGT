#include "Workstation.h"

Workstation::Workstation(int b, int f, int d)
{
    building = b;
    floor = f;
    desc = d;
}

Workstation* Workstation::parseWorkstation(pugi::xml_node workstationNode)
{
	int b = workstationNode.attribute("Building").as_int();
	int f = workstationNode.attribute("Floor").as_int();
	int d = workstationNode.attribute("Desc").as_int();

	return new Workstation(b, f, d);
}


std::ostream &operator<<(std::ostream &os, const Workstation &workstation) {
    os << "building: " << workstation.building << " floor: " << workstation.floor << " desc: " << workstation.desc;
    return os;
}