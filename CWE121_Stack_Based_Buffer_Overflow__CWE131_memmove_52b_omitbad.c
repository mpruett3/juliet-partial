/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_52b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* good function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_52c_goodG2BSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_52b_goodG2BSink(int * data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_52c_goodG2BSink(data);
}

#endif /* OMITGOOD */