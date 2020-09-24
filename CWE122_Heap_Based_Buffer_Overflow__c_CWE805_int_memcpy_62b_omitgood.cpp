/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_62b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memcpy
 *    BadSink : Copy int array to data using memcpy
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_62
{

#ifndef OMITBAD

void badSource(int * &data)
{
    /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (int *)malloc(50*sizeof(int));
    if (data == NULL) {exit(-1);}
}

#endif /* OMITBAD */


} /* close namespace */
