/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_square_65b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_square_65b_badSink(int data)
{
    {
        /* POTENTIAL FLAW: if (data*data) > INT_MAX, this will overflow */
        int result = data * data;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

