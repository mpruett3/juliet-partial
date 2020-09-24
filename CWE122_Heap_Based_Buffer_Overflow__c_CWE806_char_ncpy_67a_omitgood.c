/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_structType
{
    char * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_bad()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_structType myStruct;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67b_badSink(myStruct);
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}
