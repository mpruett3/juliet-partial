/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fgets_postinc_16.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_fgets_postinc_16_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    while(1)
    {
        {
            char inputBuffer[CHAR_ARRAY_SIZE] = "";
            /* POTENTIAL FLAW: Read data from the console using fgets() */
            if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
            {
                /* Convert to int */
                data = atoi(inputBuffer);
            }
            else
            {
                printLine("fgets() failed.");
            }
        }
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Incrementing data could cause an overflow */
            data++;
            int result = data;
            printIntLine(result);
        }
        break;
    }
}

#endif /* OMITBAD */


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_fgets_postinc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

