// filename: template.cpp

#include <fstream>    // For input and output file streams
#include <string>     // For string data types
#include <iomanip>    // for setw()
#include <iostream>   // for endl
using namespace std;  // to make code more readable (no "std::" prefix)

void printHeader (ofstream& outData);

int main()
{

    // Declare and open files
    ifstream inData;		    // declare infile object
    ofstream outData;		    // declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile

    printHeader(outData);
  
}

void printHeader (ofstream& outData)
{
  cout << "Header" << endl;
}

