/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using wcsncpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83_bad::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83_bad::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE806_wchar_t_ncpy_83_bad()
{
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        wcsncpy(dest, data, wcslen(data));
        dest[50-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}
}
#endif /* OMITBAD */
