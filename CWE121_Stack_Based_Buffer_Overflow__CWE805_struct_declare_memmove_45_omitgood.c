/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.label.xml
Template File: sources-sink-45.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy twoIntsStruct array to data using memmove
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static twoIntsStruct * CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_badData;
static twoIntsStruct * CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_goodG2BData;

#ifndef OMITBAD

static void badSink()
{
    twoIntsStruct * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_badData;
    {
        twoIntsStruct source[100];
        {
            size_t i;
            /* Initialize array */
            for (i = 0; i < 100; i++)
            {
                source[i].intOne = 0;
                source[i].intTwo = 0;
            }
        }
        /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
        memmove(data, source, 100*sizeof(twoIntsStruct));
        printStructLine(&data[0]);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = dataBadBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_badData = data;
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
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memmove_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

