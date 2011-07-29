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
#include "../../executor/comparator/all/part_all_comparator.c"
#include "../../executor/comparator/prefix/array_prefix_comparator.c"
#include "../../executor/comparator/subsequence/array_subsequence_comparator.c"
#include "../../executor/comparator/suffix/array_suffix_comparator.c"
#include "../../executor/modifier/inserter/part_inserter.c"
#include "../../executor/modifier/overwriter/part_overwriter.c"
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
 * Tests the array comparator.
 */
void test_comparator_array() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator array.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

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
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_13_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence complete word true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o, Wor", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_6_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence letters middle true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence one letter true r: %i\n", r);
    // The following is a crash test.
    // The right array "o" count is too high (100).
    // But since the counts are compared inside,
    // the array boundaries are not crossed and errors prevented.
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_100_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence count false r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_subsequence_array((void*) &r, (void*) L"Hello, World!", (void*) L"blubla", (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_6_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST subsequence different words false r: %i\n", r);

    // Integer equal, smaller or equal, greater.
    int i1 = *NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;
    int* i2 = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST integer equal false r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST integer smaller or equal true r: %i\n", r);
    r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    compare_all_array((void*) &r, (void*) &i1, (void*) i2, (void*) GREATER_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST integer greater false r: %i\n", r);
}

/**
 * Tests the part comparator.
 */
void test_comparator_part() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test comparator part.");

    // Declare parts.
    void* w1 = *NULL_POINTER_MEMORY_MODEL;
    void* w2 = *NULL_POINTER_MEMORY_MODEL;
    void* w3 = *NULL_POINTER_MEMORY_MODEL;
    void* w4 = *NULL_POINTER_MEMORY_MODEL;
    void* p1 = *NULL_POINTER_MEMORY_MODEL;
    void* p2 = *NULL_POINTER_MEMORY_MODEL;
    void* p3 = *NULL_POINTER_MEMORY_MODEL;
    // Declare comparison results.
    int r1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int r2 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int r3 = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate parts.
    allocate_part_NEW((void*) &w1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &w2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &w3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &w4, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Initialise parts.
    //

    // Fill whole one.
    overwrite_part_element(w1, (void*) L"one", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w1, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill whole two.
    overwrite_part_element(w2, (void*) L"two", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w2, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill whole three.
    overwrite_part_element(w3, (void*) L"three", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w3, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill whole four.
    overwrite_part_element(w4, (void*) L"four", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w4, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) L"Hello, ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) L"World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_6_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part three.
    // CAUTION! This part differs from part two only in its model,
    // which is "World" (WITHOUT exclamation mark) and not "World!"
    overwrite_part_element(p3, (void*) L"bla", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p3, (void*) L"World", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Assign parts to whole one.
    //
    // one | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Set part one at index 0.
    overwrite_part_element(w1, (void*) &p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Insert part two BEFORE part one, at index 0.
    // The part one is moved to index 1 automatically by the "insert_part_element" function.
    insert_part_element(w1, (void*) &p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Copy all parts of whole one into whole two.
    // This is a DEEP COPY.
    //
    // two | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w2, w1, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    //
    // Copy all parts of whole one into whole three.
    // This is a DEEP COPY.
    // Adds a third part to whole three afterwards.
    //
    // three | part
    // bla | wide_character | World!
    // blu | wide_character | Hello,
    // bla | wide_character | World
    //

    // Copy all parts of whole one into whole three.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w3, w1, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    // Insert part three at index 2, so that the
    // whole three contains three parts altogether.
    insert_part_element(w3, (void*) &p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Assign parts to whole four.
    // This is almost identical to the assignment of part one,
    // only that part three is added instead of part two here.
    // Both differ slightly in only one letter of their model.
    //
    // four | part
    // bla | wide_character | World
    // blu | wide_character | Hello,
    //

    // Set part one at index 0.
    overwrite_part_element(w4, (void*) &p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Insert part two BEFORE part one, at index 0.
    // The part one is moved to index 1 automatically by the "insert_part_element" function.
    insert_part_element(w4, (void*) &p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Compare parts:
    // - one and two are equal
    // - one (or two) and three differ in their number of parts
    // - one (or two) and four differ in their model
    //   (wide character array of a contained part)
    //
    compare_all_part((void*) &r1, w1, w2, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
    compare_all_part((void*) &r2, w1, w3, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);
    compare_all_part((void*) &r3, w1, w4, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"TEST r1: %i\n", r1);
    fwprintf(stdout, L"TEST r2: %i\n", r2);
    fwprintf(stdout, L"TEST r3: %i\n", r3);

    //
    // Deallocate parts.
    //

    deallocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w4, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
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
//    test_comparator_array();
//    test_comparator_part();
}

/* COMPARATOR_TESTER */
#endif
