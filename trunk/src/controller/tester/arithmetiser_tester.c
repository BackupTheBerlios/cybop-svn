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

#ifndef ARITHMETISER_TESTER
#define ARITHMETISER_TESTER

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Tests the arithmetiser integer adder.
 */
void test_arithmetiser_integer_adder() {

    // The integer number.
    int i = *NUMBER_4_INTEGER_MEMORY_MODEL;
    // Some test variable with no meaning, to create a pointer.
    int test = *NUMBER_298_INTEGER_MEMORY_MODEL;
    // The pointer.
    void* p = (void*) &test;
    // The summand integer number.
    int s = *NUMBER_3_INTEGER_MEMORY_MODEL;

    fwprintf(stdout, L"Pointer original: %i\n", p);

    // Add integer to integer.
    add_integer((void*) &i, (void*) &s, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Add integer to pointer.
    add_integer((void*) &p, (void*) &s, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"Integer addition result: %i\n", i);
    fwprintf(stdout, L"Pointer addition result: %i\n", p);
}

/**
 * Tests the arithmetiser multiplicator.
 */
void test_arithmetiser_multiplicator() {

    // The integer number.
    int i = *NUMBER_3_INTEGER_MEMORY_MODEL;
    // The factor integer number.
    int f = *NUMBER_4_INTEGER_MEMORY_MODEL;

    // Multiply integer with integer.
    multiply_with_integer((void*) &i, (void*) &f, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    fwprintf(stdout, L"Multiplication result: %i\n", i);
}

/**
 * Tests the arithmetiser.
 */
void test_arithmetiser() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test arithmetiser.");

    test_arithmetiser_integer_adder();
    test_arithmetiser_multiplicator();
}

/* ARITHMETISER_TESTER */
#endif
