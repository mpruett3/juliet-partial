/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_fscanf_add_68b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern short CWE190_Integer_Overflow__short_fscanf_add_68_badData;
extern short CWE190_Integer_Overflow__short_fscanf_add_68_goodG2BData;
extern short CWE190_Integer_Overflow__short_fscanf_add_68_goodB2GData;

#ifndef OMITBAD

void CWE190_Integer_Overflow__short_fscanf_add_68b_badSink()
{
    short data = CWE190_Integer_Overflow__short_fscanf_add_68_badData;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        short result = data + 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

