/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncpy_81_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: ncpy
 *    BadSink : Copy data to string using strncpy
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
