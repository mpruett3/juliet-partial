/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType
{
    double * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_bad()
{
    double * data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
    /* FLAW: Using sizeof the pointer and not the data type in malloc() */
    data = (double *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    *data = 1.7E300;
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67b_badSink(myStruct);
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}
