/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__placement_new_54a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-54a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data to a small buffer
 * GoodSource: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    GoodSink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    BadSink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_54
{


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_b(char * data);

static void goodG2B()
{
    char * data;
    char * dataBadBuffer = (char *)malloc(sizeof(OneIntClass));
    if (dataBadBuffer == NULL) {exit(-1);}
    char * dataGoodBuffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataGoodBuffer == NULL) {exit(-1);}
    /* FIX: Initialize to a buffer at least the sizeof(TwoIntsClass) */
    data = dataGoodBuffer;
    goodG2BSink_b(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_b(char * data);

static void goodB2G()
{
    char * data;
    char * dataBadBuffer = (char *)malloc(sizeof(OneIntClass));
    if (dataBadBuffer == NULL) {exit(-1);}
    char * dataGoodBuffer = (char *)malloc(sizeof(TwoIntsClass));
    if (dataGoodBuffer == NULL) {exit(-1);}
    /* POTENTIAL FLAW: Initialize data to a buffer small than the sizeof(TwoIntsClass) */
    data = dataBadBuffer;
    goodB2GSink_b(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE122_Heap_Based_Buffer_Overflow__placement_new_54; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

