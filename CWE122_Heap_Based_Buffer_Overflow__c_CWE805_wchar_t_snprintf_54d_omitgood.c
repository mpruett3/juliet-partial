/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_54d.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF snprintf
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_54e_badSink(wchar_t * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_54d_badSink(wchar_t * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_54e_badSink(data);
}

#endif /* OMITBAD */

