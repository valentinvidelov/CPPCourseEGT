#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <iostream>
using namespace std;

class PlayingCard{
public:
    PlayingCard(char, char);
    void setSuit(char);
    void setValue(char);
    void displayCard();
    char getSuit();
    char getValue();


private:
    char suit;
    char value;
};

#endif // PLAYINGCARD_H