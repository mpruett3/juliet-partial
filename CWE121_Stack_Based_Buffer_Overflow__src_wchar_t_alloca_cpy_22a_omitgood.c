/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* The global variable below is used to drive control flow in the source function */
int CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_badGlobal = 0;

wchar_t * CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_badSource(wchar_t * data);

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_badGlobal = 1; /* true */
    data = CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_badSource(data);
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        wcscpy(dest, data);
        printWLine(data);
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cpy_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

