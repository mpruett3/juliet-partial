/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_08.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-08.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using strcpy
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* The two function below always return the same value, so a tool
 * should be able to identify that calls to the functions will always
 * return a fixed value.
 */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}


#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the staticReturnsTrue() to staticReturnsFalse() */
static void goodG2B1()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    if(staticReturnsTrue())
    {
        /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_08_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

