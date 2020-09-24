/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memmove
 *    BadSink : Copy int64_t array to data using memmove
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int64_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68_badData;
int64_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68_goodG2BData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68b_goodG2BSink();
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_memmove_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
