/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_14.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second globalFive==5 to globalFive!=5 */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Use an invalid index */
        data = 10;
    }
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Use an invalid index */
        data = 10;
    }
    if(globalFive==5)
    {
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
}

/* goodG2B1() - use goodsource and badsink by changing the first globalFive==5 to globalFive!=5 */
static void goodG2B1()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
        * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(globalFive==5)
    {
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
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int data;
    /* Initialize data */
    data = -1;
    if(globalFive==5)
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
        * access an index of the array in the sink that is out-of-bounds */
        data = 7;
    }
    if(globalFive==5)
    {
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
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_14_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
