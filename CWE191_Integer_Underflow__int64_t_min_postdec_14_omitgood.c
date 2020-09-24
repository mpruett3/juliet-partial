/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_min_postdec_14.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for int64_t
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int64_t_min_postdec_14_bad()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Use the minimum size of the data type */
        data = LLONG_MIN;
    }
    if(globalFive==5)
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            int64_t result = data;
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
    CWE191_Integer_Underflow__int64_t_min_postdec_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

