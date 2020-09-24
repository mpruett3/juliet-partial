/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    double * unionFirst;
    double * unionSecond;
} CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_unionType;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_bad()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myUnion.unionFirst = data;
    {
        double * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
        printDoubleLine(*data);
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

