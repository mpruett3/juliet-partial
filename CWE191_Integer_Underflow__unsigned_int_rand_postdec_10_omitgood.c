/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_postdec_10.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-10.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__unsigned_int_rand_postdec_10_bad()
{
    unsigned int data;
    data = 0;
    if(globalTrue)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (unsigned int)RAND32();
    }
    if(globalTrue)
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            unsigned int result = data;
            printUnsignedLine(result);
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
    CWE191_Integer_Underflow__unsigned_int_rand_postdec_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

