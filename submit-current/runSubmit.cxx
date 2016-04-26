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
// This is the run file
//
// Finalized:  December 08, 2009
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Revision History:
//
// 02/01/2010:  Heather Sanders
// Updated printer configuration.
//
// 02/18/2010:  Heather Sanders
// Added signal handling to catch CTRL-C.  Program will now exit
// and clean up temp files, if user presses CTRL-C.
//
// Fixed printing issues where assignments containing null chars
// would not print.  Null chars are stripped just prior to 
// printing.
//
// 10/06/2010:  Heather Sanders
// Added command to output file check that lists directory 
// contents to assist in troubleshooting file permission issues.
//
// 10/26/2012:  Heather Pegg
// Made two cosmetic changes.  Dropped the '2010' from the intro
// Changed the network services printer name to reflect our new
// location.
// 
// 09/30/2013:  Heather Pegg
// Added function in SubType class that sorts linked lists.
// The linked list that displays the data files will now be 
// sorted.
//
// Added defensive code in linked list creation that no longer
// allows '.' and '..' to be added to the linked lists.
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "SubType.h"
#include "SubFunctions.h"


int main()
{
   //=-=-=-=-=-=-=-= Declarations  =-=-=-=-=-=-=-=
   // All of the variables the main function
   // will use:
   //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

   char input;                //User input
   int menuTest;              //Menu Size
   int selection;             //User input converted to int
   int compileChk;            //If a.out exists
   int copyChk;               //If copy succeeded.
   int answers[4];            //Flags for menu selection
   string progExt, dataExt;   //User defined extensions for cxx & data files
   string comFlags, linkFlags;//User defined Compiler and Linker flags.
   string befFile, aftFile;   //outFile checks.
   string fileName, fileName2;//Output files
   SubType st;                //Class object
   DirType* dflist;           //Points to head of link list for datafile list.
   DirType* dflocator;        //Locator pointer in datafile list
   DirType* dfnextlist;       //Next location pointer in datafile list.
   DirType* sflist;           //Points to head of link list for sourcefile list.
   DirType* sflocator;        //Locator pointer in sourcefile list.
   DirType* sfnextlist;       //Next location in sourcefile list.
   ofstream outFile;          //Our outfile that we will be writing to.
   ofstream dirFile;          //Temp file that contains the dir listing.
   time_t currDate;           //Datestamp

   //=-=-=-=-=-=-= End Declarations =-=-=-=-=-=-=

   //We need to catch any CTRL-key combos, because they cause bad things to 
   //happen.
   
   //CTRL-C
   signal(SIGINT, &handleCTRL);
   //CTRL-backslash
   signal(SIGABRT, &handleCTRL);
   //
   signal(SIGTERM, &handleCTRL);
   //CTRL-Z
   signal(SIGTSTP, &handleCTRL);
   //CTRL-D
   signal(0, &handleCTRL);

   //Clear the screen and greet the user.
   system("/usr/bin/clear");
   cout << "This is submittobidgoli.  Please follow the instructions." << endl;
   cout << endl << "This program will ask you a few questions.  You will be ";
   cout << "informed of what " << endl << "you can and cannot do as you go through ";
   cout << "this program." << endl << endl << "NOTE:  Your program MUST be set up to ";
   cout << "with 'in.data' as your INFILE and " << endl << "'out.data' as your OUTFILE";
   cout << " for this to work correctly.  If you are not set" << endl << "up correctly,";
   cout << " exit NOW, and reconfigure your program!" << endl << endl;


   cout << "Press any Enter/Return to begin" << endl;
   pressEnter(input);


   cout << "Generating output files ....";

   //Students like to cheat by sending the submit program to the background and
   //then modifying the outfile to have correct output.  I am trying to get around 
   //this in a number of ways.  One of the ways is to randomly generate the filename:
   fileName = st.MakeFileName();
   sleep(1); //for random nums.
   fileName2 = st.MakeFileName();

   //We will go ahead and open up the outfile and make it ready for writing:
   fileName = "/usr/local/.tmp/" + fileName;
   outFile.open(fileName.c_str());

   //A secondary outfile for copying and other temporary output.
   fileName2 = "/usr/local/.tmp/" + fileName2;
   dirFile.open(fileName2.c_str());

   //Set the filenames so that the signal handler has access to them:
   SetFilenames(fileName, fileName2);

   //File status check
   if(outFile.fail() || dirFile.fail())
   {
      cout << endl << "     **** OUTPUT FILE ERROR **** " << endl;
      cout << "Unable to open or write to the output file." << endl;
      cout << "Contact the Support Center at x4225 on campus" << endl;
      cout << "to report this incident." << endl << endl;
      cout << "    ===============   DIRECTORY LISTING   ===============" << endl;
      system("ls -l");
      cout << "    ===============      END LISTING      ===============";
      cout << endl << endl;
      return 1;
   }
   cout << "Done." << endl;

   cout << "Preparing your directory for submission....";
   st.PreClean();
   cout << "Done." << endl << endl;

   //Users are a strange force of nature.  I am going to do as much as I can for them, 
   //and give them as little power as possible.  Less power = less chance for program problems.

   //We will verify with the user:
   cout << "Detecting file types ....";
   st.SetExtensions();
   cout << "Done." << endl <<"Setting program extensions ....";
   progExt = st.GetSources();
   cout << "Done." << endl << "Setting data extensions ....";
   dataExt = st.GetInputs();
   cout << "Done." << endl << endl;

   if(progExt == "xxx")
   {
      cout << endl << "     **** PROGRAM FILE ERROR **** " << endl;
      cout << "No files found with C++ file extensions.  You" << endl;
      cout << "must have at least one file with a .cxx, .cpp," << endl;
      cout << ".cc, or .c extension, or this program will NOT" << endl;
      cout << "run" << endl << endl;

      st.PostClean(fileName, fileName2);
      return 1;
   }

   cout << "I am detecting that your C++ program files end with " << progExt << " ." << endl << endl;
   cout << "Is this correct?  [ y/n ] :  ";

   getChar(input);
   chkYesNo(input);

   if(input == 'n')
   {
      cout << "Choose one of the following options about your program SOURCE file extensions:" << endl;
      cout << endl << "     My C++ SOURCE files end with..." << endl << "     1)  .cxx   " << endl;
      cout << "     2)  .cpp " << endl << "     3)  .cc " << endl << "     4)  .c " << endl << endl << endl;

      getChar(input);

      //menuTest is the upper bounds of the user menu.
      menuTest = 4;
      selection = 0;

      chkInput(input, selection, menuTest);
      answers[0] = selection;
 
      switch(answers[0])
      {
         case 1:
            st.SetSources(".cxx");
            break;
         case 2:
            st.SetSources(".cpp");
            break;
         case 3:
            st.SetSources(".cc");
            break;
         case 4:
            st.SetSources(".c");
            break;
         default:
            st.SetSources(".cxx");
            break;
      }  
   }

   if(dataExt == "xxx")
   {
      cout << endl << "        **** DATA FILE ERROR **** " << endl;
      cout << "No files found with DATA file extensions.  You" << endl;
      cout << "must have at least one file with a valid data " << endl;
      cout << "file extension, or this program will NOT run." << endl;
      cout << "Please copy your data files for this assignment" << endl;
      cout << "to this directory and re-run this program." << endl;

      st.PostClean(fileName, fileName2);
      return 1;
   }

   cout << endl << "I am detecting that your assignment DATA files end with  " << dataExt << " ." << endl << endl;
   cout << "Is this correct?  [ y/n ] :  ";

   getChar(input);
   chkYesNo(input); 
   
   if(input == 'n')
   {
      cout << "Choose one of the following options about your program DATA file extensions:" << endl;
      cout << endl << "     My C++ DATA files end with..." << endl;
      cout << "     1)  .f##  (FALL Semester Bidgoli)" << endl;
      cout << "     2)  .w##  (WINTER Semester Bidgoli)" << endl;
      cout << "     3)  .s##  (SPRING/SUMMER Semester Bidgoli)" << endl;
      cout << "     4)  .dat#  (LEE Data File)"<< endl << endl;

      getChar(input);
      menuTest = 4;
      selection = 0;
      chkInput(input, selection, menuTest);
      answers[1] = selection;

      switch(answers[1])
      {
         case 1:
            cout << "Setting input to Bidgoli fall. " << endl;
            st.SetInputs(".f");
            break;
         case 2:
            cout << "Setting input to Bidgoli winter. " << endl;
            st.SetInputs(".w");
            break;
         case 3:
            cout << "Setting input to Bidgoli spring/summer. " << endl;
            st.SetInputs(".s");
            break;
         case 4:
            cout << "Setting input to Lee 316. " << endl;
            st.SetInputs(".dat");   
            break;
      }
   }

   cout << endl << "Will you need to set any compiler flags?  If you do not know what this means,";
   cout << " answer no (n) here.  [ y/n ] :  ";

   getChar(input);
   chkYesNo(input);

   if(input == 'y')
   {
      cout << "Enter compiler flags:  ";
      cin >> comFlags;
      pressEnter(input);
      st.SetComFlags(comFlags);
   }

   cout <<  endl << "Will you need to set any linker flags?  ";
   cout << "If you do not know what this means, answer no (n) here.  [ y/n ] :  ";

   getChar(input);
   chkYesNo(input);

   if(input == 'y')
   {
      cout << "Enter linker flags:  ";
      cin >> linkFlags;
      pressEnter(input);
      st.SetLinkFlags(linkFlags);
   }

   cout << endl;
   cout << "You will be given the choice as to whether or not to print later.  But, " << endl;
   cout << "for now, you can choose which printer you prefer:  " << endl << endl;
   cout << "     My PRINTER of choice is:  " << endl << "     1) SE145 " << endl;
   cout << "     2) SE135 " << endl << "     3) SE104A " << endl;
   cout << "     4) SE105A " << endl << "     5) SE105B " << endl << "     6) SE136" << endl;
   cout << "     7) SCCC 122B "  << endl; 
   cout << "Your Printer of Choice:  ";

   getChar(input);
   menuTest = 7;
   selection = 0;
   chkInput(input, selection, menuTest);

   cout << endl << "I have all of the information I need. ";
   cout << " Attempting to compile your program. You should see no errors here.";
   cout << endl << endl;

   time(&currDate);
   outFile << "********************************************************************************";
   outFile << endl << "                BEGIN:  " <<  getenv("USER") << endl;
   outFile << "********************************************************************************";
   outFile << endl << endl << ctime(&currDate) << endl << endl;
 
   st.AddDirListToFile(fileName2); 
   st.CopyInFile(fileName2, "in.lis");
   st.CopyToOutfile(outFile, "in.lis");
   dirFile.close();


   answers[2] = selection;   
   cout << "selection:  " << selection << endl;

   progExt = st.GetSources();
   progExt = "*" + progExt;

   st.CompileSources(progExt);

   //Set up the linked list for filling:
   dflist = new DirType;
   dflist->info = "==##==empty==##==";
   dflist->next = NULL;

   sflist = new DirType;
   sflist->info = "==##==empty==##==";
   sflist->next = NULL;

   //Collect a linked list of all of the files in the cwd:
   
   cout << endl << "Building Data File List ... " << endl;
   dflist = st.MakeDataFileList(dflist);
   dflist = st.SortList(dflist);
   cout << "Done." << endl;

   cout << endl << "Building Source File List ... " << endl;
   sflist = st.MakeSourceFileList(sflist);
   cout << "Done." << endl;

   cout << endl << endl << "Checking to see if we have an executable to run ...." ;
   compileChk = st.GetIsCompiled();

   if(compileChk == 1)
   {
      cout << "Success" << endl << endl;
   }
   else
   {  cout << endl << endl << "     **** COMPILE ERROR **** " << endl; 
      cout << "Your program failed to compile."  << endl << "You must repair your code and";
      cout << endl << "re-run this program." << endl << endl;
      st.PostClean(fileName, fileName2);
      return 1;
   }

   sflocator = sflist;
   sfnextlist = sflocator->next;

   if(sflocator->info == "==##==empty==##==")
   {
      cout << endl << endl << "     **** SOURCE FILE ERROR **** " << endl;
      cout << "No SOURCE or HEADER files found in this" << endl;
      cout << "directory!  Please make sure that your " << endl;
      cout << "source and header files exist and re-run" << endl;
      cout << "this program." << endl << endl;
      st.PostClean(fileName, fileName2);
      return 1;
   }

   outFile << endl << endl;
   outFile << "********************************************************************************";
   outFile << endl << "                COMPILE" << endl;
   outFile << "********************************************************************************";
   outFile << endl << endl;
   outFile << "cxx " << comFlags << " " << linkFlags << " " << progExt << endl << endl;
   outFile << "********************************************************************************";
   outFile << endl << "                SOURCES" << endl;
   outFile << "********************************************************************************";
   outFile << endl << endl;
  
   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << "                FILE:  " << sflocator->info << endl;
   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << endl;
   st.CopyToOutfile(outFile, sflocator->info);

   while(sflocator->next != NULL)
   {
      sflocator = sfnextlist;
      sfnextlist = sflocator->next;
      outFile << "--------------------------------------------------------------------------------";
      outFile << endl << "                FILE:  " << sflocator->info << endl;
      outFile << "--------------------------------------------------------------------------------";
      outFile << endl << endl;
      st.CopyToOutfile(outFile, sflocator->info);
   }
  
   cout << "Time to process your data files." << endl; 

   dflocator = dflist;
   dfnextlist = dflocator->next;

   if(dflocator->info == "==##==empty==##==")
   {
      cout << endl << endl << "     **** DATA FILE ERROR **** " << endl;
      cout << "No DATA files found in this directory! " << endl <<"Please copy data files into";
      cout << " this directory and" << endl << "re-run this program." << endl << endl;
      st.PostClean(fileName, fileName2);
      return 1;
   }
  
   outFile << "********************************************************************************";
   outFile << endl << "                DATA FILES" << endl;
   outFile << "********************************************************************************";
   outFile << endl << endl;

   cout << "Processing:  " << dflocator->info << endl << endl;
   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << "                FILE:  " << dflocator->info << endl;
   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << endl;
   st.CopyInFile(dflocator->info, "in.data");
   st.CopyToOutfile(outFile, "in.data");

   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << "                Execution" << endl;
   outFile << "--------------------------------------------------------------------------------";
   outFile << endl << endl;
   st.RunAOut();
   outFile << endl;
   st.CopyToOutfile(outFile, "out.data");

   while(dflocator->next != NULL) 
   {
      dflocator = dfnextlist;
      dfnextlist = dflocator->next;
      cout << "Processing:  " << dflocator->info << endl << endl;
      outFile << "--------------------------------------------------------------------------------";
      outFile << endl;
      outFile << "                FILE:  " << dflocator->info << endl;
      outFile << "--------------------------------------------------------------------------------";
      outFile << endl << endl;
      st.CopyInFile(dflocator->info, "in.data");
      st.CopyToOutfile(outFile, "in.data");

      outFile << "--------------------------------------------------------------------------------";
      outFile << endl << "                Execution" << endl;
      outFile << "--------------------------------------------------------------------------------";
      outFile << endl << endl;
      st.RunAOut();
      st.CopyToOutfile(outFile, "out.data");
   }

   //Students cheat.  One of the ways they do it is to pause this program
   //and edit the outFile before printing.  We are going to load the 
   //outFile into a string to compare before and after printing to see
   //if the student tried to modify it.
   befFile = st.CopyToString(fileName);
  
   cout << endl << endl << "All processing is complete.  ";
   cout << "Would you like to preview your assignment? [ y/n ] :  ";
   getChar(input);
   chkYesNo(input);

   if(input == 'y')
   {
      st.PreviewAssignment(fileName);
   } 

   cout << endl << endl << "Would you like to print your assignment? [ y/n ] :  ";
   getChar(input);
   chkYesNo(input);

   if(input == 'y')
   {
      aftFile = st.CopyToString(fileName);

      //Do the after checks on the outFile:
      if(befFile != aftFile)
      {
         string rmCmd, user, curr;

         user = getenv("USER");
         curr = ctime(&currDate);

         cout << endl << "   ****  OUTFILE TAMPERING DETECTED!  ****" << endl;
         cout << "Outfile change detected!  It would appear that " << endl;
         cout << "you have tampered with the program output file." << endl;
         cout << "Tampering with the output file is considered as" << endl;
         cout << "cheating.  I will spare you the failing grade " << endl;
         cout << "and just exit now." << endl;

         rmCmd = "/bin/echo '" + curr + "  " + user + "' >> /var/log/sublog";
         system(rmCmd.c_str()); 
         rmCmd = "/bin/echo 'Files: " + fileName + ", " + fileName2 + "' >> /var/log/sublog";
         system(rmCmd.c_str());

         return 1;
      }
      else
      {
         cout << "Outfile check successful!  " << endl;
         cout << "Creating numbered file ... ";
         st.MakeNumbered(fileName, fileName2);
         cout << "Done." << endl;
         cout << "Sending to your chosen printer ...";
         st.PrintOutput(answers[2], fileName2);
         cout << "Printing Done." << endl;
      }
   }

   st.PostClean(fileName, fileName2);

   return 0;
}

