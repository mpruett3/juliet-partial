/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_62b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_62
{


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(wchar_t * &data)
{
    /* FIX: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
}

#endif /* OMITGOOD */

} /* close namespace */
