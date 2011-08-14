/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef CONVERTER_TESTER
#define CONVERTER_TESTER

#include <stdio.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../executor/memoriser/allocator/model_allocator.c"
#include "../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../logger/logger.c"

/**
 * Tests the integer-to-wide character conversion.
 */
void test_converter_integer_to_wide_character_conversion() {

    log_write_terminated_message((void*) stdout, L"Test integer-to-wide character conversion:\n");

    // The test wide character array.
    void* t = *NULL_POINTER_MEMORY_MODEL;
    int tc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // One byte for the wide character and another for the trailing null.
    size_t ts = *NUMBER_2_INTEGER_MEMORY_MODEL;

    // Allocate test wide character array.
    allocate((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Transform source integer to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
    tc = wsprintfW((wchar_t*) t, L"%i", *NUMBER_5_INTEGER_MEMORY_MODEL);
/* CYGWIN_ENVIRONMENT */
#else
    tc = swprintf((wchar_t*) t, ts, L"%i", *NUMBER_5_INTEGER_MEMORY_MODEL);
/* CYGWIN_ENVIRONMENT */
#endif

    fwprintf(stdout, L"TEST ts: %i\n", ts);
    fwprintf(stdout, L"TEST tc: %i\n", tc);
    fwprintf(stdout, L"TEST t: %ls\n", (wchar_t*) t);

    // Deallocate test wide character array.
    deallocate((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the encode integer function.
 */
void test_converter_encode_integer() {

    log_write_terminated_message((void*) stdout, L"Test encode integer:\n");

    // The destination character array.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;
    void* ds = *NULL_POINTER_MEMORY_MODEL;

    // An arbitrary source integer value.
    int s = *NUMBER_18_INTEGER_MEMORY_MODEL;

    // Allocate destination character array.
    allocate_model((void*) &d, (void*) &dc, (void*) &ds, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer((void*) &d, dc, ds, (void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    fwprintf(stdout, L"Test: Destination character array: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"Test: Destination character array count: %i\n", *((int*) dc));
    fwprintf(stdout, L"Test: Destination character array size: %i\n", *((int*) ds));

    // Deallocate destination character array.
    deallocate_model((void*) &d, (void*) &dc, (void*) &ds, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the decode integer vector function.
 */
void test_converter_decode_integer_vector() {

    log_write_terminated_message((void*) stdout, L"Test decode integer vector:\n");

    // The source character array.
    wchar_t sa[] = {L'1', L',', L'2', L',', L'3', L',', L'4', L',', L'5'};
    void* s = sa;
    int sc = *NUMBER_5_INTEGER_MEMORY_MODEL;

    // The destination integer vector.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate integer vector.
    allocate((void*) &d, (void*) &ds, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    // Decode character array into integer vector.
    decode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    // The integer values.
    int* i0 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* i1 = (int*) *NULL_POINTER_MEMORY_MODEL;
    int* i2 = (int*) *NULL_POINTER_MEMORY_MODEL;

    // Get integer at index 0 from integer vector.
    get((void*) &i0, d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    // Get integer at index 1 from integer vector.
    get((void*) &i1, d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    // Get integer at index 2 from integer vector.
    get((void*) &i2, d, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"Integer 0: %i\n", *i0);
    fwprintf(stdout, L"Integer 1: %i\n", *i1);
    fwprintf(stdout, L"Integer 2: %i\n", *i2);

    // Deallocate integer vector.
    deallocate((void*) &d, (void*) &ds, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the encode integer vector function.
 */
void test_converter_encode_integer_vector() {

    log_write_terminated_message((void*) stdout, L"Test encode integer vector:\n");

    // The source integer array.
    //?? TODO: Shouldn't this be WITHOUT apostrophes, i.e.:
    //?? int sa[] = {1, 2, 3};
    int sa[] = {'1', '2', '3'};
    void* s = sa;
    int sc = *NUMBER_3_INTEGER_MEMORY_MODEL;

    // The destination character array.
    wchar_t* d = (wchar_t*) *NULL_POINTER_MEMORY_MODEL;
    int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate destination character vector.
    allocate((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    fwprintf(stdout, L"Encoded character array: %ls\n", d);
    fwprintf(stdout, L"Encoded character array count: %i\n", dc);
    fwprintf(stdout, L"Encoded character array size: %i\n", ds);

    // Deallocate destination character vector.
    deallocate((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the utf-8 decoding.
 */
void test_converter_decode_utf8() {

    log_write_terminated_message((void*) stdout, L"Test utf-8 decoding:\n");

    wchar_t* f = L"exit/run.cybol";
    int fc = 14;

    // The read model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;
    int rmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int rms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate read model.
    allocate((void*) &rm, (void*) &rms, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Read persistent byte stream over channel.
    receive_data((void*) &rm, (void*) &rmc, (void*) &rms, (void*) f, (void*) &fc, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) FILE_SYSTEM_CYBOL_CHANNEL, (void*) FILE_SYSTEM_CYBOL_CHANNEL_COUNT);

    fwprintf(stdout, L"TEST rms: %i\n", rms);
    fwprintf(stdout, L"TEST rmc: %i\n", rmc);
    fwprintf(stdout, L"TEST rm: %s\n", (wchar_t*) rm);

    // The wide character model.
    void* wm = *NULL_POINTER_MEMORY_MODEL;
    int wmc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int wms = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate wide character model.
    allocate((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, rm, (void*) &rmc);
    //?? TEST only! DELETE LATER!
//??    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, (void*) ASCII_CYBOL_TEXT_CYBOL_ABSTRACTION, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST wm: %ls\n", (wchar_t*) wm);
    fwprintf(stdout, L"TEST wmc: %i\n", wmc);

    // Deallocate read model.
    deallocate((void*) &rm, (void*) &rms, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Deallocate wide character model.
    deallocate((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Tests the converter.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_converter() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test converter.");

//    test_converter_integer_to_wide_character_conversion();

//    test_converter_encode_integer();

//    test_converter_decode_integer_vector();
//    test_converter_encode_integer_vector();

//    test_converter_decode_utf8();
}

/* CONVERTER_TESTER */
#endif
