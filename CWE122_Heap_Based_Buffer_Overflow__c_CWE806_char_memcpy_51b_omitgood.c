/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_51b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-51b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_51b_badSink(char * data)
{
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        memcpy(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

