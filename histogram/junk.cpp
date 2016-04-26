// filename    : prog1.cpp
// author      : george corser, CS116 TR
// input file  : in.data
// processing  : reads a record from an input file
//               and writes a report to an output file
// output file : out.data

// preprocessor directives
#include <fstream>    // for ifstream, ofstream
#include <string>     // for string data types
#include <iomanip>    // for formatting test setw, setprecision
#include <iostream>   // for endl, fixed
using namespace std;  // to make code more readable (no "std::" prefix)

void printHeader (ofstream& outData); // function prototype (declare function)

int main()
{

    // declare and open files
    ifstream inData;		// declare infile object
    ofstream outData;		// declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile

    // declare variables
    string patientName;
    int patientID;
    float exam1, exam2, exam3;
    float avg;
    string posneg;

    // read values from input file into variables
    inData >> patientName >> patientID >> exam1 >> exam2 >> exam3;

    // validate input data
    bool valid = true;
    if(patientID < 1111 || patientID > 9999) valid = false;
    if(exam1 < 0 || exam1 > 100) valid = false;
    if(exam2 < 0 || exam2 > 100) valid = false;
    if(exam3 < 0 || exam3 > 100) valid = false;

    // compute average exam score and pos/neg/risk rating
    avg = (exam1 + exam2 + exam3) / 3;
    if (avg > 70)
    {
        if (avg >= 97) posneg = "Pos / RISK";
        else posneg = "Pos";
    }
    else posneg = "Neg";

    // print report header
    printHeader(outData);

    // print report detail
    outData << setprecision(2) << fixed;
    outData << setfill(' ') << setw(15) << left << patientName;
    outData << setw(12) << left << patientID;
    outData << setw(7) << left << exam1;
    outData << setw(7) << left << exam2;
    outData << setw(7) << left << exam3;
    if (valid)
    {
        outData << setw(10) << left << avg;
        outData << setw(10) << left << posneg;
    }
    else outData << setw(20) << "~~ Invalid data ~~";
    outData << endl;

    outData << endl << "*< end of report >*" << endl;

	// close files
	inData.close();
	outData.close();
}

void printHeader (ofstream& outData)
{
  outData << "*~~< Patient Exam Report >~~*" << endl << endl;
  outData << setfill(' ') << setw(15) << left << "Name";
  outData << setw(12) << left << "Patient Id";
  outData << setw(7) << left << "Exam1";
  outData << setw(7) << left << "Exam2";
  outData << setw(7) << left << "Exam3";
  outData << setw(10) << left << "AVG";
  outData << setw(10) << left << "Pos/Neg";
  outData << endl;

  outData << setfill(' ') << setw(15) << left << "----";
  outData << setw(12) << left << "----------";
  outData << setw(7) << left << "-----";
  outData << setw(7) << left << "-----";
  outData << setw(7) << left << "-----";
  outData << setw(10) << left << "-----";
  outData << setw(10) << left << "-------";
  outData << endl;
}
