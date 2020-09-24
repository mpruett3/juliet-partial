/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_multiply_07.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-07.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_07_bad()
{
    int64_t data;
    data = 0LL;
    if(staticFive==5)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%" SCNd64, &data);
    }
    if(staticFive==5)
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
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

