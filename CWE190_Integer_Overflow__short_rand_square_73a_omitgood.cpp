/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_square_73a.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE190_Integer_Overflow__short_rand_square_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<short> dataList);

void bad()
{
    short data;
    list<short> dataList;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE190_Integer_Overflow__short_rand_square_73; /* so that we can use good and bad easily */

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

