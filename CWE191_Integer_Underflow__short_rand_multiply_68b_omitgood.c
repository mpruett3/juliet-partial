/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_multiply_68b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern short CWE191_Integer_Underflow__short_rand_multiply_68_badData;
extern short CWE191_Integer_Underflow__short_rand_multiply_68_goodG2BData;
extern short CWE191_Integer_Underflow__short_rand_multiply_68_goodB2GData;

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_rand_multiply_68b_badSink()
{
    short data = CWE191_Integer_Underflow__short_rand_multiply_68_badData;
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

