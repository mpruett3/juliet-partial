/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_multiply_84_goodG2B.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
