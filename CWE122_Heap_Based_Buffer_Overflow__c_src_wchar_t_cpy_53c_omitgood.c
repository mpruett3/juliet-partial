/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_53d_badSink(wchar_t * data);

void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_53c_badSink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_53d_badSink(data);
}

#endif /* OMITBAD */

