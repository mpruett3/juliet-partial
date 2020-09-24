/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_66a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy twoIntsStruct array to data using a loop
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_66b_badSink(twoIntsStruct * dataArray[]);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_66_bad()
{
    twoIntsStruct * data;
    twoIntsStruct * dataArray[5];
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (twoIntsStruct *)malloc(50*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* put data in array */
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_66b_badSink(dataArray);
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

