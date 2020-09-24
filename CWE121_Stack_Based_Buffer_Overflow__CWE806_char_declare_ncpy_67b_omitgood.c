/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_67b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_67_structType
{
    char * structFirst;
} CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_67_structType;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strncpy(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

#endif /* OMITBAD */

