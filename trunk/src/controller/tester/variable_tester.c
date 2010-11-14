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

#ifndef VARIABLE_TESTER
#define VARIABLE_TESTER

#include <stdio.h>

#include "../../logger/logger.c"

/**
 * Tests the type sizes.
 */
void test_type_sizes() {

    log_write_terminated_message((void*) stdout, L"Test type sizes:\n");

    fwprintf(stdout, L"null: %i\n", *NULL_POINTER_MEMORY_MODEL);

    fwprintf(stdout, L"char size: %i\n", *CHARACTER_PRIMITIVE_SIZE);
    fwprintf(stdout, L"double size: %i\n", *DOUBLE_PRIMITIVE_SIZE);
    fwprintf(stdout, L"int size: %i\n", *INTEGER_PRIMITIVE_SIZE);
    fwprintf(stdout, L"void* size: %i\n", *POINTER_PRIMITIVE_SIZE);
    fwprintf(stdout, L"unsigned long size: %i\n", *UNSIGNED_LONG_PRIMITIVE_SIZE);
    fwprintf(stdout, L"wchar_t size: %i\n", *WIDE_CHARACTER_PRIMITIVE_SIZE);
}

/**
 * Tests the variable usage.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_variable() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Test variable.");

//    test_type_sizes();
}

/* VARIABLE_TESTER */
#endif
