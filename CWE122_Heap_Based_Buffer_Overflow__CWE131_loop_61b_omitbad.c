/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int * CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_61b_goodG2BSource(int * data)
{
    /* FIX: Allocate memory using sizeof(int) */
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITGOOD */
