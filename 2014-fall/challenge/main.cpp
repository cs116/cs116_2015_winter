/*
    Program Name:   CS116 challenge
    Author:         Joseph Nicklyn
    Date:           OCT 20, 2014

    details:

        Write a program which searches an input file lin-by-line, then
        replaces text matching string1 with text in string2, and writes the
        new text to an output file.  You will need to declare and initalize
        four variables: infile, outifle, string1, and string2

        in string1 allow upto 3 wildcard characters, indicated by asterisks
        (*).  If string2 contains one or more question marks(?), replace the
        first question mark with the first character wildcarded by an
        asterisk; the second question mark with the second character
        wildcarded by an asterisk; and the third question mark with the third
        character wildcarded by an asterisk.

        main()

        1:  Declare variables
        2:  Check if files were acatually opened
        3:  while getline()
        4:      call replaceText()
        ...
        4a:         cast string to char*
        4b:         while match not found
        4c:             search for match
        4d:         if found
        4e:             rewrite output
        4f:     return;
        ...
        5:      write to outfile
        6:  return



*/

#include <iostream> /* cout, screen writes  */
#include <string>   /* string object        */
#include <fstream>  /* file in/out          */

using namespace std;

/* prototype(s) */
int replaceText(string &, string &, string &, string &);

int main()
{
    /** declerations **/

    ifstream inFile("in.data");                         /* source file                  */
    ofstream outFile("out.data");                       /* destination file             */

    string oldMask   = "thistext**thattext";            /* mask1                        */
    string newMask   = "theother??text??to??write";     /* mask 2                       */
    string recordIn  = "";                              /* line from inFile             */
    string recordOut = "";                              /* modified record              */

    /* search line by line, modify each line, and write to outFile                      */
    if (inFile && outFile) {
        while(getline(inFile, recordIn)) {
            if (replaceText(recordOut, recordIn, oldMask, newMask)) {
                cout << recordIn << "\n\t->" << recordOut << endl << endl;
                outFile << recordOut << endl;           /* write to the outFile         */
            }
        }
    }

    if (inFile)
        inFile.close();
    if (outFile)
        outFile.close();

    return 0;
}

/* replaces [input] containing [mask1] with [mask2]                                     */
int replaceText(string &dest, string &input, string &mask1, string &mask2) {

        /*
            this function uses pointer math, we will need to
            work with the string objects data as a character pointer
        */

        const char *sa = input.c_str(); /* pointer to input                             */
        const char *sb = mask1.c_str(); /* pointer to mask1                             */

        const char *s1;                 /* iterator for sa                              */
        const char *s2;                 /* iterator for sb                              */

        char wildStr[5] = "";           /* a temporary holder for wild cards
                                            - this could have been accomplished
                                              using offsets, but to keep it
                                              simple...
                                        */
        int found  = -1;                /* found a '*' wildcard                         */
        int wildAt = -1;                /* offset of [mask1] within [input]             */
        int p = 0;                      /* wildStr, position                            */


        /* begin searching [input], until found something                               */
        while (*sa && found == -1) {
            /*
                iterate [input] pointer to the next character,
                reset [mask1] pointer, and loop [if] until mis-match is found
            */
            for(p=0,wildAt=-1, s1=sa++,s2=sb;*s1 && *s2;s1++,s2++) {
                if (*s2 != '*' && *(s2) != *(s1)) /* not the same, and not wild         */
                        break;
                else if (*s2 == '*') {
                    if (wildAt == -1)
                        wildAt = s2-sb;
                    wildStr[p++] = *s1; /* store [mask1]'s contents wildcarded          */
                    wildStr[p]   = 0;   /* ensure null terminated                       */
                }
            }

            if (*s2 == 0)               /* [mask2] is [NULL] meaning, matched           */
                found = sa-input.c_str();
        }


        if(found !=-1) {                /* found was flaged                             */
            /* [dest] is set to [input] to the point where the wildcard begins          */
            dest = input.substr(0, found-1);
            /*
                iterate through [mask2] setting contents to [dest], but
                replacing with wildStr, at appropriate locations
            */
            for(p=0,s1 = mask2.c_str(),p=0;*s1;s1++) {
                if (*s1 == '?') {       /* set [dest] with wildcard's contents          */
                    dest.append(1, wildStr[p++]);
                } else {                /* set [dest] to [input], without modification  */
                    p = 0;
                    dest.append(1, (*s1));
                }
            }
        }
        return (found!=-1);

}

