#include <iostream> // for cout stream object (for printing to screen)
#include <fstream>  // for ifstream file stream declaration
#include <string>   // for string variable declaration
#include <cstdlib>  // for atoi function
using namespace std;// to eliminate need to code "std::" before "cout"

int main() {

  string line = "";
  int i = 0;

  ifstream inFile;
  ofstream outFile;

  inFile.open("in.data", ios::in);
  outFile.open("out.data", ios::out);

  if (inFile.is_open() && outFile.is_open() ) {
    while ( getline ( inFile, line ) ) {
     // cout << line << endl;     // print the line to the screen
      i = atoi( line.c_str() );
     // cout << " - " << endl;
      outFile << line << endl;  // append to output file 
                                // the same line as input file
      outFile << " - " << endl; // insert a dash between every line
    }
  }
  

  inFile.close();
  outFile.close();
  return 0;
}
