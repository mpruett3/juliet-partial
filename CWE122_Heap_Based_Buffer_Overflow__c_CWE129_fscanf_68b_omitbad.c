/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68_badData;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68_goodG2BData;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68_goodB2GData;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68b_goodG2BSink()
{
    int data = CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68_goodG2BData;
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

/* goodB2G uses the BadSource with the GoodSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68b_goodB2GSink()
{
    int data = CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fscanf_68_goodB2GData;
    {
        int i;
        int * buffer = (int *)malloc(10 * sizeof(int));
        if (buffer == NULL) {exit(-1);}
        /* initialize buffer */
        for (i = 0; i < 10; i++)
        {
            buffer[i] = 0;
        }
        /* FIX: Properly validate the array index and prevent a buffer overflow */
        if (data >= 0 && data < (10))
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
            printLine("ERROR: Array index is out-of-bounds");
        }
        free(buffer);
    }
}

#endif /* OMITGOOD */
