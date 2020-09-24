/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_16.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 16 Control flow: while(1)
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_16
{


#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    while(1)
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
        break;
    }
    while(1)
    {
        {
            int i;
            int * buffer = new int[10];
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
            delete[] buffer;
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    while(1)
    {
        /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
         * access an index of the array in the sink that is out-of-bounds */
        data = 7;
        break;
    }
    while(1)
    {
        {
            int i;
            int * buffer = new int[10];
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
            delete[] buffer;
        }
        break;
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_16; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

