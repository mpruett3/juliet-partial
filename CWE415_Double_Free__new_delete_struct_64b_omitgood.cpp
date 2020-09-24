/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_struct_64b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_struct_64
{

#ifndef OMITBAD

void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * * dataPtr = (twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

#endif /* OMITBAD */


} /* close namespace */
