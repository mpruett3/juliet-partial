/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_long_82a.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_long_82.h"

namespace CWE415_Double_Free__new_delete_long_82
{

#ifndef OMITBAD

void bad()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    CWE415_Double_Free__new_delete_long_82_base* baseObject = new CWE415_Double_Free__new_delete_long_82_bad;
    baseObject->action(data);
    delete baseObject;
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE415_Double_Free__new_delete_long_82; /* so that we can use good and bad easily */

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

