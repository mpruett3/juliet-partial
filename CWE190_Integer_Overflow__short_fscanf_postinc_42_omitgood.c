/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_fscanf_postinc_42.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static short badSource(short data)
{
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%hd", &data);
    return data;
}

void CWE190_Integer_Overflow__short_fscanf_postinc_42_bad()
{
    short data;
    data = 0;
    data = badSource(data);
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        data++;
        short result = data;
        printIntLine(result);
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
    CWE190_Integer_Overflow__short_fscanf_postinc_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

