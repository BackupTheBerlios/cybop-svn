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

#ifndef ACCESSOR_TESTER
#define ACCESSOR_TESTER

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Tests the accessor size determiner.
 */
void test_accessor_size_determiner() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test accessor size determiner.");

    // The character abstraction (type) size.
    int cs = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The double abstraction (type) size.
    int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The integer abstraction (type) size.
    int is = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The pointer abstraction (type) size.
    int ps = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The unsigned long abstraction (type) size.
    int uls = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The wide character abstraction (type) size.
    int wcs = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine size.
    determine_size((void*) &cs, (void*) CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
    determine_size((void*) &ds, (void*) DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION);
    determine_size((void*) &is, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    determine_size((void*) &ps, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
    determine_size((void*) &uls, (void*) UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION);
    determine_size((void*) &wcs, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"Type size character: %i\n", cs);
    fwprintf(stdout, L"Type size double: %i\n", ds);
    fwprintf(stdout, L"Type size integer: %i\n", is);
    fwprintf(stdout, L"Type size pointer: %i\n", ps);
    fwprintf(stdout, L"Type size unsigned long: %i\n", uls);
    fwprintf(stdout, L"Type size wide character: %i\n", wcs);
}

/**
 * Tests the accessor assigner.
 */
void test_accessor_assigner() {

    // The double number.
    double d = 2.0;
    // The value to be assigned.
    double v = 3.5;

    fwprintf(stdout, L"Double before assigner: %f\n", d);
//??    assign((void*) &d, (void*) &v, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) DOUBLE_MEMORY_ABSTRACTION);
    fwprintf(stdout, L"Double after assigner: %f\n", d);
}

/**
 * Tests the accessor array setter.
 */
void test_accessor_array_setter() {

    void* d = *NULL_POINTER_MEMORY_MODEL;
    int ds = *NUMBER_100_INTEGER_MEMORY_MODEL;
    wchar_t* s1 = L"Huhu scheene Welt, lass' mal sehen!";
    int s1c = *NUMBER_35_INTEGER_MEMORY_MODEL;
    int i1 = *NUMBER_0_INTEGER_MEMORY_MODEL;
    wchar_t* s2 = L"Erde";
    int s2c = *NUMBER_4_INTEGER_MEMORY_MODEL;
    int i2 = *NUMBER_13_INTEGER_MEMORY_MODEL;

    // Allocate destination array.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"d string: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"s1: %ls\n", s1);
    fwprintf(stdout, L"s1c: %i\n", s1c);
    fwprintf(stdout, L"i1: %i\n", i1);

//??    overwrite_array(d, (void*) s1, (void*) &s1c, (void*) &i1, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"d string 2: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"s2: %ls\n", s2);
    fwprintf(stdout, L"s2c: %i\n", s2c);
    fwprintf(stdout, L"i2: %i\n", i2);

//??    overwrite_array(d, (void*) s2, (void*) &s2c, (void*) &i2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"d string 3: %ls\n", (wchar_t*) d);

    // Deallocate destination array.
    deallocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
}

/**
 * Tests the accessor.
 */
void test_accessor() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test accessor.");

//    test_accessor_size_determiner();
//    test_accessor_assigner();
//    test_accessor_array_setter();
}

/* ACCESSOR_TESTER */
#endif
