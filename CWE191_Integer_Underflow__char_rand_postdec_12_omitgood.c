/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_rand_postdec_12.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__char_rand_postdec_12_bad()
{
    char data;
    data = ' ';
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (char)RAND32();
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            /* POTENTIAL FLAW: Decrementing data could cause an underflow */
            data--;
            char result = data;
            printHexCharLine(result);
        }
    }
    else
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > CHAR_MIN)
        {
            data--;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_rand_postdec_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

