#include <vector>
#include "NonAlcoholic.h"
#include "Alcoholic.h"

//order = number, drink, finsum

int main(){
    // Alcoholic alc1("user1", "greygoose", "vodka", 2, 20, .44, 18.5 );
    // NonAlcoholic nonAlc1("user2", "nestle", "water", 10, 1.50, 2, 10.25 );

    Drinks* dPtr1 = new Alcoholic("user1", "greygoose", "vodka", 2, 20, .44, .185 );
    Drinks* dPtr2 = new  NonAlcoholic("user2", "nestle", "water", 10, 1.50, 2, .1025 );
    Alcoholic *aPtr = new Alcoholic("user3", "smirnoff", "vodka", 3, 20, .44, .185 );
    NonAlcoholic *naPtr = new NonAlcoholic("user4", "devin", "water", 20, 1.50, 4, .1025 );

    vector<Drinks *> drinks;
  
    drinks.push_back(dPtr1);
    drinks.push_back(dPtr2);

    for (int i=0; i<drinks.size(); i++){
        drinks.at(i)->print();
        
    }

    drinks.push_back(aPtr);
    drinks.push_back(naPtr);

    //using cast to determine if drink is alc or nonalc
    for (int i=0; i<drinks.size(); i++){
        Alcoholic *ptr = dynamic_cast<Alcoholic *>(drinks.at(i));
        if (ptr != 0){
            cout << "alcoholic" << endl;

        }
        else {
            cout << "Non-alcoholic" << endl;
        }
    }

    return 0;
}