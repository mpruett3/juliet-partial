/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_42.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static double * badSource(double * data)
{
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    return data;
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_42_bad()
{
    double * data;
    /* Initialize data */
    data = NULL;
    data = badSource(data);
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

