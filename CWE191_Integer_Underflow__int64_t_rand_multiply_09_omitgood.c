/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_multiply_09.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int64_t_rand_multiply_09_bad()
{
    int64_t data;
    data = 0LL;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
    }
    if(GLOBAL_CONST_TRUE)
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
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
    CWE191_Integer_Underflow__int64_t_rand_multiply_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

