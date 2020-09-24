/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_sub_01.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int64_t_rand_sub_01_bad()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int64_t result = data - 1;
        printLongLongLine(result);
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
    CWE191_Integer_Underflow__int64_t_rand_sub_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

