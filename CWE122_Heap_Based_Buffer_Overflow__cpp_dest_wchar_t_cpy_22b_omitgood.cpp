/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_22b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_22
{

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int badGlobal;

wchar_t * badSource(wchar_t * data)
{
    if(badGlobal)
    {
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new wchar_t[50];
        data[0] = L'\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITBAD */


} /* close namespace */
