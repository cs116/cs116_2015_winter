// filename: prog01.cpp
// author: george corser, cs116, 1/27/2014

#include <fstream>    // for input and output file streams
#include <string>     // for string data types
#include <iomanip>    // for setw()
#include <iostream>   // for cout, endl
using namespace std;  // to make code more readable (no "std::" prefix)

void printHeader (ofstream& outData);

int main()
{

    // Declare and open files
    ifstream inData;		    // declare infile object
    ofstream outData;		    // declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile

    string patientName;
    int patientID;
    float exam1, exam2, exam3;

    inData >> patientName >> patientID >> exam1 >> exam2 >> exam3;

    bool valid = true;
    if(patientID < 1111 || patientID > 9999) valid = false;
    if(exam1 < 0 || exam1 > 100) valid = false;
    if(exam2 < 0 || exam2 > 100) valid = false;
    if(exam3 < 0 || exam3 > 100) valid = false;
    float avg = (exam1 + exam2 + exam3 ) / 3;
    string posneg = "";
    if (valid)
    {
        if (avg > 70)
        {
            if (avg > 97) posneg = "Pos / RISK";
            else          posneg = "Pos";
        }
        else posneg = "Neg";
    }


    printHeader(outData);

    outData << patientName << "\t" << patientID << "\t\t" << exam1 << "\t" << exam2 << "\t" << exam3;
    if(valid) outData << "\t" << avg << "\t" << posneg;
    else outData << "\t~~ Invalid data~~";
    outData << endl << endl;
    outData << "*< End of Report >*" << endl;
}

void printHeader (ofstream& outData)
{
  outData << "*~~< Patient Exam Report >~~*" << endl << endl;
  outData << "Patient Name\tPatient ID\tExam1\tExam2\tExam3\tAVG\tPos/Neg" << endl;
  outData << "------------\t----------\t-----\t-----\t-----\t---\t-------" << endl;

}

