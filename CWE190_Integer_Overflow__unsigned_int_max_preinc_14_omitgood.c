/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_max_preinc_14.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for unsigned int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_max_preinc_14_bad()
{
    unsigned int data;
    data = 0;
    if(globalFive==5)
    {
        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = UINT_MAX;
    }
    if(globalFive==5)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
            unsigned int result = data;
            printUnsignedLine(result);
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
    CWE190_Integer_Overflow__unsigned_int_max_preinc_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

