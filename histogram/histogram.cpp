// filename: histogram.cpp
// author  : george corser, cs116

#include <fstream>  //for input file stream
#include <string>   // for string declaration
#include <iostream> // for cout
using namespace std;

int main() {

// Declare and open files
ifstream inData;         // input file object
inData.open("in.data");  // open the input file

// Declare variables
const int E = 20;        // histogram "bucket" threshholds
const int D = 40;
const int C = 60;
const int B = 80;
const int A = 100;
int a=0, b=0, c=0, d=0, e=0; // histogram "buckets" counters
int temp=-1;
string tempstring = "";

inData >> temp;

while (temp >=0)
{
  if (temp < E) e++;
  else
    if (temp < D) d++;
    else
      if (temp < C) c++;
      else
        if(temp < B) b++;
        else a++;
  temp = -1;
  inData >> temp;
}
// cout << a << " " << b << " " << c << " " << d << " " << e << endl;

tempstring = "";
cout << "A : " ;
for (int i = 0; i < a; i++) tempstring += "*";
cout << tempstring << endl;

tempstring = "";
cout << "B : " ;
for (int i = 0; i < b; i++) tempstring += "*";
cout << tempstring << endl;

tempstring = "";
cout << "C : " ;
for (int i = 0; i < c; i++) tempstring += "*";
cout << tempstring << endl;

tempstring = "";
cout << "D : " ;
for (int i = 0; i < d; i++) tempstring += "*";
cout << tempstring << endl;

tempstring = "";
cout << "E : " ;
for (int i = 0; i < e; i++) tempstring += "*";
cout << tempstring << endl;

return 0;

}
