/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_add_68b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE190_Integer_Overflow__int_max_add_68_badData;
extern int CWE190_Integer_Overflow__int_max_add_68_goodG2BData;
extern int CWE190_Integer_Overflow__int_max_add_68_goodB2GData;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_max_add_68b_badSink()
{
    int data = CWE190_Integer_Overflow__int_max_add_68_badData;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int result = data + 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */
