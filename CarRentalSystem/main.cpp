#include "LuxuryCar.h"
#include "FamilyCar.h"
#include <vector>

//TODO 
//fix class headers + cpp
//ADD COLOR TO CAR CLASS
//ADD TAX FOR DAILY USE TO CAR CLASS
                         
int main(){

    vector<Car *> cars;

    Car* cPtr1 = new LuxuryCar("BMW", "M3", "Coupe", "MHS23984J34", "V342512", 750, "Champagne");
    Car* cPtr2 = new FamilyCar("Honda", "CRV", "SUV", "SDJH2343K3425", "L3423165", 200);

    cars.push_back(cPtr1);
    cars.push_back(cPtr2);

    for (int i=0; i< cars.size(); i++){
        cars.at(i)->print();
        // cout << cars.at(i)->calcTax() << endl; //add it to separate prints
    }

    return 0;
}