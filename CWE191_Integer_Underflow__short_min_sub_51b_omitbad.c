/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_sub_51b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-51b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__short_min_sub_51b_goodG2BSink(short data)
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__short_min_sub_51b_goodB2GSink(short data)
{
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > SHRT_MIN)
    {
        short result = data - 1;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform subtraction.");
    }
}

#endif /* OMITGOOD */
