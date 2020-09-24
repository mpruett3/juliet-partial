/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_67a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67a.tmpl.c
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

typedef struct _CWE415_Double_Free__malloc_free_long_67_structType
{
    long * structFirst;
} CWE415_Double_Free__malloc_free_long_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_long_67b_badSink(CWE415_Double_Free__malloc_free_long_67_structType myStruct);

void CWE415_Double_Free__malloc_free_long_67_bad()
{
    long * data;
    CWE415_Double_Free__malloc_free_long_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_long_67b_badSink(myStruct);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_long_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

