/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_53b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-53b.tmpl.c
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


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_int64_t_53c_goodG2BSink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_53b_goodG2BSink(int64_t * data)
{
    CWE415_Double_Free__malloc_free_int64_t_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_int64_t_53c_goodB2GSink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_53b_goodB2GSink(int64_t * data)
{
    CWE415_Double_Free__malloc_free_int64_t_53c_goodB2GSink(data);
}

#endif /* OMITGOOD */
