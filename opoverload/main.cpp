#include "Time.h"

int main(){

    Time t1;
    Time t2(13,23,8);
    Time t3(544, 12, 65);
    Time t4(2,8,4);

    cout << t1;
    cout << t2;
    cout << t3;
    cout << t4;
    cout << "2 million seconds added to t4: " << endl;
    cout << (t4 += 2000000); 
    return 0;
}