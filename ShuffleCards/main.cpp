// #include "PlayingCard.h"
#include "DeckOfCards.h"

int main(){                  //creates and displays a deck, shuffles (raffleshuffle)
    DeckOfCards deck;
    deck.createDeck();
    deck.displayDeck();
    cout << "Raffled shuffled: " << endl;
    deck.raffleShuffle();    
    deck.displayDeck();

    return 0;
}