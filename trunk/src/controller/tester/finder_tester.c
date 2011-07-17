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
#include "../../executor/finder/array_finder.c"
#include "../../executor/finder/item_finder.c"
#include "../../executor/finder/part_finder.c"
#include "../../logger/logger.c"

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

    test_finder_array();
}

/* FINDER_TESTER */
#endif
