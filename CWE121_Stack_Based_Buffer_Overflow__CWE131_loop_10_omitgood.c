/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_10.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_10_bad()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        /* FLAW: Allocate memory without using sizeof(int) */
        data = (int *)ALLOCA(10);
    }
    {
        int source[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
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
    CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

