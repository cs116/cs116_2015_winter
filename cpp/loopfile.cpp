// filename: loopfile.cpp
// description: print contents of a file, line by line
// input: in.data
// processing: read file, assign elements to variables,
//             cout variables
// outout: file contents print to screen

#include <fstream> // for input and ouput files
#include <string>
#include <iomanip> // setprecision), setw()
#include <iostream> // cout, endl
using namespace std;

int main()
{
  // declare file stream
  ifstream zippydee; // creates input file stream objet (like cin)
  zippydee.open("in.data");

  // declare variables
  string firstName = "";
  string lastName = "";
  int counter = 0;

  // read variable values from file
  while(zippydee >> firstName >> lastName)
  {
    cout << firstName << " " << lastName << endl;
    counter++;
  }
  cout << counter << " records processed." << endl << endl;

  return 0;
}
