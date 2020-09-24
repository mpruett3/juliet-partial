/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncat
 *    BadSink : Copy data to string using strncat
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

static char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_badData;
static char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    char * data = CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_badData;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_badData = data;
    badSink();
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
    CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_ncat_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

