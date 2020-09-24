/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memmove_81_bad.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE193.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Point data to a buffer that does not have space for a NULL terminator
 * GoodSource: Point data to a buffer that includes space for a NULL terminator
 * Sinks: memmove
 *    BadSink : Copy string to data using memmove()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
