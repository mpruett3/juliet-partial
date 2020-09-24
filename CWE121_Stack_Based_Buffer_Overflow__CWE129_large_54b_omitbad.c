/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE129.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54c_goodG2BSink(int data);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54b_goodG2BSink(int data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54c_goodB2GSink(int data);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54b_goodB2GSink(int data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_54c_goodB2GSink(data);
}

#endif /* OMITGOOD */