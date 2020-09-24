/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_53d.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-53d.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_53d_badSink(char * data)
{
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strncpy(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

#endif /* OMITBAD */

