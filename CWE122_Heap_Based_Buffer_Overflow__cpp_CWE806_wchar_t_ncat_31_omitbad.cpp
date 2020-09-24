/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncat_31.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806.label.xml
Template File: sources-sink-31.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncat
 *    BadSink : Copy data to string using wcsncat
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncat_31
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = new wchar_t[100];
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t dest[50] = L"";
            /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-wcslen(dest)*/
            wcsncat(dest, data, wcslen(data));
            dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
            printWLine(data);
            delete [] data;
        }
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncat_31; /* so that we can use good and bad easily */

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
