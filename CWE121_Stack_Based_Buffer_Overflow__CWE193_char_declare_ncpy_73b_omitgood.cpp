/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_ncpy_73b.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE193.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Point data to a buffer that does not have space for a NULL terminator
 * GoodSource: Point data to a buffer that includes space for a NULL terminator
 * Sinks: ncpy
 *    BadSink : Copy string to data using strncpy()
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

using namespace std;

namespace CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_ncpy_73
{

#ifndef OMITBAD

void badSink(list<char *> dataList)
{
    /* copy data out of dataList */
    char * data = dataList.back();
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
    }
}

#endif /* OMITBAD */


} /* close namespace */
