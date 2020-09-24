/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_multiply_67a.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__int_max_multiply_67_structType
{
    int structFirst;
} CWE190_Integer_Overflow__int_max_multiply_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int_max_multiply_67b_badSink(CWE190_Integer_Overflow__int_max_multiply_67_structType myStruct);

void CWE190_Integer_Overflow__int_max_multiply_67_bad()
{
    int data;
    CWE190_Integer_Overflow__int_max_multiply_67_structType myStruct;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int_max_multiply_67b_badSink(myStruct);
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
    CWE190_Integer_Overflow__int_max_multiply_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

