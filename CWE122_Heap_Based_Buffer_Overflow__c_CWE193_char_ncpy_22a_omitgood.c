/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: ncpy
 *    BadSink : Copy string to data using strncpy()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_badGlobal = 0;

char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_badSource(char * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_bad()
{
    char * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_badGlobal = 1; /* true */
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_badSource(data);
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

