/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__unsigned_int_rand_predec_68a.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

unsigned int CWE191_Integer_Underflow__unsigned_int_rand_predec_68_badData;
unsigned int CWE191_Integer_Underflow__unsigned_int_rand_predec_68_goodG2BData;
unsigned int CWE191_Integer_Underflow__unsigned_int_rand_predec_68_goodB2GData;


#ifndef OMITGOOD

/* good function declarations */
void CWE191_Integer_Underflow__unsigned_int_rand_predec_68b_goodG2BSink();
void CWE191_Integer_Underflow__unsigned_int_rand_predec_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__unsigned_int_rand_predec_68_goodG2BData = data;
    CWE191_Integer_Underflow__unsigned_int_rand_predec_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE191_Integer_Underflow__unsigned_int_rand_predec_68_goodB2GData = data;
    CWE191_Integer_Underflow__unsigned_int_rand_predec_68b_goodB2GSink();
}

void CWE191_Integer_Underflow__unsigned_int_rand_predec_68_good()
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
    CWE191_Integer_Underflow__unsigned_int_rand_predec_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

