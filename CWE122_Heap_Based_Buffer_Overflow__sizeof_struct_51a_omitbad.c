/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_51a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* good function declarations */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_51b_goodG2BSink(twoIntsStruct * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoIntsStruct * data;
    /* Initialize data */
    data = NULL;
    /* FIX: Using sizeof the data type in malloc() */
    data = (twoIntsStruct *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_51b_goodG2BSink(data);
}

void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_51_good()
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
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

