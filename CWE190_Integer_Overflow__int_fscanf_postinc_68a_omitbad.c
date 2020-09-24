/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_postinc_68a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE190_Integer_Overflow__int_fscanf_postinc_68_badData;
int CWE190_Integer_Overflow__int_fscanf_postinc_68_goodG2BData;
int CWE190_Integer_Overflow__int_fscanf_postinc_68_goodB2GData;


#ifndef OMITGOOD

/* good function declarations */
void CWE190_Integer_Overflow__int_fscanf_postinc_68b_goodG2BSink();
void CWE190_Integer_Overflow__int_fscanf_postinc_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__int_fscanf_postinc_68_goodG2BData = data;
    CWE190_Integer_Overflow__int_fscanf_postinc_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE190_Integer_Overflow__int_fscanf_postinc_68_goodB2GData = data;
    CWE190_Integer_Overflow__int_fscanf_postinc_68b_goodB2GSink();
}

void CWE190_Integer_Overflow__int_fscanf_postinc_68_good()
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
    CWE190_Integer_Overflow__int_fscanf_postinc_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

