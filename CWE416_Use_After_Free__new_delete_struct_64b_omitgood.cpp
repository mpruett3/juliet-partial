/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_struct_64b.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after delete
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_struct_64
{

#ifndef OMITBAD

void badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * * dataPtr = (twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct * data = (*dataPtr);
    /* POTENTIAL FLAW: Use of data that may have been deleted */
    printStructLine(data);
    /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
}

#endif /* OMITBAD */


} /* close namespace */
