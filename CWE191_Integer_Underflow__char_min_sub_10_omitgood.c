/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_min_sub_10.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-10.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for char
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__char_min_sub_10_bad()
{
    char data;
    data = ' ';
    if(globalTrue)
    {
        /* POTENTIAL FLAW: Use the minimum size of the data type */
        data = CHAR_MIN;
    }
    if(globalTrue)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            char result = data - 1;
            printHexCharLine(result);
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
    CWE191_Integer_Underflow__char_min_sub_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

