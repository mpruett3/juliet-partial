/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_fscanf_multiply_53a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int64_t_fscanf_multiply_53b_goodG2BSink(int64_t data);

static void goodG2B()
{
    int64_t data;
    data = 0LL;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_53b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int64_t_fscanf_multiply_53b_goodB2GSink(int64_t data);

static void goodB2G()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%" SCNd64, &data);
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_53b_goodB2GSink(data);
}

void CWE191_Integer_Underflow__int64_t_fscanf_multiply_53_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE191_Integer_Underflow__int64_t_fscanf_multiply_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

