#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time{
    friend ostream &operator<<(ostream &, const Time &);
public:
    Time(int h=0, int m=0, int s=0);
    void setTime(int, int, int);
    const Time &operator+=( int );
private:
    int hour;
    int min;
    int sec;
    int day;

    void helpIncrement();
};

#endif //TIME_H