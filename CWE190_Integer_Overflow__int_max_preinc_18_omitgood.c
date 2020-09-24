/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_preinc_18.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_preinc_18_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        int result = data;
        printIntLine(result);
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
    CWE190_Integer_Overflow__int_max_preinc_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

