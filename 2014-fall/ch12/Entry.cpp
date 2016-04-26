//*****************************************************************
// IMPLEMENTATION FILE (Entry.cpp)
// This file contains the specification of the Entry ADT,
// which has two contained classes, Name and Time
//*****************************************************************
 
#include "Entry.h"
#include <string>
#include <iostream>
using namespace std;

string Entry::GetNameStr() const

{
  return (name.GetFirstName() + ' ' + name.GetLastName());
}

//****************************************************************

string Entry::GetTimeStr() const
{
  string outStr;
  ostringstream tempOut;	 // Access ostringstream

  if (time.GetHours() < 10)
    tempOut << '0';
  tempOut << time.GetHours() << ":";
  if (time.GetMinutes() < 10)
    tempOut << '0';
  tempOut << time.GetMinutes() << ":";
  if (time.GetSeconds() < 10)
    tempOut << '0';
  tempOut << time.GetSeconds();
  outStr = tempOut.str();
  return outStr;       
}

//**************************************************************
 
Entry::Entry()
{
}
 
//*************************************************************

Entry::Entry(string firstName, string middleName, string lastName,
        int  initHours, int  initMinutes, int  initSeconds )   

  : name(firstName, middleName, lastName),
    time(initHours, initMinutes, initSeconds)
{
}

