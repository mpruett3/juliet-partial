/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_wchar_t_11.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-11.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_wchar_t_11
{


#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second globalReturnsTrue() to globalReturnsFalse() */
static void goodB2G1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrue())
    {
        data = new wchar_t[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrue())
    {
        data = new wchar_t[100];
        /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
        delete [] data;
    }
    if(globalReturnsTrue())
    {
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first globalReturnsTrue() to globalReturnsFalse() */
static void goodG2B1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        data = new wchar_t[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrue())
    {
        data = new wchar_t[100];
        /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE415_Double_Free__new_delete_array_wchar_t_11; /* so that we can use good and bad easily */

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

