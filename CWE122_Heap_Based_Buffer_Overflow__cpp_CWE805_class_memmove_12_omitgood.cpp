/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memmove_12.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy TwoIntsClass array to data using memmove
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memmove_12
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new TwoIntsClass[50];
    }
    else
    {
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new TwoIntsClass[100];
    }
    {
        TwoIntsClass source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(TwoIntsClass));
        printIntLine(data[0].intOne);
        delete [] data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memmove_12; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

