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

#ifndef COMPARATOR_TESTER
#define COMPARATOR_TESTER

#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/comparator/prefix/array_prefix_comparator.c"
#include "../../executor/comparator/subsequence/array_subsequence_comparator.c"
#include "../../executor/comparator/suffix/array_suffix_comparator.c"
#include "../../logger/logger.c"

/**
 * Tests the ascii character - wide character equality.
 */
void test_comparator_ascii_character() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator ascii character.");

    char test = 'a';

    if (test = *LATIN_SMALL_LETTER_A_UNICODE_CHARACTER_CODE_MODEL) {

        log_write_terminated_message((void*) stdout, L"Characters ARE equal.\n");

    } else {

        log_write_terminated_message((void*) stdout, L"Characters are NOT equal.\n");
    }
}

/**
 * Tests the comparator all comparison.
 */
void test_comparator_all() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator all.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

/*??
    // The wide character array.
    void* w = *NULL_POINTER_MEMORY_MODEL;
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;
    allocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

    // All.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_all_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_13_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST all true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_all_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello World!", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_12_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST all false r: %i\n", r);

    // Prefix.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_prefix_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hell", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_4_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST prefix true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_prefix_array((void*) &r, (void*) L"Hello, World!", (void*) L"ello", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_4_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST prefix false r: %i\n", r);

    // Suffix.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_suffix_array((void*) &r, (void*) L"Hello, World!", (void*) L"World!", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_6_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST suffix true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_suffix_array((void*) &r, (void*) L"Hello, World!", (void*) L"World", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_5_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST suffix false r: %i\n", r);

    // Subsequence.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o, Wor", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_6_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"blubla", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_6_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence false r: %i\n", r);
}

/**
 * Tests the comparator.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_comparator() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator.");

//    test_comparator_ascii_character();
    test_comparator_all();
}

/* COMPARATOR_TESTER */
#endif
