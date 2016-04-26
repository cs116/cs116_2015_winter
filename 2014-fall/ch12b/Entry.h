//*****************************************************************
// SPECIFICATION FILE (Entry.h)
// This file contains the specification of the Entry ADT, which has 
// two contained classes, Name and Time
//*****************************************************************
 
#include "TimeOfDay.h"
#include "Name.h"
#include <sstream>
#include <string>
 
class Entry
{
public:
  string GetNameStr() const;
  // Post: Returns the first and last name of Name object  
  //       with a blank in between  
  string GetTimeStr() const;
  // Post: Returns the hours and minutes from TimeOfDay object
  //       with a colon in between 
  Entry();
  // Default constructor
  // Post: Entry object has been constructed
  //       Name and TimeOfDay objects have been constructed using
  //       their defualt constructors 
  Entry(string firstName, string middleName, string lastName,
        int initHours, int initMinutes, int initSeconds );   
  // Parameterized constructor
  // Post: Entry object has been constructed.
  //       Name and TimeOfDay objects have been constructed using
  //       their parameterized constructors 
private:
  Name name;
  TimeOfDay time;
};