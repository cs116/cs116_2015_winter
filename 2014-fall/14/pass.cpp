//******************************************************************
// program:    pass.cpp
// by:         George Corser
// date:       Mon, Oct 20, 2014
// 
// INPUT: This program reads from a file:  
// student id (1111 <= studID <= 9999), number of scores,  and exam scores
// (0.00 <= exam <= 100.00). Input file may contain MULTIPLE records.
// in the following format:
//
// 1111 3 75 80 70
//
// MAIN PROCESSING: This program does the following.
//
// 0. initialize end-of-report variables
// 1. print report title
// 2. print column headings
// 3. read first student ID
// WHILE records exist in input file
//   4. print student id
//   4a. read number of exams
//   WHILE unread exams exist
//       4b. read next exam
//       add exam to accumulator
//   compute average for student
// get next record from input file
// END WHILE
//  
// 10. print end-of-report message
// 11. print end-of-report statistics
//
// OUTPUT: This program writes to an output file: a formatted report
// showing student ID's and average scores

//
//******************************************************************

#include <fstream>    // For input and output file streams
#include <string>     // For string data types
#include <iomanip>    // for setw()
#include <iostream>   // for endl
using namespace std;  // to make code more readable (no "std::" prefix)

int main()
{

    // 0. initialize end-of-report variables
    float quizAVG = 0; 
    int quizQTY = 0;
    int totalQuizzes = 0;
    int totalStudents = 0;

    // Declare and open files
    ifstream inData;		    // declare infile object
    ofstream outData;		    // declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile
  
    // Declare variables
    string studID;   // Student ID, must be between "1111" and "9999"
    float examScore = 0;
    int numOfExams = 0;

    // ---------- MAIN PROCESSING ----------------------------------
	
    // 1. print report title
    outData << endl << endl << left; // left align all items in report
    outData << "*~~< Stud Quiz Report >~~*" << endl;

    // 2. print column headings
    outData << setw(8) << "Stud ID";
    outData << setw(7) << "AVG of All Quizzes" << endl;
	
    // 3. Read first student ID 
    studID = "";
    inData >> studID;

  // WHILE records exist in input file
  while( studID > "")
  {
    // 4. print student ID
    outData << setw(8) << studID;
    outData << setprecision(2) << fixed ;

    // 4a. read number of quizzes
    inData >> numOfExams;
    quizQTY = numOfExams;
    quizAVG = 0;

    while(numOfExams > 0)
    {
       numOfExams--;
       totalQuizzes++;
       inData >> examScore;
       quizAVG = quizAVG + examScore;       
    }
    quizAVG = quizAVG / quizQTY;

    outData << quizAVG;

  outData << endl;
  studID = ""; 
  inData >> studID;
  totalStudents++;

  } // END WHILE

   // ----- End of report infomration -----

   outData << "There were " << totalStudents;
   outData << " students & " << totalQuizzes;
   outData << " quizzes in file." << endl << endl;
	
   outData << "*~ end ~*" << endl<<endl;
  // ---------- END OF MAIN PROCESSING ------------------------
	
    // Close files
    inData.close();
    outData.close();
    return 0;
} 
