/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_predec_61a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int CWE191_Integer_Underflow__int_min_predec_61b_badSource(int data);

void CWE191_Integer_Underflow__int_min_predec_61_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_min_predec_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
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
    CWE191_Integer_Underflow__int_min_predec_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

