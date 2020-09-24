/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_ncpy_84_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: ncpy
 *    BadSink : Copy string to data using wcsncpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
