/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-16.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the while statements */
static void goodG2B()
{
    double * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        /* FIX: Using sizeof the data type in malloc() */
        data = (double *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 1.7E300;
        break;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_good()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_double_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

