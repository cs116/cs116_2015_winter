//******************************************************************
// program:    pass.cpp (Program 17)
// by:         George Corser
// date:       Mon, Oct 20, 2014
// 
// INPUT: File containing integers, one per line
// PROCESSING: Update, print and sort integers
// OUTPUT: File containing rearranged integers
//
//******************************************************************

#include <fstream>    // For input and output file streams
#include <string>     // For string data types
#include <iomanip>    // for setw()
#include <iostream>   // for endl
using namespace std;  // to make code more readable (no "std::" prefix)

void BubbleSort(int num[], int numLength);

int main()
{

    // 0. Initialize end-of-report variables
    
    int max = 0;
    int min = 1000000;
    float numaverage = 0.0;
    int numtotal = 0;           // used to compute numaverage
    int numcount = 0;           // used to compute numaverage
    int numarray[100]; 
    for (int i = 0; i < 100; i++) numarray[i] = -1;

    // 1. Declare and open files

    ifstream inData;		// declare infile object
    ofstream outData;		// declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile
  
    // 2. Read first number from file inData

    inData >> numarray[numcount] ;  // priming read

    // 3. Read remaining numbers

    while (numarray[numcount] > -1)
    {
        numcount++;
        inData >> numarray[numcount] ;  // read next number
    }

    // 4. Add one to even numbers in numarray

    for (int i = 0; i < numcount; i++)
    {
        if (numarray[i] % 2 == 0) numarray[i]++;
    }

    // 5. Add two numbers in numarray with odd index

    for (int i = 0; i < numcount; i++)
    {
        if (i % 2 != 0) numarray[i] += 2;
    }

    // 6. Print the array (Write output file)

    outData << "*~~<Numbers>~~" << endl; 

    for (int i = 0; i < numcount; i++)
    {
        outData << numarray[i] << endl;
    }

    // 7. Print max, min and average

    for (int i = 0; i < numcount; i++)
    {
        if (numarray[i] > max) max = numarray[i];
        if (numarray[i] < min) min = numarray[i];
        numtotal += numarray[i];
    }
   
    outData << "Max: " << max << endl;
    outData << "Min: " << min << endl;
    outData << setprecision(2) << fixed; 
    outData << "Average: " << float(numtotal) / numcount << endl; 
    
    // 8. Sort numarray

    BubbleSort (numarray, 100);
 	
    // Close files

    inData.close();
    outData.close();

    return 0;

} // END main()

// Source: http://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
// Bubble Sort Function for Descending Order 

void BubbleSort(int num[], int numLength)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;              // holding variable
      // int numLength = num.length( ); 
      for(i = 1; (i <= numLength) && flag; i++)
      {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
          {
               if (num[j+1] > num[j])   // ascending order simply 
                                        // changes to <
              { 
                    temp = num[j];      // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    flag = 1;  // indicates that a swap occurred.
               }
          }
     }
     return;   // nothing is returned
}
