/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_72b.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__malloc_free_wchar_t_72
{

#ifndef OMITBAD

void badSink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITBAD */


} /* close namespace */
