/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_rand_multiply_54d.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__char_rand_multiply_54e_badSink(char data);

void CWE191_Integer_Underflow__char_rand_multiply_54d_badSink(char data)
{
    CWE191_Integer_Underflow__char_rand_multiply_54e_badSink(data);
}

#endif /* OMITBAD */

