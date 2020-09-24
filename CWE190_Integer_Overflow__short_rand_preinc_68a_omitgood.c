/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_preinc_68a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

short CWE190_Integer_Overflow__short_rand_preinc_68_badData;
short CWE190_Integer_Overflow__short_rand_preinc_68_goodG2BData;
short CWE190_Integer_Overflow__short_rand_preinc_68_goodB2GData;

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__short_rand_preinc_68b_badSink();

void CWE190_Integer_Overflow__short_rand_preinc_68_bad()
{
    short data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    CWE190_Integer_Overflow__short_rand_preinc_68_badData = data;
    CWE190_Integer_Overflow__short_rand_preinc_68b_badSink();
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
    CWE190_Integer_Overflow__short_rand_preinc_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

