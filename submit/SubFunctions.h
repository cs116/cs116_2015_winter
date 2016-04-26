//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  Written by Heather L. Sanders - Linux Systems Administrator
//   Saginaw Valley State Univerisity - (989) 964-2156 - W374
//                     hlsander@svsu.edu
//
// This is the new submittobidgoli program.  It is written in C++
// to address the issues with cheating.  Students will no longer
// be able view, copy, or modify the sourcecode.
//
// Interactively collects information from user.
// Compiles source code.
// Produces executable files.
// Produces output file for printing.
// Prints output file to designated printer.
// Cleans up temp files and exits.
//
// This is the Function Header File
//
// Finalized:  December 08, 2009
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// #include <iostream>
// #include <string>
// #include <stdlib.h>
// using namespace std;

string file1, file2;

void pressEnter(char input);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Prompts user to press 'Enter' to continue.
//
// Input:     char
// Output:    None
// Requires:  data stream is open and valid.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void getChar(char& input);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Pulls one character only from stream.
//
// Input:     char
// Output:    None
// Requires:  data stream is open and valid.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void chkInput(char& input, int& selection, int menuTest);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Validates numeric input.  
//
// Input:     char
// Output:    None
// Requires:  input, selection, and menuTest are valid.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void handleCTRL(int sig);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Catches CTRL-key combinations.  Cleans up temp files and exits
//
// Input:     int
// Output:    None
// Requires:  sig is int.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void SetFilenames(string fn1, string fn2);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets filenames so that the signal handler has access to them.
//
// Input:     strings
// Output:    strings
// Requires:  two valid strings
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


void chkYesNo(char& input)
{
   while((input != 'y') && (input != 'n'))
   {
      cout << "You entered:  " << input << endl;
      cout << "Enter 'y' or 'n' (case sensitive):  ";
      getChar(input);
   }
}

void pressEnter(char input)
{
   while((cin.get(input)) && (input != '\n'))
      ;
}

void getChar(char& input)
{
   if(isspace(input))
      cin.ignore();

   cin.clear();
   input = cin.get();
   cin.ignore();
}

void chkInput(char& input, int& selection, int menuTest)
{
   if(isspace(input))
      cin.ignore();

   if(isdigit(input))
   {
      //Type convert input to an int, so we can evaluate it.
      selection = atoi(&input);

      while((selection <= 0) || (selection > menuTest))
      {
         cout << "Invalid number selection.  Please select item 1 - " << menuTest << ":  ";
         getChar(input);
         selection = atoi(&input);
      }
   }
   else
   {
      while(!isdigit(input))
      {
         do
         {
            cout << "Invalid character selection.  Please select item 1 - " << menuTest << ":  "; 
            getChar(input);
            selection = atoi(&input);
         }while((selection <= 0) || (selection > menuTest));
      }
   }
}

void handleCTRL(int sig)
{
   string rmCmd;

   cout << endl << "Signal " << sig << " caught." << endl;
   cout << "Cleaning up .... ";

   rmCmd = "/bin/rm -f " + file1;
   system(rmCmd.c_str());

   rmCmd = "/bin/rm -f " + file2;
   system(rmCmd.c_str());

   system("/bin/rm -f a.out");
   system("/bin/rm -f *.o");
   system("/bin/rm -f *.lis");

   cout << "Done!" << endl;

   exit(1);
}

void SetFilenames(string fn1, string fn2)
{
   file1 = fn1;
   file2 = fn2;
}   
