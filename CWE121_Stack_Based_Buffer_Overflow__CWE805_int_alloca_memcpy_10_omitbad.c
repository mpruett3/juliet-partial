/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memcpy_10.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memcpy
 *    BadSink : Copy int array to data using memcpy
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the globalTrue to globalFalse */
static void goodG2B1()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
        data = dataGoodBuffer;
    }
    {
        int source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    if(globalTrue)
    {
        /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
        data = dataGoodBuffer;
    }
    {
        int source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memcpy_10_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memcpy_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

