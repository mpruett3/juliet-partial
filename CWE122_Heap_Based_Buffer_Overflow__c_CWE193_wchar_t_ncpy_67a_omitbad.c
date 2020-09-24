/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: ncpy
 *    BadSink : Copy string to data using wcsncpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType
{
    wchar_t * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType;


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType myStruct;
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67b_goodG2BSink(myStruct);
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

