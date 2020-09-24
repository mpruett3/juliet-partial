/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using strcpy()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61b_goodG2BSource(char * data);

static void goodG2B()
{
    char * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61b_goodG2BSource(data);
    {
        char source[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strcpy(data, source);
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

