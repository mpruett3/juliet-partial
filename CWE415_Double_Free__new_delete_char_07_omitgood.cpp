/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_char_07.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-07.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

namespace CWE415_Double_Free__new_delete_char_07
{

#ifndef OMITBAD

void bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    if(staticFive==5)
    {
        data = new char;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    if(staticFive==5)
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE415_Double_Free__new_delete_char_07; /* so that we can use good and bad easily */

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

