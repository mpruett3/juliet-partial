/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_83_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
