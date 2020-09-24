/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_memcpy_15.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memcpy
 *    BadSink : Copy array to data using memcpy()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    int * data;
    data = NULL;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
        /* FIX: Allocate memory using sizeof(int) */
        data = (int *)ALLOCA(10*sizeof(int));
        break;
    }
    {
        int source[10] = {0};
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    int * data;
    data = NULL;
    switch(6)
    {
    case 6:
        /* FIX: Allocate memory using sizeof(int) */
        data = (int *)ALLOCA(10*sizeof(int));
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
    {
        int source[10] = {0};
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE131_memcpy_15_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE131_memcpy_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

