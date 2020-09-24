/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_61a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int64_t CWE190_Integer_Overflow__int64_t_rand_add_61b_badSource(int64_t data);

void CWE190_Integer_Overflow__int64_t_rand_add_61_bad()
{
    int64_t data;
    data = 0LL;
    data = CWE190_Integer_Overflow__int64_t_rand_add_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
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
    CWE190_Integer_Overflow__int64_t_rand_add_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}
