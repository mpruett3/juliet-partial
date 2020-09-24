/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_badData;
int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodG2BData;
int CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodB2GData;


#ifndef OMITGOOD

/* good function declarations */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodG2BSink();
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodG2BData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodB2GData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodB2GSink();
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
