/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_ncat_81_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: ncat
 *    BadSink : Copy string to data using strncat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
