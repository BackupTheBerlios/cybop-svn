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

#ifndef MODIFIER_TESTER
#define MODIFIER_TESTER

#include <wchar.h>

#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/copier/part_copier.c"
#include "../../executor/memoriser/allocator/part_allocator.c"
#include "../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../executor/modifier/inserter/array_inserter.c"
#include "../../executor/modifier/overwriter/part_overwriter.c"
#include "../../executor/modifier/remover/array_remover.c"
#include "../../logger/logger.c"

/**
 * Tests part modification on compound part.
 */
void test_modifier_part_compound() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test modifier part compound.");

    //
    // Declare parts.
    //

    void* w1 = *NULL_POINTER_MEMORY_MODEL;
    void* w2 = *NULL_POINTER_MEMORY_MODEL;
    void* w3 = *NULL_POINTER_MEMORY_MODEL;
    void* p1 = *NULL_POINTER_MEMORY_MODEL;
    void* p2 = *NULL_POINTER_MEMORY_MODEL;

    //
    // Allocate parts.
    //

    allocate_part_NEW((void*) &w1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &w2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &w3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Initialise parts.
    //

    // Fill whole one.
    overwrite_part_element(w1, (void*) L"source", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_6_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w1, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill whole two.
    overwrite_part_element(w2, (void*) L"shallow", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w2, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill whole three.
    overwrite_part_element(w3, (void*) L"deep", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w3, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) L"Hello, ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) L"World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_6_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Assign parts to whole one.
    //
    // CAUTION! Hand over reference of p1, p2!
    //
    // CAUTION! Do NOT use the "overwrite_part" or "insert_part" function here,
    // since (void*) &p1 is treated as pointer ARRAY and thus requires one of
    // the two functions "overwrite_part_element" or "insert_part_element"!
    //

    // Set part one at index 0.
    overwrite_part_element(w1, (void*) &p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Insert part two BEFORE part one, at index 0.
    insert_part_element(w1, (void*) &p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Add all pointer references of whole one to whole two.
    //
    // This is a SHALLOW COPY.
    // After copying, the elements of whole two should
    // point to the same parts as whole one.
    //
    // CAUTION! This time, the "overwrite_part" and NOT the "overwrite_part_element"
    // function is used, since a part's content is copied to another part.
    // No array is given.
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
    overwrite_part(w2, w1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    //
    // Copy all parts of whole one into whole three.
    //
    // This is a DEEP COPY.
    // Not the pointer references are copied, but a new part
    // is created for each part read from the source.
    // This function "dives" into the last node of the knowledge hierarchy.
    //
    // The difference to the shallow copy above is that the abstraction
    // PART_PRIMITIVE_MEMORY_ABSTRACTION is given instead of POINTER_PRIMITIVE_MEMORY_ABSTRACTION.
    //

    // Copy all parts of whole one into whole two.
    // CAUTION! Hand over the correct count of elements!
//    overwrite_part(w3, w1, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    //
    // Output whole one as model diagram.
    //

    // The model diagram.
    void* mdi = *NULL_POINTER_MEMORY_MODEL;
    int mdic = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mdis = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The multibyte character stream.
    void* mb = *NULL_POINTER_MEMORY_MODEL;
    int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The file name.
    void* fn = L"TEST_MODIFIER_TESTER_WHOLE_ONE.txt";
    int fnc = *NUMBER_34_INTEGER_MEMORY_MODEL;
    int fns = *NUMBER_35_INTEGER_MEMORY_MODEL;

    // Allocate model diagram.
    allocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate multibyte character stream.
    allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Encode model into model diagram.
    encode_model_diagram_NEW((void*) &mdi, (void*) &mdic, (void*) &mdis, w1);
    // Encode model diagram into multibyte character stream.
    encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, mdi, (void*) &mdic);
    // Write multibyte character stream as message to file system.
    send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);

    // Deallocate model diagram.
    deallocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate multibyte character stream.
    deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Output whole one as model diagram.
    //

    // The model diagram.
    mdi = *NULL_POINTER_MEMORY_MODEL;
    mdic = *NUMBER_0_INTEGER_MEMORY_MODEL;
    mdis = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The multibyte character stream.
    mb = *NULL_POINTER_MEMORY_MODEL;
    mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The file name.
    fn = L"TEST_MODIFIER_TESTER_WHOLE_TWO.txt";
    fnc = *NUMBER_34_INTEGER_MEMORY_MODEL;
    fns = *NUMBER_35_INTEGER_MEMORY_MODEL;

    // Allocate model diagram.
    allocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate multibyte character stream.
    allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Encode model into model diagram.
    encode_model_diagram_NEW((void*) &mdi, (void*) &mdic, (void*) &mdis, w2);
    // Encode model diagram into multibyte character stream.
    encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, mdi, (void*) &mdic);
    // Write multibyte character stream as message to file system.
    send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);

    // Deallocate model diagram.
    deallocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate multibyte character stream.
    deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Output whole one as model diagram.
    //

    // The model diagram.
    mdi = *NULL_POINTER_MEMORY_MODEL;
    mdic = *NUMBER_0_INTEGER_MEMORY_MODEL;
    mdis = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The multibyte character stream.
    mb = *NULL_POINTER_MEMORY_MODEL;
    mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The file name.
    fn = L"TEST_MODIFIER_TESTER_WHOLE_THREE.txt";
    fnc = *NUMBER_36_INTEGER_MEMORY_MODEL;
    fns = *NUMBER_37_INTEGER_MEMORY_MODEL;

    // Allocate model diagram.
    allocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate multibyte character stream.
    allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Encode model into model diagram.
    encode_model_diagram_NEW((void*) &mdi, (void*) &mdic, (void*) &mdis, w3);
    // Encode model diagram into multibyte character stream.
    encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, mdi, (void*) &mdic);
    // Write multibyte character stream as message to file system.
    send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);

    // Deallocate model diagram.
    deallocate_array((void*) &mdi, (void*) &mdis, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate multibyte character stream.
    deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Deallocate parts.
    //

    deallocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests part modification on wide character array.
 */
void test_modifier_part_wide_character() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test modifier part wide character.");

    // The parts.
    void* p1 = *NULL_POINTER_MEMORY_MODEL;
    void* p2 = *NULL_POINTER_MEMORY_MODEL;

    // Allocate parts.
    allocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Fill part one.
    overwrite_part_element(p1, (void*) L"blu", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) L"He, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_10_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"bla", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) L"ABClloXYZ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_9_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Add (model content of) part two to part one.
    //

    insert_part(p1, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_3_INTEGER_MEMORY_MODEL);

    //
    // Output test results.
    //

    // The part elements retrieved as reference.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;

    // Get part elements.
    copy_array_forward((void*) &n, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &a, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &m, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &d, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // The part elements data, count retrieved as reference.
    void* nd = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ad = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* md = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;

    // Get part elements data, count retrieved as reference.
    copy_array_forward((void*) &nd, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ad, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dd, d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    fwprintf(stdout, L"TEST nd: %ls\n", (wchar_t*) nd);
    fwprintf(stdout, L"TEST nc: %i\n", *((int*) nc));
    fwprintf(stdout, L"TEST ad: %ls\n", (wchar_t*) ad);
    fwprintf(stdout, L"TEST ac: %i\n", *((int*) ac));
    fwprintf(stdout, L"TEST md: %ls\n", (wchar_t*) md);
    fwprintf(stdout, L"TEST mc: %i\n", *((int*) mc));
    fwprintf(stdout, L"TEST dd: %i\n", dd);
    fwprintf(stdout, L"TEST dc: %i\n", *((int*) dc));

    // Deallocate parts.
    deallocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests array modification.
 */
void test_modifier_array() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test modifier array.");

    // The wide character array.
    void* w = *NULL_POINTER_MEMORY_MODEL;
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int s = *NUMBER_0_INTEGER_MEMORY_MODEL;

    allocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Append "Hello".
    insert_array((void*) &w, (void*) L"ABCHelloXYZ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) &c, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Append "World!".
    insert_array((void*) &w, (void*) L"World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_6_INTEGER_MEMORY_MODEL, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Remove "llo".
    remove_array((void*) &w, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Insert "ho, ".
    insert_array((void*) &w, (void*) L"ho, ", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    // Append "test" outside, leaving two elements empty.
    // CAUTION! This is NOT shown when printed on screen,
    // since arrays are initialised with the null
    // termination character "\0" by default,
    // so that the "fwprintf" function stops output there.
    insert_array((void*) &w, (void*) L"test", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) NUMBER_20_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &c, (void*) &s);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST c: %i\n", c);
    fwprintf(stdout, L"TEST s: %i\n", s);

    deallocate_array((void*) &w, (void*) &s, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the modifier.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_modifier() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test modifier.");

//    test_modifier_part_compound();
//    test_modifier_part_wide_character();
//    test_modifier_array();
}

/* MODIFIER_TESTER */
#endif
