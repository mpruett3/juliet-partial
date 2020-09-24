/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_min_predec_65b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for short
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__short_min_predec_65b_goodG2BSink(short data)
{
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        short result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__short_min_predec_65b_goodB2GSink(short data)
{
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > SHRT_MIN)
    {
        --data;
        short result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

#endif /* OMITGOOD */
