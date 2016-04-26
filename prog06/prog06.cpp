// prog06.cpp
#include <iostream> 
#include <fstream>
using namespace std;
#define ARRAY_SIZE 10
class PatientRecord {
  public:
    string lname;
    string fname;
    int id;
    char gender;
    float exam1, exam2, exam3;
    PatientRecord * next;
};
int main() {
  
  // declare input file stream and open the file
  ifstream inData ("1.data");
  ofstream outData ("out.data");
  
  //declare variables (same as class)
  string lname;
  string fname;
  int id;
  char gender;
  float exam1, exam2, exam3;
  
  // declare parallel arrays
  int idarray[ARRAY_SIZE];
  PatientRecord * ptrarray[ARRAY_SIZE];
  int counter = 0;
  PatientRecord * lastptr = NULL, * head = NULL;
  
  while (inData >> lname >> fname >> id >> gender
    >> exam1 >> exam2 >> exam3) {
    // assign values from file to object elements
    ptrarray[counter] = new PatientRecord;
    ptrarray[counter]->lname = lname;
    ptrarray[counter]->fname = fname;
    ptrarray[counter]->id = id;
    ptrarray[counter]->gender = gender;
    ptrarray[counter]->exam1 = exam1;
    ptrarray[counter]->exam2 = exam2;
    ptrarray[counter]->exam3 = exam3;
    ptrarray[counter]->next = lastptr;
    if (head == NULL) head = ptrarray[counter];
    
    idarray[counter] = id;
    
    counter++;
  }
  
  // sort both idarray and ptrarray
  
for (int i=0; i< (ARRAY_SIZE -1); i++) {
   for(int j = (i+1); j < ARRAY_SIZE; j++)
   {
      if (idarray[i] > idarray[j])
      {
         int temp= idarray[i];
         idarray[i] = idarray[j];
         idarray[j] = temp;
         PatientRecord * temp2= ptrarray[i];
         ptrarray[i] = ptrarray[j];
         ptrarray[j] = temp2;
      }
   }
}
  // print sorted data
  
  for (int i=0; i<ARRAY_SIZE; i++) {
    outData << ptrarray[i]->lname << " " << ptrarray[i]->fname << " " <<
    ptrarray[i]->id << " "<< ptrarray[i]->gender << " "<<
    ptrarray[i]->exam1 << " "<< ptrarray[i]->exam2 << " "<<
    ptrarray[i]->exam3 << " " << endl;
  }
  return 0;
}  
