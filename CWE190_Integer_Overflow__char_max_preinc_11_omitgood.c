/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_preinc_11.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__char_max_preinc_11_bad()
{
    char data;
    data = ' ';
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Use the maximum size of the data type */
        data = CHAR_MAX;
    }
    if(globalReturnsTrue())
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            ++data;
            char result = data;
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
    CWE190_Integer_Overflow__char_max_preinc_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

