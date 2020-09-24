/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_square_52b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int64_t_rand_square_52c_goodG2BSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_rand_square_52b_goodG2BSink(int64_t data)
{
    CWE190_Integer_Overflow__int64_t_rand_square_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int64_t_rand_square_52c_goodB2GSink(int64_t data);

void CWE190_Integer_Overflow__int64_t_rand_square_52b_goodB2GSink(int64_t data)
{
    CWE190_Integer_Overflow__int64_t_rand_square_52c_goodB2GSink(data);
}

#endif /* OMITGOOD */
