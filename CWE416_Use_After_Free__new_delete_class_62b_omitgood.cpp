/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_class_62b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_class_62
{

#ifndef OMITBAD

void badSource(TwoIntsClass * &data)
{
    data = new TwoIntsClass;
    data->intOne = 1;
    data->intTwo = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */
