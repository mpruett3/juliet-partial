/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_max_add_45.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int64_t
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int64_t CWE190_Integer_Overflow__int64_t_max_add_45_badData;
static int64_t CWE190_Integer_Overflow__int64_t_max_add_45_goodG2BData;
static int64_t CWE190_Integer_Overflow__int64_t_max_add_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_max_add_45_badData;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
    }
}

void CWE190_Integer_Overflow__int64_t_max_add_45_bad()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = LLONG_MAX;
    CWE190_Integer_Overflow__int64_t_max_add_45_badData = data;
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
    CWE190_Integer_Overflow__int64_t_max_add_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

