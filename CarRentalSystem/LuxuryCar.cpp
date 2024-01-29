#include "LuxuryCar.h"


LuxuryCar:public::LuxuryCar:public()
{
		this->distanceTravelled = 0;
	this->extras = "";

}

LuxuryCar:public::LuxuryCar:public(const LuxuryCar:public copyFrom){
		this->distanceTravelled = copyFrom.distanceTravelled;
	this->extras = copyFrom.extras;

}

LuxuryCar:public::LuxuryCar:public(LuxuryCar:public&& moveFrom){
		this->distanceTravelled = moveFrom.distanceTravelled;
	this->extras = moveFrom.extras;

}

LuxuryCar:public::~LuxuryCar:public(){
	
}


int LuxuryCar:public::get_distanceTravelled() const{
  return this->distanceTravelled;
}

void LuxuryCar:public::set_distanceTravelled(int distanceTravelled){
  this->distanceTravelled = distanceTravelled;
}

string LuxuryCar:public::get_extras() const{
  return this->extras;
}

void LuxuryCar:public::set_extras(string extras){
  this->extras = extras;
}
