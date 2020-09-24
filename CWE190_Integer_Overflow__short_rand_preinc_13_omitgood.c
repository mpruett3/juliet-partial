/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_preinc_13.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-13.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_rand_preinc_13_bad()
{
    short data;
    data = 0;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
            short result = data;
            printIntLine(result);
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
    CWE190_Integer_Overflow__short_rand_preinc_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

