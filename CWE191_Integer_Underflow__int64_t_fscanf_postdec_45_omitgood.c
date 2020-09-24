/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_postdec_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"

static int64_t CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_badData;
static int64_t CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_goodG2BData;
static int64_t CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int64_t data = CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_badData;
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        data--;
        int64_t result = data;
        printLongLongLine(result);
    }
}

void CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_bad()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%" SCNd64, &data);
    CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_badData = data;
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
    CWE191_Integer_Underflow__int64_t_fscanf_postdec_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

