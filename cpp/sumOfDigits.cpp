// filename: sumOfDigits.cpp
#include <iostream>
using namespace std;

int main()
{

  int number = 12345678;
  int sum = 0;
  int newnumber;
  int remainder;

  while (number > 0)
  {
    newnumber = number / 10;
    remainder = number % 10;
    sum = remainder + sum;
    number = newnumber;
  }
  cout << "sum: " << sum << endl;

  if (sum % 3 == 0) cout << "suspect" << endl;
  else cout << "not a suspect" << endl;

  return 0;
}


