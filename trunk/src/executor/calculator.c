/*
 * Copyright (C) 1999-2009. Christian Heller.
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
 * @version $RCSfile: calculator.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CALCULATOR_SOURCE
#define CALCULATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Calculates the memory area depending on the given primitive type.
 *
 * @param p0 the area
 * @param p1 the size
 * @param p2 the type
 */
void calculate_area(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate area.");

        if (*t == *CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) CHARACTER_PRIMITIVE_SIZE);

        } else if (*t == *DOUBLE_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) DOUBLE_PRIMITIVE_SIZE);

        } else if (*t == *INTEGER_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) INTEGER_PRIMITIVE_SIZE);

        } else if (*t == *POINTER_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) POINTER_PRIMITIVE_SIZE);

        } else if (*t == *UNSIGNED_LONG_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) UNSIGNED_LONG_PRIMITIVE_SIZE);

        } else if (*t == *WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION) {

            multiply_integer_with_integer(p0, p1, (void*) WIDE_CHARACTER_PRIMITIVE_SIZE);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate area. The type is null.");
    }
}

/* CALCULATOR_SOURCE */
#endif
