/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_33.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_33
{

#ifndef OMITBAD

void bad()
{
    int * data;
    int * &dataRef = data;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int) */
    data = (int *)ALLOCA(10);
    {
        int * data = dataRef;
        {
            int source[10] = {0};
            /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
            memmove(data, source, 10*sizeof(int));
            printIntLine(data[0]);
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

using namespace CWE121_Stack_Based_Buffer_Overflow__CWE131_memmove_33; /* so that we can use good and bad easily */

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

