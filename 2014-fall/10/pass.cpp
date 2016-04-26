//******************************************************************
// program:    pass.cpp
// by:         George Corser
// date:       Fri, Sep 26, 2014
// 
// INPUT: This program reads from a file: last name (with comma), 
// first name, student id (1111 <= studID <= 9999) and three exam scores
// (0.00 <= exam <= 100.00). The input file contains one record
// in the following format:
//
// Lewis, Rose 1111 75 80 70
//
// MAIN PROCESSING: This program does the following.
// 
// 1. print report title
// 2. print column headings
// 3. print name
// 4. print student id
// 5. set precision, and print exam1
// 6. print exam2
// 7. print exam3
// 8. if all exam scores in valid range (0, 100)...
//      8a. print average
//      if average >= 97...
//        9b. print "PASSED / TOP"
//      else
//        if average >= 70...
//            9a. print "PASSED"
//        else
//            9b. print "FAILED"
//    else
//      8b. print "invalid data"
// 10. print end-of-report message
//
// OUTPUT: This program writes to an output file: a formatted one-line report
// indicating one of the following: the student passed, the student 
// passed at the top of the class, the student failed, or the file
// had invalid data. The output file contains data in one of the 
// following formats: 
//
// *~~< Stud Exam Report >~~*
// Name            Stud Id  Exam1  Exam2  Exam3  AVG    Passed/Failed
// Lewis, Rose     1111     75.00  80.00  70.00  75.00  PASSED
// *< end >*
//
// *~~< Stud Exam Report >~~*
// Name            Stud Id  Exam1  Exam2  Exam3  AVG    Passed/Failed
// Lewis, Rose     1111     75.00  80.00 101.00  ~~ Invalid data ~~
// *< end >*
//
// *~~< Stud Exam Report >~~*
// Name            Stud Id  Exam1  Exam2  Exam3  AVG    Passed/Failed
// Lewis, Rose     1111     97.00  97.00  97.00  97.00  PASSED / TOP
// *< end >*
//
// *~~< Stud Exam Report >~~*
// Name            Stud Id  Exam1  Exam2  Exam3  AVG    Passed/Failed
// Lewis, Rose     1111     0.00   0.00   0.00   0.00   FAILED
// *< end >*
//
//******************************************************************

#include <fstream>    // For input and output file streams
#include <string>     // For string data types
#include <iomanip>    // for setw()
#include <iostream>   // for endl
using namespace std;  // to make code more readable (no "std::" prefix)

int main()
{
    // Declare and open files
    ifstream inData;		    // declare infile object
    ofstream outData;		    // declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile
  
    // Declare variables
    string lname;    // Last name, with trailing comma (ex: "Smith,")
    string fname;    // First name
    string fullname; // Full name
    string studID;   // Student ID, must be between "1111" and "9999"
    float exam1;     // Score on Exam 1
    float exam2;     // Score on Exam 2
    float exam3;     // Score on Exam 3

    // Read in data from file inData
    inData >> lname >> fname >> studID >> exam1 >> exam2 >> exam3;

	// ---------- MAIN PROCESSING ----------------------------------
	
    // 1. print report title
	outData << endl << left; // left align all items in report
    outData << "*~~< Stud Exam Report >~~*" << endl;

    // 2. print column headings
    outData << setw(14) << "Name";
    outData << setw(8) << "Stud ID";
    outData << setw(7) << "Exam1";
    outData << setw(7) << "Exam2";
    outData << setw(7) << "Exam3";
    outData << setw(7) << "AVG";
    outData << "Passed/Failed" << endl;
 
    // 3. print name
    fullname = lname + ' ' + fname; // last name is assumed to contain trailing comma
    outData << setw(14) << fullname; // width 14 characters
	
    // 4. print student ID
    outData << setw(8) << studID;
	
    // 5. set precision 2 for all numbers, and print exam1 score
    outData << setprecision(2) << fixed ;
    outData << setw(7) << exam1;

    // 6. print exam2 score
    outData << setw(7) << exam2;
	
    // 7. print exam3 score
    outData << setw(7) << exam3;
	
    // print average and pass/fail/top indicator
    if (exam1 >= 0 and exam1 <= 100 and exam2 >= 0 and exam2 <= 100 and
        exam3 >= 0 and exam3 <= 100) // if all the exams have valid scores
    {
        // 8a. print average
        outData << setw(7) << (exam1+exam2+exam3)/3;
        // print pass/fail/top indicator
        if ((exam1+exam2+exam3)/3 >= 97)
		    // 9b. print "PASSED / TOP"
            outData << "PASSED / TOP";
        else
            if ((exam1+exam2+exam3)/3 >= 70)
			    // 9a. print "PASSED"
                outData << "PASSED";
            else
			    // 9c. print "FAILED"
                outData << "FAILED";
    }
    else
	    // 8b. print invalid data message
        outData << "~~ Invalid data ~~";

    // 10. print end-of-report message
	outData << endl;
    outData << endl << "< end >" << endl << endl;
	
	// ---------- END OF MAIN PROCESSING --------------------------------
	
    // Close files
    inData.close();
    outData.close();
    return 0;
} 
