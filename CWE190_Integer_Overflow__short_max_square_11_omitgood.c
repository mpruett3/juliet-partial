/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_square_11.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_max_square_11_bad()
{
    short data;
    data = 0;
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = SHRT_MAX;
    }
    if(globalReturnsTrue())
    {
        {
            /* POTENTIAL FLAW: if (data*data) > SHRT_MAX, this will overflow */
            short result = data * data;
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
    CWE190_Integer_Overflow__short_max_square_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

