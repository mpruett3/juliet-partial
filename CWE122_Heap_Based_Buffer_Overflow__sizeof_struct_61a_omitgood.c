/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_61b_badSource(twoIntsStruct * data);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_61_bad()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_61b_badSource(data);
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

