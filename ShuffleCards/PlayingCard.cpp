#include "PlayingCard.h"

PlayingCard::PlayingCard(char s, char v)
{
    setSuit(s);
    setValue(v);
}

void PlayingCard::setSuit(char s)
{
    this->suit = s;
}

void PlayingCard::setValue(char v)
{
    this->value = v;
}

void PlayingCard::displayCard()
{
    cout << getValue() << getSuit() << endl;
}

char PlayingCard::getSuit()
{
    return this->suit;
}

char PlayingCard::getValue()
{
    return this->value;
}
