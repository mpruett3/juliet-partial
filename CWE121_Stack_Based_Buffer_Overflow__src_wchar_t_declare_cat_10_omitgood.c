/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_10.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cat
 *    BadSink : Copy data to string using wcscat
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_10_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    if(globalTrue)
    {
        /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
        wmemset(data, L'A', 100-1); /* fill with L'A's */
        data[100-1] = L'\0'; /* null terminate */
    }
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-wcslen(dest)*/
        wcscat(dest, data);
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
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

