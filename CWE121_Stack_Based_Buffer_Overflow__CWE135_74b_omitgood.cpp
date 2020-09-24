/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_74b.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_74
{

#ifndef OMITBAD

void badSink(map<int, void *> dataMap)
{
    /* copy data out of dataMap */
    void * data = dataMap[2];
    {
        /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
        (void)wcscpy((wchar_t *)dest, (wchar_t *)data);
        printLine((char *)dest);
    }
}

#endif /* OMITBAD */


} /* close namespace */
