/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_34.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_34_unionType;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_34_bad()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_34_unionType myUnion;
    data = NULL;
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; /* null terminate */
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        {
            char source[100];
            memset(source, 'C', 100-1); /* fill with 'C's */
            source[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
            memcpy(data, source, 100*sizeof(char));
            data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
            printLine(data);
            free(data);
        }
    }
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memcpy_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

