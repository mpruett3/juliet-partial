/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_square_74a.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-74a.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE190_Integer_Overflow__int64_t_rand_square_74
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(map<int, int64_t> dataMap);

void bad()
{
    int64_t data;
    map<int, int64_t> dataMap;
    data = 0LL;
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
    /* Put data in a map */
    dataMap[0] = data;
    dataMap[1] = data;
    dataMap[2] = data;
    badSink(dataMap);
}

#endif /* OMITBAD */


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */


using namespace CWE190_Integer_Overflow__int64_t_rand_square_74; /* so that we can use good and bad easily */

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

