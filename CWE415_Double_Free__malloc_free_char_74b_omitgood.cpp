/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_74b.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__malloc_free_char_74
{

#ifndef OMITBAD

void badSink(map<int, char *> dataMap)
{
    /* copy data out of dataMap */
    char * data = dataMap[2];
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITBAD */


} /* close namespace */
