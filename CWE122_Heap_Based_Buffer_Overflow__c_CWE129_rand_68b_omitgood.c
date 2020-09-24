/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68_badData;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68_goodG2BData;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68_goodB2GData;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68b_badSink()
{
    int data = CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_68_badData;
    {
        int i;
        int * buffer = (int *)malloc(10 * sizeof(int));
        if (buffer == NULL) {exit(-1);}
        /* initialize buffer */
        for (i = 0; i < 10; i++)
        {
            buffer[i] = 0;
        }
        /* POTENTIAL FLAW: Attempt to write to an index of the array that is above the upper bound
         * This code does check to see if the array index is negative */
        if (data >= 0)
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is negative.");
        }
        free(buffer);
    }
}

#endif /* OMITBAD */
