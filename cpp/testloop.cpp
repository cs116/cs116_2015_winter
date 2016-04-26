// filename: cin1.cpp
#include <iostream> // cout, cin
#include <string>
#include <fstream>
using namespace std; // avoid std::cout

int main()
{

  // declare and open input file
  ifstream inFile;
  inFile.open("in.data");

  string fName = "", lName = "";
  int counter = 0;

  //inFile >> fName >> lName;
  while(inFile >> fName >> lName)
  {
    counter++;
    cout << fName << " " << lName << " " << counter << endl;
    // inFile >> fName >> lName;
  }

  return 0;
}
