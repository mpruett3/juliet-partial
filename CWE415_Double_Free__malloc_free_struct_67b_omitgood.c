/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_67b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_struct_67_structType
{
    twoIntsStruct * structFirst;
} CWE415_Double_Free__malloc_free_struct_67_structType;

#ifndef OMITBAD

void CWE415_Double_Free__malloc_free_struct_67b_badSink(CWE415_Double_Free__malloc_free_struct_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITBAD */
