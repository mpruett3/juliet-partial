/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memmove_84_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
