/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_snprintf_16.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: swprintf
 *    BadSink : Copy string to data using swprintf
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_snprintf_16
{


#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    while(1)
    {
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new wchar_t[100];
        data[0] = L'\0'; /* null terminate */
        break;
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        SNPRINTF(data, 100, L"%s", source);
        printWLine(data);
        delete [] data;
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_snprintf_16; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

