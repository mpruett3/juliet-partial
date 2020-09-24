/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_61a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_61b_goodG2BSource(char * data);

static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_61b_goodG2BSource(data);
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        memmove(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_61_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memmove_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
