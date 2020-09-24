/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_postinc_67b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__int_fscanf_postinc_67_structType
{
    int structFirst;
} CWE190_Integer_Overflow__int_fscanf_postinc_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fscanf_postinc_67b_badSink(CWE190_Integer_Overflow__int_fscanf_postinc_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        int result = data;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

