/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_badData;
static twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    twoIntsStruct * data = CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_badData;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printStructLine(data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_bad()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (twoIntsStruct *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_badData = data;
    badSink();
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

