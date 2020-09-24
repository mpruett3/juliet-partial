/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_sub_68b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern short CWE191_Integer_Underflow__short_rand_sub_68_badData;
extern short CWE191_Integer_Underflow__short_rand_sub_68_goodG2BData;
extern short CWE191_Integer_Underflow__short_rand_sub_68_goodB2GData;

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_rand_sub_68b_badSink()
{
    short data = CWE191_Integer_Underflow__short_rand_sub_68_badData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */
