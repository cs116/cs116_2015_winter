// ----- leapyear.cpp -----
// see page 35 of textbook

#include <iostream>

using namespace std;

bool IsLeapYear(int year); // function declaration

int main()
{
  int year;
  cout << "\nEnter a year: \n";
  cin >> year;
  if (IsLeapYear(year))
    cout << year << " is a leap year.\n";
  else
    cout << year << " is not a leap year.\n";
  cout << endl;
  return 0;
} 

bool IsLeapYear (int year)
{
  if (year % 4 != 0) 
    return false; 
  if (year % 100 != 0) 
    return true;
  if (year % 400 != 0) 
    return false;
  return true; 
}
