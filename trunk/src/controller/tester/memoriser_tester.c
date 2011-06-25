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

#ifndef MEMORISER_TESTER
#define MEMORISER_TESTER

#include <wchar.h>

#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/item_copier.c"
#include "../../executor/copier/offset_array_copier.c"
#include "../../logger/logger.c"

/**
 * Tests the array resizing.
 */
void test_memoriser_array_resizing() {

    log_write_terminated_message((void*) stdout, L"Test memoriser array resizing:\n");

    // The text.
    wchar_t ta[] = {L't', L'e', L's', L't', L'\n', L'\0'};
    wchar_t* t = ta;
    int* tc = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

    // The original array.
    void* o = *NULL_POINTER_MEMORY_MODEL;
    int oc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int os = *tc;
    // The copied array.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    int cc = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cs = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Allocate original array.
    allocate_array((void*) &o, (void*) &os, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Allocate copied array.
    allocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Fill original array with text.
    replace_array(o, (void*) t, (void*) tc, (void*) &oc, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    oc = oc + *tc;

    // Print original array content.
    log_write_terminated_message((void*) stdout, t);

    // Reallocate copied array.
    os = os + *NUMBER_10_INTEGER_MEMORY_MODEL;
    reallocate_array((void*) &o, (void*) &oc, (void*) &os, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Print original array content.
    log_write_terminated_message((void*) stdout, t);

    // Deallocate original array.
    deallocate_array((void*) &o, (void*) &os, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Deallocate copied array.
    deallocate_array((void*) &c, (void*) &cs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the array, item, compound, part.
 */
void test_memoriser_all() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test memoriser all.");

    // The array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The item.
    void* i = *NULL_POINTER_MEMORY_MODEL;
    // The compound.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;

//    allocate_array((void*) &a, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_item((void*) &i, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
//    allocate_compound_NEW((void*) &c, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
//    allocate_part((void*) &p, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);

    // set + get array (= 2x copy?)
//    copy_array(a, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL);
//    copy_array_offset(a, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
//    fwprintf(stdout, L"TEST array: %ls\n", (wchar_t*) a);

    // set + get item
//    copy_item(a, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    // set + get part

//    deallocate_part((void*) &p, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
//    deallocate_compound_NEW((void*) &c, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_item((void*) &i, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
//    deallocate_array((void*) &a, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the item.
 */
void test_memoriser_item() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test memoriser item.");

    // The item container.
    void* i = *NULL_POINTER_MEMORY_MODEL;

    // Allocate item container.
    allocate_item((void*) &i, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Fill item container.
    copy_item_element(i, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // The item elements retrieved as reference.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // Get item container elements.
    copy_array_offset((void*) &d, i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_offset((void*) &c, i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_offset((void*) &s, i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);

    fwprintf(stdout, L"TEST item data: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"TEST item count: %i\n", *((int*) c));
    fwprintf(stdout, L"TEST item size: %i\n", *((int*) s));

    // Deallocate item container.
    deallocate_item((void*) &i, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the array.
 */
void test_memoriser_array() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test array.");

    // The pointer array.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The wide character array.
    void* w = *NULL_POINTER_MEMORY_MODEL;
    // The integer array.
    void* i = *NULL_POINTER_MEMORY_MODEL;

    allocate_array((void*) &p, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_array((void*) &w, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_array((void*) &i, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    copy_array_offset(w, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_array_offset(i, (void*) NUMBER_10000_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_array_offset(p, &w, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    copy_array_offset(p, &i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_4_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    fwprintf(stdout, L"TEST p: %i\n", p);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);
    fwprintf(stdout, L"TEST i: %i\n", *((int*) i));

    // The wide character array retrieved as reference from the pointer array.
    void* wr = *NULL_POINTER_MEMORY_MODEL;
    // The integer array retrieved as reference from the pointer array.
    void* ir = *NULL_POINTER_MEMORY_MODEL;

    fwprintf(stdout, L"TEST NULL_POINTER_MEMORY_MODEL: %i\n", NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST *NULL_POINTER_MEMORY_MODEL: %i\n", *NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST wr: %i\n", wr);
    fwprintf(stdout, L"TEST ir: %i\n", ir);

    copy_array_offset((void*) &wr, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMBER_2_INTEGER_MEMORY_MODEL);
    copy_array_offset((void*) &ir, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMBER_4_INTEGER_MEMORY_MODEL);

    fwprintf(stdout, L"TEST NULL_POINTER_MEMORY_MODEL: %i\n", NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST *NULL_POINTER_MEMORY_MODEL: %i\n", *NULL_POINTER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST wr: %i\n", wr);
    fwprintf(stdout, L"TEST ir: %i\n", ir);
    fwprintf(stdout, L"TEST *wr: %ls\n", (wchar_t*) wr);
    fwprintf(stdout, L"TEST *ir: %i\n", *((int*) ir));

    deallocate_array((void*) &i, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_array((void*) &w, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_array((void*) &p, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the wide character array.
 */
void test_memoriser_array_wide_character() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test wide character array.");

    // The wide character array.
    void* w = *NULL_POINTER_MEMORY_MODEL;

    allocate_array((void*) &w, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Copy wide characters with zero indices.
    // This is identical to the following simplified function call:
    // copy_array(a, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL);
    copy_array_offset(w, L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different destination index.
    copy_array_offset(w, L"again", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different source index.
    copy_array_offset(w, L"blublablublaHehooblubla", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMBER_12_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    // Copy wide characters with different destination- and source index.
    copy_array_offset(w, L"xxxxxxxxxxxlloxxxxxxx", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_3_INTEGER_MEMORY_MODEL, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) NUMBER_11_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST w: %ls\n", (wchar_t*) w);

    deallocate_array((void*) &w, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the memoriser.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_memoriser() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test memoriser.");

//    test_memoriser_array_resizing();

//    test_memoriser_all();
//    test_memoriser_part();
//    test_memoriser_compound();
    test_memoriser_item();
//    test_memoriser_array();
//    test_memoriser_array_wide_character();
}

/* MEMORISER_TESTER */
#endif
