/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_65a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_65b_goodG2BSink;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    data[0] = L'\0'; /* null terminate */
    funcPtr(data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_65_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_loop_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

