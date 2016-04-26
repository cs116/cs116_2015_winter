//******************************************************************
// program:    name2.cpp
// by:         George Corser
// source:     page 174 of textbook (copied verbatim)
// date:       Mon, Sep 22, 2014
// 
// Format Names program
// This program reads in a social security number, a first name, a 
// middle name or initial, and a last name from file inData.  
//
// modification: if input file has only ssn and 2 names, then
// program assumes no middle name (labeled: gpc0922)
//
// The name is written to file outData in three formats: 
//    1. First name, middle name, last name, and social security 
//    number.
//    2. last name, first name, middle name, and social 
//    security number
//    3. last name, first name, middle initial, and social security
//    number
//    4.  First name, middle initial, last name
//******************************************************************

#include <fstream>    // Access ofstream
#include <string>     // Access string

using namespace std;  // to make codemore readable (no "std::" prefix)

int main()
{
    // Declare and open files
    ifstream inData;		// declare infile object
    ofstream outData;		// declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile
  
    // Declare variables
    string socialNum;	// Social security number
    string firstName;   // First name
    string lastName;	// Last name
    string middleName;	// Middle name
    string initial;	// Middle initial
  
    // Read in data from file inData
    inData >> socialNum >> firstName >> middleName >> lastName;

    // gpc0922: If only two names, assume no middle name
    // i.e., swap (blank) last name and middle name
    if (lastName == "")
    {
        lastName = middleName; 
        middleName = " ";
    }

    // Access middle initial and append a period
    initial = middleName.substr(0, 1) + '.';

    // gpc0922: if no middle name then don't print middle name or initial
    if (middleName == " ")
    {
    outData << firstName <<  ' ' << lastName 
            << ' ' << socialNum << endl;
    outData << lastName << ", " << firstName 
            << ' ' << socialNum  << endl;
    outData << lastName << ", " << firstName 
            << ' ' << socialNum  << endl;
	outData << firstName << ' ' << lastName << endl;
    }
    else // otherwise print using original code, below
    { 
    // Output information in required formats
    outData << firstName << ' ' << middleName << ' ' << lastName 
            << ' ' << socialNum << endl;
    outData << lastName << ", " << firstName << ' ' << middleName 
            << ' ' << socialNum  << endl;
    outData << lastName << ", " << firstName << ' ' << initial 
            << ' ' << socialNum  << endl;
	outData << firstName << ' ' << initial << ' ' << lastName << endl;
    }
 
    // Close files
    inData.close();
    outData.close();
    return 0;
}  
  
