// program: leapyear.cpp
// author: george corser
// date: 2014-09-01
// course: cs-116, fall 2014, saginaw valley state university (svsu)
// input: <year> (integer)
// processing: checks if year is evenly divisible by 4, 100, 400
// output: "<year> is a leapyear" or "<year> is not a leapyear" (text)

int main()
#include <iostream>          // needed for cout 
using namespace std;         // to eliminate "std::" in front of cout
{
    // Get year
	int year;
	//cout << "Enter year: " << endl; // prompt user for: year
	//cin >> year;	                  // store user input: year
	year = 1997;
	
	// Set leapyear = FALSE
	bool leapyear = false;
	
	if (year % 4 == 0)       // if "year" is divisible by 4
	   leapyear = true;	     // set leapyear == TRUE
	if (year % 100 == 0)     // if "year" is divisible by 100
	   leapyear = false;     // set leapyear == FALSE
	if (year % 400 == 0)     // if "year" is divisible by 400
	   leapyear = true;      // set leapyear == TRUE
					
	if (leapyear)            // if leapyear == TRUE
	  cout << year << " is a leap year."  << endl;
	else
	  cout << year << " is not a leap year."  << endl;

	return 0;                // 0 means program successful
}
