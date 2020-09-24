/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: snprintf
 *    BadSink : Copy data to string using snprintf
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81
{

#ifndef OMITBAD

void bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    const CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81_bad();
    baseObject.action(data);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


using namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_81; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

