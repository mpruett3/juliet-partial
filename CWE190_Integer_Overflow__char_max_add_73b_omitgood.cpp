/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_add_73b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE190_Integer_Overflow__char_max_add_73
{

#ifndef OMITBAD

void badSink(list<char> dataList)
{
    /* copy data out of dataList */
    char data = dataList.back();
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

#endif /* OMITBAD */


} /* close namespace */
