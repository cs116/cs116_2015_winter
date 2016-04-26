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
// This is the class header file.
//
// Finalized:  December 08, 2009
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <ctype.h>
#include <stdexcept>
#include <signal.h>

using namespace std;

struct DirType
{
   string info;
   DirType* next;
};

class SubType
{
   public:
      //Constructors
      SubType();
      SubType(string sf, string cf, string lf, string ipf, int ic);

      //Get/Set Methods
      string GetSources();
      string GetInputs();
      int GetIsCompiled();
      void SetSources(string sf);
      void SetInputs(string ipf);
      void SetComFlags(string cf);
      void SetLinkFlags(string lf);

      string MakeFileName();
      void EmptyDirList(DirType*& list);
      void SetExtensions();
      DirType* MakeDataFileList(DirType* list);
      DirType* MakeSourceFileList(DirType* list);
      void PreClean();
      void PostClean(string fn, string fn2);
      void AddDirListToFile(string fn);
      void CompileSources(string sf);
      void RunAOut();
      void CopyInFile(string fn, string fn2);
      void CopyToOutfile(ofstream& outFile, string fn);
      string CopyToString(string fn);
      void MakeNumbered(string fn, string fn2);
      void PreviewAssignment(string fn);
      void PrintOutput(int sel, string fn);

   private:
      string sourceFiles;
      string comFlags;
      string linkFlags;
      string inputFiles;
      int isCompiled;
};

