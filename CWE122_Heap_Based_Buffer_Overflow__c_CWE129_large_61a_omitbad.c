/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61b_goodG2BSource(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61b_goodG2BSource(data);
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
int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61b_goodB2GSource(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61b_goodB2GSource(data);
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

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

