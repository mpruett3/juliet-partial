/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_rand_sub_44.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void badSink(int data)
{
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

void CWE191_Integer_Underflow__int_rand_sub_44_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = badSink;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    /* use the function pointer */
    funcPtr(data);
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
    CWE191_Integer_Underflow__int_rand_sub_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

