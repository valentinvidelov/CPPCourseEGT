#ifndef REFEREE_H
#define REFEREE_H

#include "User.h"

class Referee:public User{
public:
    Referee();

private:
    string results, cards, goals;
};

#endif // REFEREE_H