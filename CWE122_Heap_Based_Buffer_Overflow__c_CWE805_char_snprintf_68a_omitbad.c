/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68_badData;
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    data = NULL;
    /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; /* null terminate */
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68_goodG2BData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68b_goodG2BSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

