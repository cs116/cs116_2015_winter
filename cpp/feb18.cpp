// filename: feb18.cpp
// description: reads input file and prints sum of numbers
// input : in.data
// output: to screen

#include <iostream> // cout, endl
#include <string> //
#include <fstream> // for ifstream
#include <cmath> // for sqrt()
using namespace std; // to avoid std::

float square (int); // function prototype
int cube (int);
int powerfun(int, int);

int main ()
{
  // cout << sqrt(2);
  // ------ declare variables and objects
  // ifstream infile ("in.data");
  ifstream infile;
  infile.open("in.data");
  // ifstream infile = ifstream("in.data");
  int temp = 0, counter = 0;
  string name = "";
  infile >> name;
  while (infile)
  {
  // ----- add numbers to counter
  // infile >> name >> name >> temp ;
  infile >> name;
  infile >> temp;
  cout << powerfun (temp, 4) << " " ;
  counter += temp;
  infile >> temp ;
  cout << powerfun (temp, 4) << " " ;
  counter += temp;
  infile >> name;
  }
  // counter = counter + temp;

  cout <<  counter << endl;

  return 0;

}

float square (int zippydee)
{
  return zippydee * zippydee;
}

int cube (int zippydoo)
{
  return zippydoo * zippydoo * zippydoo;
}

int powerfun (int x, int y)
{
  int temp = x;
  for (int i=1; i<y; i++)
  {
   temp *= x;
   // temp = temp * x;
  }
  return temp;
}
