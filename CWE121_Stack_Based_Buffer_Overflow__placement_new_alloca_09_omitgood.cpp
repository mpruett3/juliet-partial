/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_09.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-09.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data to a small buffer
 * GoodSource: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    GoodSink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    BadSink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_09
{

#ifndef OMITBAD

void bad()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA(sizeof(OneIntClass));
    char * dataGoodBuffer = (char *)ALLOCA(sizeof(TwoIntsClass));
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Initialize data to a buffer smaller than the sizeof(TwoIntsClass) */
        data = dataBadBuffer;
    }
    if(GLOBAL_CONST_TRUE)
    {
        {
            /* The Visual C++ compiler generates a warning if you initialize the class with ().
             * This will cause the compile to default-initialize the object.
             * See http://msdn.microsoft.com/en-us/library/wewb47ee%28v=VS.100%29.aspx
             */
            /* POTENTIAL FLAW: data may not be large enough to hold a TwoIntsClass */
            TwoIntsClass * classTwo = new(data) TwoIntsClass;
            /* Initialize and make use of the class */
            classTwo->intOne = 5;
            classTwo->intTwo = 10; /* POTENTIAL FLAW: If sizeof(data) < sizeof(TwoIntsClass) then this line will be a buffer overflow */
            printIntLine(classTwo->intOne);
            /* skip printing classTwo->intTwo since that could be a buffer overread */
        }
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_09; /* so that we can use good and bad easily */

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

