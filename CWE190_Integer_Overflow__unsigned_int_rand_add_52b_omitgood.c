/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_add_52b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_rand_add_52c_badSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_add_52b_badSink(unsigned int data)
{
    CWE190_Integer_Overflow__unsigned_int_rand_add_52c_badSink(data);
}

#endif /* OMITBAD */

