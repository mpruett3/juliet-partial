/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memcpy_65a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-65a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy int64_t array to data using memcpy
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memcpy_65
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(int64_t * data);

void bad()
{
    int64_t * data;
    /* define a function pointer */
    void (*funcPtr) (int64_t *) = badSink;
    data = NULL;
    /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new int64_t[50];
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memcpy_65; /* so that we can use good and bad easily */

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

