/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_17.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_17_bad()
{
    int i;
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    for(i = 0; i < 1; i++)
    {
        /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
         * buffer in various memory copying functions using a "large" source buffer. */
        data = dataBadBuffer;
    }
    {
        int source[100] = {0}; /* fill with 0's */
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

