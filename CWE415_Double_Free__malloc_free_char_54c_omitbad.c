/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_54c.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_char_54d_goodG2BSink(char * data);

void CWE415_Double_Free__malloc_free_char_54c_goodG2BSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_54d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_char_54d_goodB2GSink(char * data);

void CWE415_Double_Free__malloc_free_char_54c_goodB2GSink(char * data)
{
    CWE415_Double_Free__malloc_free_char_54d_goodB2GSink(data);
}

#endif /* OMITGOOD */
