/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_12.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: swprintf
 *    BadSink : Copy data to string using swprintf
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif


#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
 * both branches use the GoodSource */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        wmemset(data, L'A', 50-1); /* fill with L'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    else
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        wmemset(data, L'A', 50-1); /* fill with L'A's */
        data[50-1] = L'\0'; /* null terminate */
    }
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_12_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
