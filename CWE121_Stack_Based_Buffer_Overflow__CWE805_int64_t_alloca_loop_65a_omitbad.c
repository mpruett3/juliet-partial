/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_alloca_loop_65a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: loop
 *    BadSink : Copy int64_t array to data using a loop
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_alloca_loop_65b_goodG2BSink(int64_t * data);

static void goodG2B()
{
    int64_t * data;
    void (*funcPtr) (int64_t *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_alloca_loop_65b_goodG2BSink;
    int64_t * dataBadBuffer = (int64_t *)ALLOCA(50*sizeof(int64_t));
    int64_t * dataGoodBuffer = (int64_t *)ALLOCA(100*sizeof(int64_t));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    funcPtr(data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_alloca_loop_65_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_alloca_loop_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

