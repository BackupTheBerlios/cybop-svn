/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: tester.c,v $ $Revision: 1.35 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POINTER_TESTER
#define POINTER_TESTER

#include <stdio.h>
#include <wchar.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../logger/logger.c"

/**
 * Tests the pointer null value as subroutine.
 */
void test_pointer_null_subroutine(void* p0, void* p1) {

    log_write_terminated_message((void*) stdout, L"Test pointer null as subroutine:\n");

    void** a = (void**) p0;
    void* b = p1;

    fwprintf(stdout, L"Pointer subroutine a: %i\n", a);
    fwprintf(stdout, L"Pointer subroutine *a: %i\n", *a);
    fwprintf(stdout, L"Pointer subroutine b: %i\n", b);
    fwprintf(stdout, L"Pointer subroutine NULL_POINTER_MEMORY_MODEL: %i\n", NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"Pointer subroutine *NULL_POINTER_MEMORY_MODEL: %i\n", *NULL_POINTER_MEMORY_MODEL);
}

/**
 * Tests the pointer null value.
 */
void test_pointer_null() {

    log_write_terminated_message((void*) stdout, L"Test pointer null:\n");

    void** a = NULL_POINTER_MEMORY_MODEL;
    void* b = *NULL_POINTER_MEMORY_MODEL;

    test_pointer_null_subroutine((void*) a, b);
}

/**
 * Tests the pointer cast.
 */
void test_pointer_cast() {

    log_write_terminated_message((void*) stdout, L"Test pointer cast:\n");

    // Assign a test character array.
    wchar_t* test_char = L"test pointer cast ok\n";

    // The & operator makes a wchar_t** from wchar_t*, in other words a pointer pointer.
    // The wchar_t** is then casted to a normal void* which is used to hand
    // over parameters in all procedures of cyboi.
    void* test_void = (void*) &test_char;

    // The void* which was for example retrieved as parameter of a procedure
    // has to be casted back to the original wchar_t**.
    wchar_t** test_back = (wchar_t**) test_void;

    // The wchar_t** has to be dereferenced using the * operator,
    // because the fputs function expects a wchar_t*.
    log_write_terminated_message((void*) stdout, *test_back);
}

/**
 * Tests the pointer return.
 *
 * In other words, if an array element is returned correctly,
 * when using a null pointer.
 */
void test_pointer_return() {

    log_write_terminated_message((void*) stdout, L"Test pointer return:\n");

    // The character array (including new line and null termination character).
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int* cs = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Create character array.
    c = (void*) L"Hello World!";
    allocate((void*) &cs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    *cs = *NUMBER_13_INTEGER_MEMORY_MODEL;

    // THIS is the important part of the test.
    // A simple null pointer can be declared and passed to a procedure (as reference &).
    // The procedure can then dereference the pointer (*parameter) and store the result.
    // Since this works, one can avoid allocating extra local result variables,
    // and use just a null pointer to initialise the result variable.

    // The result array.
    void* r = *NULL_POINTER_MEMORY_MODEL;

    // Get character from character array.
    get_array_elements((void*) &r, c, (void*) NUMBER_6_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Print result (character array).
    fwprintf(stdout, L"r: %ls\n", (wchar_t*) r);

    // Destroy character array.
    deallocate((void*) &cs, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the character array with termination.
 */
void test_character_array_with_termination() {

    log_write_terminated_message((void*) stdout, L"Test character array with termination:\n");

    // The brackets indicating an array cannot be avoided or replaced by a pointer.
    // The following line does not work:
    // wchar_t* test = {L't', L'e', L's', L't', L'\n', L'\0'};

    // The '\n' character is a new line.
    // The character array (string) termination '\0' is necessary when using
    // GNU C library functions such as "fputs".
    wchar_t test[] = {L't', L'e', L's', L't', L' ', L'c', L'h', L'a', L'r', L' ', L'a', L'r', L'r', L'a', L'y', L' ', L'o', L'k', L'\n', L'\0'};

    log_write_terminated_message((void*) stdout, test);
}

/**
 * Tests the character array with a single element.
 */
void test_character_array_single_element() {

    log_write_terminated_message((void*) stdout, L"Test character array single element:\n");

    // The character array.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int cs = *NUMBER_5_INTEGER_MEMORY_MODEL;

    // Create character array.
    allocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    set_array_elements(c, (void*) LATIN_CAPITAL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(c, (void*) LATIN_CAPITAL_LETTER_B_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(c, (void*) LATIN_CAPITAL_LETTER_C_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(c, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(c, (void*) NULL_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Print out array contents.
    log_write_terminated_message((void*) stdout, (wchar_t*) c);

    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
    wchar_t* catest = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (i >= cs) {

            break;
        }

        catest = (wchar_t*) (c + i);
        fwprintf(stdout, L"ca: %c\n", *catest);

        i++;
    }

    // Destroy character array.
    deallocate_array((void*) &c, (void*) &cs, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the character array with multiple elements.
 */
void test_character_array_multiple_elements() {

    log_write_terminated_message((void*) stdout, L"Test character array multiple elements:\n");

    // The destination array.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int ds = *NUMBER_22_INTEGER_MEMORY_MODEL;

    // Create destination array.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // The source array.
    wchar_t a[] = {L'T', L'h', L'i', L's', L' ', L'i', L's', L' ', L'a', L' ', L't', L'e', L's', L't', L'.', L'\n', L'\0'};
    wchar_t* s = a;
    int ssa[] = {17};
    int* ss = ssa;

    // The destination index to which to copy the source array.
    set_array_elements(d, (void*) s, (void*) ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The source array for overwriting.
    wchar_t oa[] = {L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L't', L'e', L'n', L'.', L'\n', L'\0'};
    wchar_t* os = oa;
    int ossa[] = {14};
    int* oss = ossa;

    set_array_elements(d, (void*) os, (void*) oss, (void*) NUMBER_8_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The remove index.
    int ri = *NUMBER_12_INTEGER_MEMORY_MODEL;

    remove_array_elements(d, (void*) &ds, (void*) &ri, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The new array size to cut off remaining elements,
    // including two places for new line '\n' and c string termination '\0'.
    int ns = *NUMBER_15_INTEGER_MEMORY_MODEL;

    reallocate_array((void*) &d, (void*) &ns, (void*) &ns, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) d);

    // The result array.
    void* r = *NULL_POINTER_MEMORY_MODEL;

    // Test getting a reference.
    get_array_elements((void*) &r, d, (void*) NUMBER_8_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    log_write_terminated_message((void*) stdout, (wchar_t*) r);

    // Destroy destination array.
    deallocate_array((void*) &d, (void*) &ns, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the integer array.
 */
void test_integer_array() {

    log_write_terminated_message((void*) stdout, L"Test integer array:\n");

    // The test value (for the "decode" function below).
    wchar_t* test = L"2,3,4";
    int testc = *NUMBER_5_INTEGER_MEMORY_MODEL;

    // The test knowledge model.
    int* m = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* mc = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* ms = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Allocate test knowledge model.
    allocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    *mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    allocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    *ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
    allocate((void*) &m, (void*) ms, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"pre mc: %i\n", *mc);
    fwprintf(stdout, L"pre ms: %i\n", *ms);
    fwprintf(stdout, L"pre m: %i\n", *m);

    //
    // Use either the "decode" function or the three "set" functions below.
    // Both possibilities should have the same functionality and results.
    //

/*??
    // Decode (parse) test value and assign to test knowledge model.
    decode((void*) &m, (void*) mc, (void*) ms, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) test, (void*) &testc,
        *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
*/

    // Set test values.
    set((void*) &m, (void*) mc, (void*) ms, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) mc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    set((void*) &m, (void*) mc, (void*) ms, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) mc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    set((void*) &m, (void*) mc, (void*) ms, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) mc, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    // The result values read out from the integer vector.
    int* result0 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* result1 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* result2 = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Get result values.
    get((void*) &result0, m, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &result1, m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &result2, m, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"post mc: %i\n", *mc);
    fwprintf(stdout, L"post ms: %i\n", *ms);
    fwprintf(stdout, L"post m: %i\n", *m);
    fwprintf(stdout, L"post result0: %i\n", *result0);
    fwprintf(stdout, L"post result1: %i\n", *result1);
    fwprintf(stdout, L"post result2: %i\n", *result2);

    // Deallocate test knowledge model.
    deallocate((void*) &m, (void*) ms, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &mc, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    deallocate((void*) &ms, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the pointer array.
 */
void test_pointer_array() {

    log_write_terminated_message((void*) stdout, L"Test pointer array:\n");

    //
    // Creation.
    //

    // The character array (including new line and null termination character).
    void* c = (void*) L"Hello World!";
    int cs = *NUMBER_13_INTEGER_MEMORY_MODEL;

    fwprintf(stdout, L"c: %ls\n", (wchar_t*) c);

    // The pointer array.
    void** p = NULL_POINTER_MEMORY_MODEL;
    int ps = *NUMBER_1_INTEGER_MEMORY_MODEL;

    // Create pointer array.
    allocate_array((void*) &p, (void*) &ps, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"p: %i\n", p);

    // The result array.
    void** r = NULL_POINTER_MEMORY_MODEL;

    //
    // Testing.
    //

    fwprintf(stdout, L"p[0] before set: %i\n", p[0]);
    fwprintf(stdout, L"p[1] before set: %i\n", p[1]);

    // Set character array in pointer array.
    // Hand over character array as reference, because pointer array is expected!
    set_array_elements(p, (void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"p[0] after set: %i\n", p[0]);
    fwprintf(stdout, L"p[1] after set: %i\n", p[1]);

    // Get character array from pointer array.
    get_array_elements((void*) &r, p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Print result (character array).
    fwprintf(stdout, L"r pointer: %i\n", *r);
    fwprintf(stdout, L"r string: %ls\n", (wchar_t*) *r);

    //
    // Destruction.
    //

    // Destroy pointer array.
    deallocate_array((void*) &p, (void*) &ps, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the pointer array with null values.
 */
void test_pointer_array_with_null_values() {

    log_write_terminated_message((void*) stdout, L"Test pointer array with null values:\n");

    // The pointer array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    int as = *NUMBER_5_INTEGER_MEMORY_MODEL;

    allocate_array((void*) &a, (void*) &as, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    set_array_elements(a, (void*) &COMMERCIAL_AT_UNICODE_CHARACTER_CODE_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(a, (void*) (void*) &NUMBER_333_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(a, (void*) (void*) NULL_POINTER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(a, (void*) (void*) NULL_POINTER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    set_array_elements(a, (void*) (void*) &COMMERCIAL_AT_UNICODE_CHARACTER_CODE_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // The result values.
    char** r0 = (char**) NULL_POINTER_MEMORY_MODEL;
    int** r1 = (int**) NULL_POINTER_MEMORY_MODEL;
    void** r2 = (void**) NULL_POINTER_MEMORY_MODEL;
    void* r3 = *NULL_POINTER_MEMORY_MODEL;
    char** r4 = (char**) NULL_POINTER_MEMORY_MODEL;

    get_array_elements((void*) &r0, a, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    get_array_elements((void*) &r1, a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    get_array_elements((void*) &r2, a, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    get_array_elements((void*) &r3, a, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    get_array_elements((void*) &r4, a, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"Result pointer as string r0: %s\n", *r0);
    fwprintf(stdout, L"Result pointer as integer r1: %i\n", **r1);
    fwprintf(stdout, L"Result pointer as pointer r2: %i\n", *r2);
    fwprintf(stdout, L"Result pointer as simple pointer r3: %i\n", r3);
    fwprintf(stdout, L"Result pointer as character r4: %c\n", **r4);

    fwprintf(stdout, L"NULL_POINTER_MEMORY_MODEL: %i \n", NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"*NULL_POINTER_MEMORY_MODEL: %i \n", *NULL_POINTER_MEMORY_MODEL);

    deallocate_array((void*) &a, (void*) &as, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the pointer addition.
 *
 * CAUTION! The following two lines calculate DIFFERENT results!
 * void* b = (void*) (m + (*NUMBER_0_INTEGER_MEMORY_MODEL * *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE));
 * void* b = (void*) m + (*NUMBER_0_INTEGER_MEMORY_MODEL * *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
 * The first line is wrong and adds 16 instead of just 4.
 * The problem are the parentheses.
 *
 * The following addition adds 8 instead of just 2.
 * int* m = (int*) *NULL_POINTER_MEMORY_MODEL;
 * allocate((void*) &m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
 * set(m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_10_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
 * int* c = m + 2;
 * should be: = 10 + 2 = 12
 * but it is: = 10 + (2 * sizeof(int)) = 10 + 8 = 18
 */
void test_pointer_addition() {

    log_write_terminated_message((void*) stdout, L"Test pointer addition:\n");

    // Allocate arrays of an arbitrary size.
    void* v = (void*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);
    int* i = (int*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);
    double* d = (double*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);
    char* c = (char*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);
    wchar_t* wc = (wchar_t*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);
    unsigned long* ul = (unsigned long*) malloc(*NUMBER_10_INTEGER_MEMORY_MODEL);

    // Calculate void pointer addresses using various formulas and casts.
    void* v0 = v; // unchanged
    void* v1 = v + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    void* v2 = (void*) v + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    void* v3 = ((void*) v) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    void* v4 = (void*) (v + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 1
    void* v5 = (void*) v + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    void* v6 = ((void*) v) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    void* v7 = (void*) (v + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 1

    fwprintf(stdout, L"void pointer v0: %i\n", v0);
    fwprintf(stdout, L"void pointer v1: %i\n", v1);
    fwprintf(stdout, L"void pointer v2: %i\n", v2);
    fwprintf(stdout, L"void pointer v3: %i\n", v3);
    fwprintf(stdout, L"void pointer v4: %i\n", v4);
    fwprintf(stdout, L"void pointer v5: %i\n", v5);
    fwprintf(stdout, L"void pointer v6: %i\n", v6);
    fwprintf(stdout, L"void pointer v7: %i\n", v7);

    // Calculate int pointer addresses using various formulas and casts.
    int* i0 = i; // unchanged
    int* i1 = i + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    int* i2 = (int*) i + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    int* i3 = ((int*) i) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    int* i4 = (int*) (i + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4
    int* i5 = (void*) i + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    int* i6 = ((void*) i) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    int* i7 = (void*) (i + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4

    fwprintf(stdout, L"int pointer i0: %i\n", i0);
    fwprintf(stdout, L"int pointer i1: %i\n", i1);
    fwprintf(stdout, L"int pointer i2: %i\n", i2);
    fwprintf(stdout, L"int pointer i3: %i\n", i3);
    fwprintf(stdout, L"int pointer i4: %i\n", i4);
    fwprintf(stdout, L"int pointer i5: %i\n", i5);
    fwprintf(stdout, L"int pointer i6: %i\n", i6);
    fwprintf(stdout, L"int pointer i7: %i\n", i7);

    // Calculate double pointer addresses using various formulas and casts.
    double* d0 = d; // unchanged
    double* d1 = d + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 8
    double* d2 = (double*) d + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 8
    double* d3 = ((double*) d) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 8
    double* d4 = (double*) (d + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 8
    double* d5 = (void*) d + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    double* d6 = ((void*) d) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    double* d7 = (void*) (d + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 8

    fwprintf(stdout, L"double pointer d0: %i\n", d0);
    fwprintf(stdout, L"double pointer d1: %i\n", d1);
    fwprintf(stdout, L"double pointer d2: %i\n", d2);
    fwprintf(stdout, L"double pointer d3: %i\n", d3);
    fwprintf(stdout, L"double pointer d4: %i\n", d4);
    fwprintf(stdout, L"double pointer d5: %i\n", d5);
    fwprintf(stdout, L"double pointer d6: %i\n", d6);
    fwprintf(stdout, L"double pointer d7: %i\n", d7);

    // Calculate char pointer addresses using various formulas and casts.
    char* c0 = c; // unchanged
    char* c1 = c + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    char* c2 = (char*) c + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    char* c3 = ((char*) c) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    char* c4 = (char*) (c + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 1
    char* c5 = (void*) c + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    char* c6 = ((void*) c) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    char* c7 = (void*) (c + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 1

    fwprintf(stdout, L"char pointer c0: %i\n", c0);
    fwprintf(stdout, L"char pointer c1: %i\n", c1);
    fwprintf(stdout, L"char pointer c2: %i\n", c2);
    fwprintf(stdout, L"char pointer c3: %i\n", c3);
    fwprintf(stdout, L"char pointer c4: %i\n", c4);
    fwprintf(stdout, L"char pointer c5: %i\n", c5);
    fwprintf(stdout, L"char pointer c6: %i\n", c6);
    fwprintf(stdout, L"char pointer c7: %i\n", c7);

    // Calculate wchar_t pointer addresses using various formulas and casts.
    wchar_t* wc0 = wc; // unchanged
    wchar_t* wc1 = wc + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    wchar_t* wc2 = (wchar_t*) wc + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    wchar_t* wc3 = ((wchar_t*) wc) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    wchar_t* wc4 = (wchar_t*) (wc + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4
    wchar_t* wc5 = (void*) wc + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    wchar_t* wc6 = ((void*) wc) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    wchar_t* wc7 = (void*) (wc + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4

    fwprintf(stdout, L"wchar_t pointer wc0: %i\n", wc0);
    fwprintf(stdout, L"wchar_t pointer wc1: %i\n", wc1);
    fwprintf(stdout, L"wchar_t pointer wc2: %i\n", wc2);
    fwprintf(stdout, L"wchar_t pointer wc3: %i\n", wc3);
    fwprintf(stdout, L"wchar_t pointer wc4: %i\n", wc4);
    fwprintf(stdout, L"wchar_t pointer wc5: %i\n", wc5);
    fwprintf(stdout, L"wchar_t pointer wc6: %i\n", wc6);
    fwprintf(stdout, L"wchar_t pointer wc7: %i\n", wc7);

    // Calculate unsigned long pointer addresses using various formulas and casts.
    unsigned long* ul0 = ul; // unchanged
    unsigned long* ul1 = ul + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    unsigned long* ul2 = (unsigned long*) ul + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    unsigned long* ul3 = ((unsigned long*) ul) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 4
    unsigned long* ul4 = (unsigned long*) (ul + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4
    unsigned long* ul5 = (void*) ul + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    unsigned long* ul6 = ((void*) ul) + *NUMBER_1_INTEGER_MEMORY_MODEL; // increased by 1
    unsigned long* ul7 = (void*) (ul + *NUMBER_1_INTEGER_MEMORY_MODEL); // increased by 4

    fwprintf(stdout, L"unsigned long pointer ul0: %i\n", ul0);
    fwprintf(stdout, L"unsigned long pointer ul1: %i\n", ul1);
    fwprintf(stdout, L"unsigned long pointer ul2: %i\n", ul2);
    fwprintf(stdout, L"unsigned long pointer ul3: %i\n", ul3);
    fwprintf(stdout, L"unsigned long pointer ul4: %i\n", ul4);
    fwprintf(stdout, L"unsigned long pointer ul5: %i\n", ul5);
    fwprintf(stdout, L"unsigned long pointer ul6: %i\n", ul6);
    fwprintf(stdout, L"unsigned long pointer ul7: %i\n", ul7);

    // Free arrays.
    free(v);
    free(i);
    free(d);
    free(c);
    free(wc);
    free(ul);
}

/**
 * Tests the pointer handling.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_pointer() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test pointer handling.");

//    test_pointer_null();
//    test_pointer_cast();
    test_pointer_return();

//    test_character_array_with_termination();
//    test_character_array_single_element();
//    test_character_array_multiple_elements();

//    test_integer_array();

//    test_pointer_array();
//    test_pointer_array_with_null_values();

//    test_pointer_addition();
}

/* POINTER_TESTER */
#endif
