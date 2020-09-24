/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: memmove
 *    BadSink : Copy string to data using memmove()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_68_badData;
extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_68b_badSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_68_badData;
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */
