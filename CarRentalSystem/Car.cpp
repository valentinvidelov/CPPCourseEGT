#include "Car.h"


Car::Car()
{
		this->distance = 0;

}

Car::Car(const Car copyFrom){
		this->distance = copyFrom.distance;

}

Car::Car(Car&& moveFrom){
		this->distance = moveFrom.distance;

}

Car::~Car(){
	
}


string brand, model, type, VIN, Car::get_plateNo() const{
  return this->plateNo;
}

void Car::set_plateNo(string  brand,  model,  type,  VIN, plateNo){
  this->plateNo = plateNo;
}

int Car::get_distance() const{
  return this->distance;
}

void Car::set_distance(int distance){
  this->distance = distance;
}
