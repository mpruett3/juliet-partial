/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_square_18.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_rand_square_18_bad()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    goto sink;
sink:
    {
        /* POTENTIAL FLAW: if (data*data) > UINT_MAX, this will overflow */
        unsigned int result = data * data;
        printUnsignedLine(result);
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
    CWE190_Integer_Overflow__unsigned_int_rand_square_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

