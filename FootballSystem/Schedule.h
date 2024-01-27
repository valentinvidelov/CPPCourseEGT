#ifndef SCHEDULE_H
#define SCHEDULE_H


#include "Teams.h"

class Schedule{
public:
    Schedule();
    

private:
    string date, time, stadium, referee;
    int round;
    Teams homeTeam, awayTeam;
};

#endif // SCHEDULE_H