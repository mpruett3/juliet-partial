/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy int array to data using memmove
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84
{

#ifndef OMITBAD

void bad()
{
    int * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84_bad * badObject = new CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84_bad(data);
    delete badObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int_memmove_84; /* so that we can use good and bad easily */

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
