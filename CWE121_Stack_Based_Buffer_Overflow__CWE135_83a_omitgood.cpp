/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_83a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE135_83.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_83
{

#ifndef OMITBAD

void bad()
{
    void * data;
    data = NULL;
    CWE121_Stack_Based_Buffer_Overflow__CWE135_83_bad badObject(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_83; /* so that we can use good and bad easily */

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

