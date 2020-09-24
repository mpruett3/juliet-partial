/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_16.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_16_bad()
{
    int * data;
    data = NULL;
    while(1)
    {
        /* FLAW: Allocate memory without using sizeof(int) */
        data = (int *)malloc(10);
        if (data == NULL) {exit(-1);}
        break;
    }
    {
        int source[10] = {0};
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        memmove(data, source, 10*sizeof(int));
        printIntLine(data[0]);
        free(data);
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
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memmove_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}
