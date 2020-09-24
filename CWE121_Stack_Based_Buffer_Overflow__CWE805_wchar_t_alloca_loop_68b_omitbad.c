/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_loop_68b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_loop_68_badData;
extern wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_loop_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_loop_68b_goodG2BSink()
{
    wchar_t * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_loop_68_goodG2BData;
    {
        size_t i;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of source */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

#endif /* OMITGOOD */
