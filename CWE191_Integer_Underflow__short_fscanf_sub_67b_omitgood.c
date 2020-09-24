/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_sub_67b.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE191_Integer_Underflow__short_fscanf_sub_67_structType
{
    short structFirst;
} CWE191_Integer_Underflow__short_fscanf_sub_67_structType;

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_fscanf_sub_67b_badSink(CWE191_Integer_Underflow__short_fscanf_sub_67_structType myStruct)
{
    short data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        short result = data - 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

