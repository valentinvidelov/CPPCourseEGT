// Date class test program.
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h" // Date class definition
#include "Time.h"

int main()
{

   Date d1; // defaults to January 1, 1900
   Date d2( 27, 12, 1992 ); // December 27, 1992
   Date d3( 0, 99, 8045 ); // invalid date
   Date d5; // empty for inputting date
   Date d6(01,03,1992);
   Date d7(01,03,1991);
   Date d8(01,12,1954);
   cout << (--d7);
   cout << (--d8);
   cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
   cout << "d1-- is: ";
   cout << (d1--) << endl;
   cout << "--d1 is: ";
   cout << (--d1) << endl;
   cout << "--d6 is: ";
   cout << (--d6);
   cout << "\n\nd2 += 7 is " << ( d2 += 7 );
   d3.setDate( 28, 2, 1992 );
   cout << "\n\n  d3 is " << d3;
   cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";

   Date d4( 13, 7, 2002 );

   cout << "\n\nTesting the prefix increment operator:\n"
      << "  d4 is " << d4 << endl;
   cout << "++d4 is " << ++d4 << endl;
   cout << "  d4 is " << d4;

   cout << "\n\nTesting the postfix increment operator:\n"
      << "  d4 is " << d4 << endl;
   cout << "d4++ is " << d4++ << endl;
   cout << "  d4 is " << d4 << endl;

   cout << "Enter date in dd-mm-yyyy format: ";
   cin >> d5;
   cout << d5;


   Time t1;
   Time t2(13,23,8);
   Time t3(544, 12, 65);
   Time t4(2,8,4);

   cout << t1;
   cout << "2 million seconds is: " << endl;
   cout << (t1 += 2000000) ;
   cout << t2;
   cout << t3;
   cout << t4;
   cout << "2 million seconds added to t4: " << endl;
   cout << (t4 += 2000000); 

   

   return 0;
} // end main


