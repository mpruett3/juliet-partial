/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_53c.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_int_53d_badSink(int * data);

void CWE415_Double_Free__malloc_free_int_53c_badSink(int * data)
{
    CWE415_Double_Free__malloc_free_int_53d_badSink(data);
}

#endif /* OMITBAD */

