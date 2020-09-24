/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_63a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using strcpy()
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_63b_badSink(char * * dataPtr);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_63_bad()
{
    char * data;
    data = NULL;
    /* FLAW: Did not leave space for a null terminator */
    data = (char *)malloc(10*sizeof(char));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_63b_badSink(&data);
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_63_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}
