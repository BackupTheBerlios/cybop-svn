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
//?? #include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../logger/logger.c"

/**
 * Tests the array resizing.
 */
void test_array_resizing() {

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
 * Tests the memoriser allocation.
 */
void test_memoriser_allocation() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test memoriser allocation.");

    // The array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    // The item.
    void* i = *NULL_POINTER_MEMORY_MODEL;
    // The compound.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;

    allocate_array((void*) &a, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_item((void*) &i, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
//    allocate_compound_NEW((void*) &c, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
//    allocate_part((void*) &p, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);

    // set + get (= 2x copy?)

//    deallocate_part((void*) &p, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
//    deallocate_compound_NEW((void*) &c, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);
//??    deallocate_item((void*) &i, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_array((void*) &a, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the memoriser.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_memoriser() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test memoriser.");

//    test_array_resizing();
    test_memoriser_allocation();
}

/* MEMORISER_TESTER */
#endif
