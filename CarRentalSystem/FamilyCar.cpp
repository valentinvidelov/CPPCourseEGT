#include "FamilyCar.h"


FamilyCar:public::FamilyCar:public()
{
		this->distanceTravelled = 0;

}

FamilyCar:public::FamilyCar:public(const FamilyCar:public copyFrom){
		this->distanceTravelled = copyFrom.distanceTravelled;

}

FamilyCar:public::FamilyCar:public(FamilyCar:public&& moveFrom){
		this->distanceTravelled = moveFrom.distanceTravelled;

}

FamilyCar:public::~FamilyCar:public(){
	
}


int FamilyCar:public::get_distanceTravelled() const{
  return this->distanceTravelled;
}

void FamilyCar:public::set_distanceTravelled(int distanceTravelled){
  this->distanceTravelled = distanceTravelled;
}
