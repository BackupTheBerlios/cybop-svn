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
#include "../../executor/memoriser/allocator/part_allocator.c"
#include "../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/part_copier.c"
#include "../../executor/modifier/inserter/array_inserter.c"
#include "../../executor/modifier/remover/array_remover.c"
#include "../../logger/logger.c"

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

    test_modifier_array();
}

/* MODIFIER_TESTER */
#endif
