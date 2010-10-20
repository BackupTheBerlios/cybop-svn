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

#ifndef ACCESSOR_TESTER
#define ACCESSOR_TESTER

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

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
    // The wide character abstraction (type) size.
    int ws = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Determine size.
    determine_size((void*) &cs, (void*) CHARACTER_MEMORY_ABSTRACTION);
    determine_size((void*) &ds, (void*) DOUBLE_MEMORY_ABSTRACTION);
    determine_size((void*) &is, (void*) INTEGER_MEMORY_ABSTRACTION);
    determine_size((void*) &ps, (void*) POINTER_MEMORY_ABSTRACTION);
    determine_size((void*) &ws, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"Type size character: %i\n", cs);
    fwprintf(stdout, L"Type size double: %i\n", ds);
    fwprintf(stdout, L"Type size integer: %i\n", is);
    fwprintf(stdout, L"Type size pointer: %i\n", ps);
    fwprintf(stdout, L"Type size wide character: %i\n", ws);
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
    assign((void*) &d, (void*) &v, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) DOUBLE_MEMORY_ABSTRACTION);
    fwprintf(stdout, L"Double after assigner: %f\n", d);
}

/**
 * Tests the accessor array setter.
 */
void test_accessor_array_setter() {
}

/**
 * Tests the accessor.
 */
void test_accessor() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test accessor.");

    test_accessor_size_determiner();
    test_accessor_assigner();
    test_accessor_array_setter();
}

/* ACCESSOR_TESTER */
#endif
