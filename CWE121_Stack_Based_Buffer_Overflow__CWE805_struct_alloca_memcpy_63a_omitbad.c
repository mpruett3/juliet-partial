/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memcpy_63a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memcpy
 *    BadSink : Copy twoIntsStruct array to data using memcpy
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memcpy_63b_goodG2BSink(twoIntsStruct * * data);

static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct * dataBadBuffer = (twoIntsStruct *)ALLOCA(50*sizeof(twoIntsStruct));
    twoIntsStruct * dataGoodBuffer = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memcpy_63b_goodG2BSink(&data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memcpy_63_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memcpy_63_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

