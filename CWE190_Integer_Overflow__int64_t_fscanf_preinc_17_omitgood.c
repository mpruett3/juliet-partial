/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_fscanf_preinc_17.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_fscanf_preinc_17_bad()
{
    int i,j;
    int64_t data;
    data = 0LL;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%" SCNd64, &data);
    }
    for(j = 0; j < 1; j++)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
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
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

