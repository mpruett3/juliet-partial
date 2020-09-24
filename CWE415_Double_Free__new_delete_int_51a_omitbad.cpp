/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int_51a.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-51a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int_51
{


#ifndef OMITGOOD

/* good function declarations */
void goodG2BSink(int * data);
void goodB2GSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = new int;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    /* Initialize data */
    data = NULL;
    data = new int;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    goodB2GSink(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE415_Double_Free__new_delete_int_51; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

