/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: loop
 *    BadSink : Copy int64_t array to data using a loop
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static int64_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_badData;
static int64_t * CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_goodG2BData;


#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int64_t * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_goodG2BData;
    {
        int64_t source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
        }
    }
}

static void goodG2B()
{
    int64_t * data;
    int64_t dataBadBuffer[50];
    int64_t dataGoodBuffer[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_goodG2BData = data;
    goodG2BSink();
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int64_t_declare_loop_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

