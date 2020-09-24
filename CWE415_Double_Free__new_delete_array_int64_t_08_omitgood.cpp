/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int64_t_08.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

namespace CWE415_Double_Free__new_delete_array_int64_t_08
{

#ifndef OMITBAD

void bad()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    if(staticReturnsTrue())
    {
        data = new int64_t[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    if(staticReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE415_Double_Free__new_delete_array_int64_t_08; /* so that we can use good and bad easily */

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

