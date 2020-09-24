/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_31.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t source[10+1] = SRC_STRING;
            size_t i, sourceLen;
            sourceLen = wcslen(source);
            /* Copy length + 1 to include NUL terminator from source */
            /* POTENTIAL FLAW: data may not have enough space to hold source */
            for (i = 0; i < sourceLen + 1; i++)
            {
                data[i] = source[i];
            }
            printWLine(data);
            free(data);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_31_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

