#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "PlayingCard.h"
#include <vector>

class DeckOfCards{
public:
    void createDeck();
    void displayDeck();
    void raffleShuffle();
private:
    vector<PlayingCard> deck;
    char suits[4] = {'C', 'D', 'H', 'S'};
    char values[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

};
//[4] = {'C', 'D', 'H', 'S'};
//[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
#endif // DECKOFCARDS_H