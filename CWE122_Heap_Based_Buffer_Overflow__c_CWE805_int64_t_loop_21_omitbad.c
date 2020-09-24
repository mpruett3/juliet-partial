/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_21.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-21.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy int64_t array to data using a loop
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"


#ifndef OMITGOOD

/* The static variables below are used to drive control flow in the source functions. */
static int goodG2B1Static = 0;
static int goodG2B2Static = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
static int64_t * goodG2B1Source(int64_t * data)
{
    if(goodG2B1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

static void goodG2B1()
{
    int64_t * data;
    data = NULL;
    goodG2B1Static = 0; /* false */
    data = goodG2B1Source(data);
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
            free(data);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
static int64_t * goodG2B2Source(int64_t * data)
{
    if(goodG2B2Static)
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

static void goodG2B2()
{
    int64_t * data;
    data = NULL;
    goodG2B2Static = 1; /* true */
    data = goodG2B2Source(data);
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
            free(data);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_21_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_21_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}
