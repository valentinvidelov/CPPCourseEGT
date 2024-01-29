#include "NewCar.h"


NewCar::NewCar()
{
	
}

NewCar::NewCar(const NewCar copyFrom){
	
}

NewCar::NewCar(NewCar&& moveFrom){
	
}

NewCar::~NewCar(){
	
}


string name, brand, NewCar::get_color() const{
  return this->color;
}

void NewCar::set_color(string  name,  brand, color){
  this->color = color;
}

int distTravelled, NewCar::get_dailyTax() const{
  return this->dailyTax;
}

void NewCar::set_dailyTax(int  distTravelled, dailyTax){
  this->dailyTax = dailyTax;
}

return NewCar::get_distTravelled,() const{
  return this->distTravelled,;
}

void NewCar::set_distTravelled,(return distTravelled,){
  this->distTravelled, = distTravelled,;
}
