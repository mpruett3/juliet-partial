/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_min_sub_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for unsigned int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static unsigned int CWE191_Integer_Underflow__unsigned_int_min_sub_45_badData;
static unsigned int CWE191_Integer_Underflow__unsigned_int_min_sub_45_goodG2BData;
static unsigned int CWE191_Integer_Underflow__unsigned_int_min_sub_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    unsigned int data = CWE191_Integer_Underflow__unsigned_int_min_sub_45_badData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        unsigned int result = data - 1;
        printUnsignedLine(result);
    }
}

void CWE191_Integer_Underflow__unsigned_int_min_sub_45_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use the minimum size of the data type */
    data = 0;
    CWE191_Integer_Underflow__unsigned_int_min_sub_45_badData = data;
    badSink();
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
    CWE191_Integer_Underflow__unsigned_int_min_sub_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

