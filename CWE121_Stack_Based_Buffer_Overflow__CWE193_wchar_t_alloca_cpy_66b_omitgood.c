/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_cpy_66b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE193.label.xml
Template File: sources-sink-66b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Point data to a buffer that does not have space for a NULL terminator
 * GoodSource: Point data to a buffer that includes space for a NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_cpy_66b_badSink(wchar_t * dataArray[])
{
    /* copy data out of dataArray */
    wchar_t * data = dataArray[2];
    {
        wchar_t source[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcscpy(data, source);
        printWLine(data);
    }
}

#endif /* OMITBAD */

