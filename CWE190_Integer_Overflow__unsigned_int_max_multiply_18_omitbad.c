/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_multiply_18.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = UINT_MAX;
    goto sink;
sink:
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < (UINT_MAX/2))
        {
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    goto sink;
sink:
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > UINT_MAX, this will overflow */
        unsigned int result = data * 2;
        printUnsignedLine(result);
    }
}

void CWE190_Integer_Overflow__unsigned_int_max_multiply_18_good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__unsigned_int_max_multiply_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

