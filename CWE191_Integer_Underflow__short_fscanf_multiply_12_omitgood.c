/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_multiply_12.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_fscanf_multiply_12_bad()
{
    short data;
    data = 0;
    if(globalReturnsTrueOrFalse())
    {
        /* POTENTIAL FLAW: Use a value input from the console */
        fscanf (stdin, "%hd", &data);
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
    }
    if(globalReturnsTrueOrFalse())
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
            short result = data * 2;
            printIntLine(result);
        }
    }
    else
    {
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > (SHRT_MIN/2))
            {
                short result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("data value is too small to perform multiplication.");
            }
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
    CWE191_Integer_Underflow__short_fscanf_multiply_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

