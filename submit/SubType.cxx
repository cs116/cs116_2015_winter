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
// This is the class implementation file.
//
// Finalized:  December 08, 2009
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Revision History:
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "SubType.h"

SubType::SubType()
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Default Constructor. Sets private vars to default values.
//   
// Input:     None
// Output:    None
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
   sourceFiles = "xxx";
   comFlags = "";
   linkFlags = "";
   inputFiles = "xxx";
   isCompiled = 0;
}

SubType::SubType(string sf, string cf, string lf, string ipf, int ic)
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Init Constructor.  Sets private vars to user defined values.
//   
// Input:      sf, cf, lf, ipf
// Output:     None
// Requires:   sf, cf, lf, ipf are valid strings
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
   sourceFiles = sf;
   comFlags = cf;
   linkFlags = lf;
   inputFiles = ipf;
   isCompiled = ic;
}

string SubType::GetSources()
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Gets value of sourceFiles.
//
// Input:     None
// Output:    string
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   return sourceFiles;
}

string SubType::GetInputs()
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Gets value of inputFiles.
//
// Input:     None
// Output:    string
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   return inputFiles;
}

int SubType::GetIsCompiled()
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Gets value of isCompiled.
//
// Input:     None
// Output:    int
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   return isCompiled;
}

void SubType::SetSources(string sf)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets value of sourceFiles
// 
// Input:     string
// Output:    None
// Requires:  sf is valid.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   sourceFiles = sf;
}

void SubType::SetInputs(string ipf)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets value of inputFiles
//
// Input:     string
// Output:    None
// Requires:  ipf is valid.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   inputFiles = ipf;
}

void SubType::SetComFlags(string cf)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets value of comFlags
//
// Input:     string
// Output:    None
// Requires:  cf is valid
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   comFlags = cf;
}

void SubType::SetLinkFlags(string lf)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets value of linkFlags
//
// Input:     string
// Output:    None
// Requires:  lf is valid
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   linkFlags = lf;
}


string SubType::MakeFileName()
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Creates random string to be used as filename.
//   
// Input:     None
// Output:    string
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
   const char CHARS_USED[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int numChars = 10;
   int charIndex = 0;
   int countChars = 0;
   char rndChar;
   string rndString;

   srand(time(0));

   while(countChars < numChars)
   {
      charIndex = (rand()%61);
      rndChar = CHARS_USED[charIndex];
      rndString += rndChar;
      countChars ++;
   }

   return rndString;
}

void SubType::PostClean(string fn, string fn2)
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Cleans up working directory of files created during run
// process of this program.
//   
// Input:     string
// Output:    None
// Requires:  Input is valid string
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
   
   //Use a string for concatenation of commands and variables
   //because the system command does not accept concatenation.
   string rmCmd;

   rmCmd = "/bin/rm -f " + fn;
   system(rmCmd.c_str());

   rmCmd = "/bin/rm -f " + fn2;
   system(rmCmd.c_str());

   system("/bin/rm -f a.out");
   system("/bin/rm -f *.o");
   system("/bin/rm -f *.lis");
}

void SubType::MakeNumbered(string fn, string fn2)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Copies outfile to file with numbered lines.  
//
// Input:     string fn, string fn2
// Output:    None
// Requires:  fn, fn2 are valid filenames
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string rmCmd;

   //Remove null characters, first.
   rmCmd = "/usr/bin/sed 's/\\x1//g' " + fn + " > " + fn2;
   system(rmCmd.c_str());
   rmCmd = "/bin/cp " + fn2 + " " + fn;
   system(rmCmd.c_str());
   rmCmd = "/usr/bin/sed 's/\\x0//g' " + fn + " > " + fn2;
   system(rmCmd.c_str());
   rmCmd = "/bin/cp " + fn2 + " " + fn;
   system(rmCmd.c_str());

   rmCmd = "/bin/cat -n " + fn + "> " + fn2;
   system(rmCmd.c_str()); 
}

void SubType::AddDirListToFile(string fn)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Writes directory listing to outfile.
// 
// Input:     string
// Output:    None
// Requires:  fn is valid filename
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string rmCmd;
   rmCmd = "/bin/ls -oa >>" + fn;
   system(rmCmd.c_str());
}

void SubType::EmptyDirList(DirType*& list)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Empty directory list of its contents.
// 
// Input:     DirType
// Output:    None
// Requries:  list is valid
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   DirType* tmpList;

   while(list != NULL)
   {
      tmpList = list;
      list = list->next;
      delete tmpList;
   }
}

void SubType::PreviewAssignment(string fn)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// View outfile on screen.
//
// Input:     string
// Output:    None
// Requires:  fn is valid filename
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string rmCmd;
   rmCmd = "/bin/more " + fn;
   system(rmCmd.c_str());
}

void SubType::PreClean()
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Cleans up working directory of files that we do not want prior
// to running this program.
//
// Input:     None
// Output:    None   
// Requires:  None
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
   system("/bin/rm -f a.out");
   system("/bin/rm -f *.o");
   system("/bin/rm -f *.lis");
   system("/bin/rm -f in.data");
   system("/bin/rm -f out.data");   
}

void SubType::SetExtensions()
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Sets the prog and data file extensions according to what is
// in the cwd.
//
// Input:     None 
// Output:    None
// Requires:  cwd is not empty.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
   int pos = -1;
   int dflag = 0;
   string tmpStr;

   //Directory pointers for dirent class.
   DIR *thisDir = NULL;
   thisDir = opendir (".");
   struct dirent *thisEnt = NULL;

   //Error handling.  Try catch is not really needed here because we can
   //handle this with a simple if/then.
   if (thisDir == NULL)
   {
      cout << "ERROR 1000: User home directory could not be initialised correctly";
      cout << " in SubType::ProcessDirList Implementation File.\n";
   }
   else
   {
      //Loop through the cwd, pull in the dir listing and put it into a linked
      //list.  We use a linked list because the number of listings is unknown.
      while(thisEnt = readdir(thisDir))
      {
         try
         {
            tmpStr = thisEnt->d_name;
            pos = tmpStr.find(".");
         }
         catch(out_of_range& e)
         {
            string rmCmd, tmpStr;
            tmpStr = thisEnt->d_name;

            rmCmd = "/bin/mv " + tmpStr + " " + tmpStr + ".f99";
            system(rmCmd.c_str());

            inputFiles = ".f99";
         }
         catch(exception& e)
         { 
            string rmCmd, tmpStr;
            tmpStr = thisEnt->d_name;

            rmCmd = "/bin/mv " + tmpStr + " " + tmpStr + ".f99";
            system(rmCmd.c_str());
            inputFiles = ".f99";
         }

         if(pos > 0)
         {
            //Use the tmpStr variable to find the file extensions.
            //We need to know the prog extensions and the data file
            //extensions.  We'll stuff those into a private variable
            //for later use.
            tmpStr = tmpStr.substr(pos);

            //Look for prog ext first:
            pos = tmpStr.find(".c");
            if((pos == 0) && (sourceFiles == "xxx"))
               sourceFiles = tmpStr;

            //Now look for fall data files:
            pos = tmpStr.find(".f");
            if((pos == 0) && (inputFiles == "xxx"))
               inputFiles = tmpStr;

            //Look for winter data files:
            pos = tmpStr.find(".w");
            if((pos == 0) && (inputFiles == "xxx"))
               inputFiles = tmpStr;

            //Look for spring/summer data files:
            pos = tmpStr.find(".s");
            if((pos == 0) && (inputFiles == "xxx"))
               inputFiles = tmpStr; 
            
            //Look for Lee data files:
            pos = tmpStr.find(".dat");
            if((pos == 0) && (inputFiles == "xxx"))
            {
               if(thisEnt->d_name != "in.data")
                  inputFiles = tmpStr;
            }

            if(thisEnt == NULL)
            {
               cout << "ERROR 1001: Directory entry could not be initialised correctly";
               cout << " in SubType::ProcessDirList Implementation File.\n";
            }

         }
         else if(pos == -1)
         {
            char input;
            string rmCmd, tmpStr;
            tmpStr = thisEnt->d_name;

            cout << "Datafile:  " + tmpStr + " does not have an extension.  " << endl << endl;
            cout << "Is this file meant to be one of your program data files?  [ y/n ] :";

            if(isspace(input))
               cin.ignore();

            cin.clear();
            input = cin.get();
            cin.ignore();

            while((input != 'y') && (input != 'n'))
            {
               cout << "You entered:  " << input << endl;
               cout << "Enter 'y' or 'n' (case sensitive):  ";

               if(isspace(input))
                  cin.ignore();
      
               cin.clear();
               input = cin.get();
               cin.ignore();
            }

            if(input == 'y')
            {
               cout << "Setting datafile extension to:"  << endl << endl << "                .f99";
               rmCmd = "/bin/mv " + tmpStr + " " + tmpStr + ".f99";
               system(rmCmd.c_str());
               inputFiles = ".f99";
               dflag ++;
            }
            else
            {
               cout << "Skipping " + tmpStr << endl << endl;
            }
         }
      }
      
      if(dflag > 0)
      {
         cout << endl << endl << "*********************************************************";
         cout << endl << "**                                                     **";
         cout << endl << "**                       TAKE NOTE                     **";
         cout << endl << "**                                                     **";
         cout << endl << "**   ANSWER YES WHEN YOU ARE ASKED IF YOUR DATA FILES  **";
         cout << endl << "**                     END WITH .f99                   **";
         cout << endl << "**                                                     **";
         cout << endl << "*********************************************************";
         cout << endl << endl;
      }
   }
}

DirType* SubType::MakeDataFileList(DirType* list)
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Gets listing of data files in current working directory.
//
// Input:     DirType
// Output:    None
// Requires:  DirType is initialized.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
   DirType* tmpList;
   tmpList = new DirType;
   tmpList = list;

   int pos, dot, ext;
   string tmpStr;

   ext = -1;

   //Directory pointers for dirent class.
   DIR *thisDir = NULL;
   thisDir = opendir (".");
   struct dirent *thisEnt = NULL;

   //Error handling.  Try catch is not really needed here because we can
   //handle this with a simple if/then.
   if (thisDir == NULL)
   {
      cout << "ERROR 1000: User home directory could not be initialised correctly";
      cout << " in SubType::ProcessDirList Implementation File.\n";
   }
   else
   {
      //Loop through the cwd, pull in the dir listing and put it into a linked
      //list.  We use a linked list because the number of listings is unknown.
      while(thisEnt = readdir(thisDir))
      {
         tmpStr = thisEnt->d_name;
         pos = tmpStr.find("a.out");
         dot = tmpStr.find(".");

         if(pos == 0)
         {
            isCompiled = 1;
         }

         if(dot != 0)
         {
            tmpStr = tmpStr.substr(dot);
            ext = tmpStr.find(inputFiles);
         }
             
         if(ext == 0)
         {
            DirType* newList;
            newList = new DirType;

            newList->info = thisEnt->d_name;
            newList->next = NULL;


            if(thisEnt == NULL)
            {
               cout << "ERROR 1001: Directory entry could not be initialised correctly";
               cout << " in SubType::ProcessDirList Implementation File.\n";
            }
            else if(tmpList->info == "==##==empty==##==")
            {
               list = newList;
               tmpList = newList;
               cout << tmpList->info << endl;
            }
            else
            {
               if(tmpList->next == NULL)
               {
                  tmpList->next = newList;
                  tmpList = tmpList->next;
                  cout << tmpList->info << endl;
               }
            }
         }
      }
   
      return list;
   }
}

DirType* SubType::MakeSourceFileList(DirType* list)
{
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Gets listing of source files in current working directory.
//
// Input:     DirType
// Output:    None
// Requires:  DirType is initialized.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
   DirType* tmpList;
   tmpList = new DirType;
   tmpList = list;

   int pos, dot, ext, exth;
   string tmpStr;
   string hStr = ".h";

   //Directory pointers for dirent class.
   DIR *thisDir = NULL;
   thisDir = opendir (".");
   struct dirent *thisEnt = NULL;

   //Error handling.  Try catch is not really needed here because we can
   //handle this with a simple if/then.
   if (thisDir == NULL)
   {
      cout << "ERROR 1000: User home directory could not be initialised correctly";
      cout << " in SubType::ProcessDirList Implementation File.\n";
   }
   else
   {
      //Loop through the cwd, pull in the dir listing and put it into a linked
      //list.  We use a linked list because the number of listings is unknown.
      while(thisEnt = readdir(thisDir))
      {
         ext = -1;
         exth = -1;
         tmpStr = thisEnt->d_name;
         dot = tmpStr.find(".");
      
         if(dot != 0)
         {
            tmpStr = tmpStr.substr(dot);
            ext = tmpStr.find(sourceFiles);
            exth = tmpStr.find(hStr);
         }

         if((ext == 0) || (exth == 0))
         {
            DirType* newList;
            newList = new DirType;

            newList->info = thisEnt->d_name;
            newList->next = NULL;


            if(thisEnt == NULL)
            {
               cout << "ERROR 1001: Directory entry could not be initialised correctly";
               cout << " in SubType::ProcessDirList Implementation File.\n";
            }
            else if(tmpList->info == "==##==empty==##==")
            {
               list = newList;
               tmpList = newList;
               cout << tmpList->info << endl;
            }
            else
            {
               if(tmpList->next == NULL)
               {
                  tmpList->next = newList;
                  tmpList = tmpList->next;
                  cout << tmpList->info << endl;
               }
            }
         }
      }

      return list;
   }
}
void SubType::RunAOut()
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Runs C++ executable in cwd.
// 
// Input:     None.
// Output:    None.
// Requires:  a.out must exist.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   system("./a.out");   
}

void SubType::CopyInFile(string fn, string fn2)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Copies data file to in.data
//
// Input:     string
// Output:    None
// Requires:  fn is valid string
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   string rmCmd;
   rmCmd = "/bin/cp " + fn + " " + fn2;

   system(rmCmd.c_str());
}

void SubType::CopyToOutfile(ofstream& outFile, string fn)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Copies contents of file to outFile.
// 
// Input:     string
// Output:    ofstream
// Requires:  outFile open, fn is valid filename
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string line;
   ifstream inFile;

   inFile.open(fn.c_str());

   while(!inFile.eof())
   {
      getline(inFile, line);
      outFile << line << endl;
   }
   inFile.close();
}

string SubType::CopyToString(string fn)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Copies contents of file to string
//
// Input:     string
// Output:    string
// Requires:  fn is valid filename
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string theFile;
   string line;
   ifstream inFile;

   inFile.open(fn.c_str());
   
   while(!inFile.eof())
   {
      getline(inFile, line);
      theFile += line;
   }

   return theFile;
}

void SubType::CompileSources(string sf)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Compiles C++ source files.
//
// Input:     string
// Output:    None
// Requires:  sf is valid string.  Source files exist.
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
{
   string rmCmd;
   rmCmd = "/usr/bin/c++ " + sf;

   system(rmCmd.c_str());
}

void SubType::PrintOutput(int sel, string fn)
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Prints output to selected printer
//
// Input:     int, string
// Output:    None
// Requires:  int is in range, string is valid filename
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=   
{
   string rmCmd;

   switch(sel)
   {
      case 1:
         //SE145
         rmCmd = "/usr/local/bin/np " + fn;
         system(rmCmd.c_str());
         break;
      case 2:
         //SE135
         rmCmd = "/usr/local/bin/np135 " + fn;
         system(rmCmd.c_str());
         break;
      case 3:
         //SE104A
         rmCmd = "/usr/local/bin/np104A " + fn;
         system(rmCmd.c_str());
         break;
      case 4:
         //SE105A
         rmCmd = "/usr/local/bin/np105A " + fn;
         system(rmCmd.c_str());
         break;
      case 5:
         //SE105B
         rmCmd = "/usr/local/bin/np105B " + fn;
         system(rmCmd.c_str());
         break;
      case 6:
         //SE136
         rmCmd = "/usr/local/bin/np136 " + fn;
         system(rmCmd.c_str());
         break;	
      case 7:
         //SCCC122B
         rmCmd = "/usr/local/bin/np374 " + fn;
         system(rmCmd.c_str());
         break;
      case 8:
         //Print to File
         rmCmd = "/usr/local/bin/npFILE " + fn;
         system(rmCmd.c_str());
         break;    
   }
}
