/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_loop_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy int array to data using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_loop_68_badData;
extern int * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_loop_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_loop_68b_goodG2BSink()
{
    int * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_loop_68_goodG2BData;
    {
        int source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITGOOD */
