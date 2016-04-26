// filename: timeismoney.cpp
// description: demonstrates reference variable

#include <iostream>
using namespace std;

int main()
{
  string time = "not enough";
  string &money = time;
  cout << time << " " << money << endl;
  return 0;
}
