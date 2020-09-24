/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_63a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-63a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data to a small buffer
 * GoodSource: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    GoodSink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    BadSink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_63
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(char * * dataPtr);

void bad()
{
    char * data;
    char * dataBadBuffer = (char *)malloc(sizeof(OneIntClass));
    if (dataBadBuffer == NULL) {exit(-1);}
    char * dataGoodBuffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataGoodBuffer == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataBadBuffer;
    badSink(&data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_63; /* so that we can use good and bad easily */

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

