/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_add_14.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_rand_add_14_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Set data to a random value */
        data = RAND32();
    }
    if(globalFive==5)
    {
        {
            /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
            int result = data + 1;
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
    CWE190_Integer_Overflow__int_rand_add_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

