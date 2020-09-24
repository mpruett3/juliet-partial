/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_structType
{
    int structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_bad()
{
    int data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67b_badSink(myStruct);
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

