/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_31.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    {
        int * dataCopy = data;
        int * data = dataCopy;
        {
            int source[100] = {0}; /* fill with 0's */
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            memmove(data, source, 100*sizeof(int));
            printIntLine(data[0]);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_31_good()
{
    goodG2B();
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
