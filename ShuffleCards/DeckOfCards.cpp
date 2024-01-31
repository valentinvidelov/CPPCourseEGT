#include "DeckOfCards.h"

void DeckOfCards::createDeck()
{
    vector<PlayingCard> deck;
    for (int i = 0; i < 4; i++){

        for (int j = 0; j<13; j++){
            PlayingCard card(suits[i], values[j]);
            deck.push_back(card);
        }
    }
    this->deck = deck;
    
}

void DeckOfCards::displayDeck()
{
    for (int i = 0; i < this->deck.size(); i++){
        deck.at(i).displayCard();
    }
}

void DeckOfCards::raffleShuffle()
{
    vector<PlayingCard>shuffledDeck, unshuffledDeck;
    unshuffledDeck = this->deck;
    for (int i = 0; i < 26; i++){
        int j = 26+i;
        shuffledDeck.push_back(unshuffledDeck.at(i));
        shuffledDeck.push_back(unshuffledDeck.at(j));

    }
    this->deck = shuffledDeck;
    // return shuffledDeck;
}
