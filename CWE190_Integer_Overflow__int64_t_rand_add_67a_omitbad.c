/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_67a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__int64_t_rand_add_67_structType
{
    int64_t structFirst;
} CWE190_Integer_Overflow__int64_t_rand_add_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int64_t_rand_add_67b_goodG2BSink(CWE190_Integer_Overflow__int64_t_rand_add_67_structType myStruct);

static void goodG2B()
{
    int64_t data;
    CWE190_Integer_Overflow__int64_t_rand_add_67_structType myStruct;
    data = 0LL;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int64_t_rand_add_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int64_t_rand_add_67b_goodB2GSink(CWE190_Integer_Overflow__int64_t_rand_add_67_structType myStruct);

static void goodB2G()
{
    int64_t data;
    CWE190_Integer_Overflow__int64_t_rand_add_67_structType myStruct;
    data = 0LL;
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__int64_t_rand_add_67b_goodB2GSink(myStruct);
}

void CWE190_Integer_Overflow__int64_t_rand_add_67_good()
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
    CWE190_Integer_Overflow__int64_t_rand_add_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

