/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data to a small buffer
 * GoodSource: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    GoodSink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    BadSink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81.h"

namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81
{

#ifndef OMITBAD

void bad()
{
    char * data;
    char dataBadBuffer[sizeof(OneIntClass)];
    char dataGoodBuffer[sizeof(TwoIntsClass)];
    /* POTENTIAL FLAW: Initialize data to a buffer smaller than the sizeof(TwoIntsClass) */
    data = dataBadBuffer;
    const CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81_base& o = CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81_bad();
    o.action(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_declare_81; /* so that we can use good and bad easily */

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

