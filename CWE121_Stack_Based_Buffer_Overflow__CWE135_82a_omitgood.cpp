/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_82a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE135_82.h"

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_82
{

#ifndef OMITBAD

void bad()
{
    void * data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = (void *)WIDE_STRING;
    CWE121_Stack_Based_Buffer_Overflow__CWE135_82_base* baseObject = new CWE121_Stack_Based_Buffer_Overflow__CWE135_82_bad;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_82; /* so that we can use good and bad easily */

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

