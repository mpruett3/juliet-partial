/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_65a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_65b_badSink(double * data);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_65_bad()
{
    double * data;
    /* define a function pointer */
    void (*funcPtr) (double *) = CWE122_Heap_Based_Buffer_Overflow__sizeof_double_65b_badSink;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    /* use the function pointer */
    funcPtr(data);
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

