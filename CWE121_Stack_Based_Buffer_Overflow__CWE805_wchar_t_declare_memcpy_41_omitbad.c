/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_41.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-41.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_41_goodG2BSink(wchar_t * data)
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of source */
        memcpy(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
    }
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    data[0] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_41_goodG2BSink(data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_41_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

