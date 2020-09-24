/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_max_multiply_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for short
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__short_max_multiply_67_structType
{
    short structFirst;
} CWE190_Integer_Overflow__short_max_multiply_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_max_multiply_67b_badSink(CWE190_Integer_Overflow__short_max_multiply_67_structType myStruct)
{
    short data = myStruct.structFirst;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > SHRT_MAX, this will overflow */
        short result = data * 2;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

