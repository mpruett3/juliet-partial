/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_loop_63b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_loop_63
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}

#endif /* OMITGOOD */

} /* close namespace */