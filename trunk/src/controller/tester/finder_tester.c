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

#ifndef FINDER_TESTER
#define FINDER_TESTER

#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/searcher/finder/array_finder.c"
#include "../../executor/searcher/finder/item_finder.c"
#include "../../executor/searcher/finder/part_finder.c"
#include "../../executor/searcher/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Tests the part by name finder.
 */
void test_finder_part_by_name() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test finder part by name.");

    //
    // Declare parts.
    //

    void* w = *NULL_POINTER_MEMORY_MODEL;
    void* p1 = *NULL_POINTER_MEMORY_MODEL;
    void* p2 = *NULL_POINTER_MEMORY_MODEL;
    void* p3 = *NULL_POINTER_MEMORY_MODEL;

    //
    // Allocate parts.
    //

    allocate_part_NEW((void*) &w, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    allocate_part_NEW((void*) &p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    //
    // Initialise parts.
    //

    // Fill whole.
    overwrite_part_element(w, (void*) L"whole", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_5_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(w, (void*) PART_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    // Fill part one.
    overwrite_part_element(p1, (void*) L"part_one", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_8_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p1, (void*) L"This is", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_7_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part two.
    overwrite_part_element(p2, (void*) L"part_two", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_8_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p2, (void*) L"some arbitrary", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_14_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Fill part three.
    overwrite_part_element(p3, (void*) L"part_three", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_10_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p3, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p3, (void*) L"text content.", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Assign parts to whole one.
    //
    // CAUTION! Hand over reference of p1, p2, p3!
    //
    // CAUTION! Do NOT use the "overwrite_part" or "insert_part" function here,
    // since (void*) &p1 is treated as pointer ARRAY and thus requires one of
    // the two functions "overwrite_part_element" or "insert_part_element"!
    //

    overwrite_part_element(w, (void*) &p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    overwrite_part_element(w, (void*) &p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    overwrite_part_element(w, (void*) &p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_2_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    //
    // Find a part by name in the whole.
    //

    // The found part.
    void* f = *NULL_POINTER_MEMORY_MODEL;

    // Find part by name.
    get_knowledge_part_by_name((void*) &f, w, (void*) L"part_two", (void*) NUMBER_8_INTEGER_MEMORY_MODEL, (void*) NUMBER_3_INTEGER_MEMORY_MODEL);

    //
    // Output test results.
    //

    fwprintf(stdout, L"TEST f: %i\n", f);

    // The part elements retrieved as reference.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;

    // Get part elements.
    copy_array_forward((void*) &n, f, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &a, f, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    copy_array_forward((void*) &m, f, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &d, f, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

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

    //
    // Deallocate parts.
    //

    deallocate_part_NEW((void*) &p1, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    deallocate_part_NEW((void*) &w, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the array finder.
 */
void test_finder_array() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test finder array.");

    // The index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Two equal strings.
    i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    find_array((void*) &i, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_13_INTEGER_MEMORY_MODEL, (void*) NUMBER_13_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST equal: %i\n", i);

    // The hierarchy separator . (dot) in a knowledge path.
    i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    find_array((void*) &i, (void*) L"resmedicinae.gui.menu#background", (void*) L".", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_32_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST .: %i\n", i);

    // The meta character # (number sign) in a knowledge path.
    i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    find_array((void*) &i, (void*) L"resmedicinae.gui.menu#background", (void*) L"#", (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_32_INTEGER_MEMORY_MODEL, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    fwprintf(stdout, L"TEST #: %i\n", i);
}

/**
 * Tests the finder.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_finder() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test finder.");

    test_finder_part_by_name();
//    test_finder_array();
}

/* FINDER_TESTER */
#endif
