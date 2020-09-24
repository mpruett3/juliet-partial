/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_13.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-13.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_class_13
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = new TwoIntsClass;
        /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
        delete data;
    }
    if(GLOBAL_CONST_FIVE==5)
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


using namespace CWE415_Double_Free__new_delete_class_13; /* so that we can use good and bad easily */

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

