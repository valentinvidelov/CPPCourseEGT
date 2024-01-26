#include "Time.h"

ostream &operator<<(ostream &output, const Time &t)
{
    output << "Day " << t.day << endl;
    if (t.hour < 10){
        output << "0" << t.hour << ":";
    } else {
        output << t.hour << ":";
    }
    if (t.min < 10){
        output << "0" << t.min << ":";
    } else {
        output << t.min << ":";
    }
    if (t.sec < 10){
        output << "0" << t.sec;
    } else {
        output << t.sec;
    }
    output << " o'clock" << endl;
    return output;
}

Time::Time(int h, int m, int s)
{
    setTime(h, m, s);
}

void Time::setTime(int hh, int mm, int ss)
{ // DO NOT test for leapsecond u have no clue what you will get yourself into
    this->hour = ( hh >= 0 && hh < 24) ? hh : 12; //if then else the funky way
    this->min = ( mm >= 0 && mm < 60) ? mm : 00;
    this->sec = (ss >=0 && ss < 60) ? ss : 00;
    this->day = 0; //initialize from day zero
}

const Time &Time::operator+=(int additionalSeconds)
{
    for (int i=0; i< additionalSeconds; i++){
        helpIncrement();
    }
    return *this;   //enables _cascading_? look that up 
}

void Time::helpIncrement()
{
    this->sec++;
    if (this->sec > 59){
        sec = 0;
        this->min++;
    }
    if (this->min > 59) {
        min = 0;
        this->hour++;
    }
    if (this->hour >23 ){
        hour = 0;
        this->day++;
    }
}
