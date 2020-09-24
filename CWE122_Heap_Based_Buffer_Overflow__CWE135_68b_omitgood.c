/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern void * CWE122_Heap_Based_Buffer_Overflow__CWE135_68_badData;
extern void * CWE122_Heap_Based_Buffer_Overflow__CWE135_68_goodG2BData;
extern void * CWE122_Heap_Based_Buffer_Overflow__CWE135_68_goodB2GData;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__CWE135_68b_badSink()
{
    void * data = CWE122_Heap_Based_Buffer_Overflow__CWE135_68_badData;
    {
        /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy(dest, data);
        printLine((char *)dest);
        free(dest);
    }
}

#endif /* OMITBAD */

