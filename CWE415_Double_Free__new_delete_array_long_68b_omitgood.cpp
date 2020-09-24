/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_68b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_long_68
{

extern long * badData;
extern long * goodG2BData;
extern long * goodB2GData;

#ifndef OMITBAD

void badSink()
{
    long * data = badData;
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}

#endif /* OMITBAD */


} /* close namespace */
