/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_square_62b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__int64_t_rand_square_62
{

#ifndef OMITBAD

void badSource(int64_t &data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
}

#endif /* OMITBAD */


} /* close namespace */
