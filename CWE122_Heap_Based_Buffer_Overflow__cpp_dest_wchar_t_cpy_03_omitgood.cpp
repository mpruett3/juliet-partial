/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_03.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-03.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_03
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    data = NULL;
    if(5==5)
    {
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new wchar_t[50];
        data[0] = L'\0'; /* null terminate */
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        wcscpy(data, source);
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_03; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

