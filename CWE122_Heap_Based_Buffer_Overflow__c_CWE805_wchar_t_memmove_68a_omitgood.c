/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68_badData;
wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68b_badSink();

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68_bad()
{
    wchar_t * data;
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0'; /* null terminate */
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68_badData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68b_badSink();
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

