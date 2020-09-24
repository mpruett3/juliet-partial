/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_65a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_65b_badSink(wchar_t * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_65b_badSink;
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = dataBadBuffer;
    data[0] = L'\0'; /* null terminate */
    /* use the function pointer */
    funcPtr(data);
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

