/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_81_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
