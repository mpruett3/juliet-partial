/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_add_07.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-07.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_rand_add_07_bad()
{
    short data;
    data = 0;
    if(staticFive==5)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
    }
    if(staticFive==5)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            short result = data + 1;
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
    CWE190_Integer_Overflow__short_rand_add_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

