/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_char_63b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_char_63
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(char * * dataPtr)
{
    char * data = *dataPtr;
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */

} /* close namespace */
