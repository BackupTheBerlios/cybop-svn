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
 * @version $RCSfile: comparator.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_EQUALITY_COMPARATOR_SOURCE
#define ELEMENT_EQUALITY_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/arithmetiser/integer_adder.c"
#include "../../executor/comparator/equality/character_equality_comparator.c"
#include "../../executor/comparator/equality/double_equality_comparator.c"
#include "../../executor/comparator/equality/integer_equality_comparator.c"
#include "../../executor/comparator/equality/pointer_equality_comparator.c"
#include "../../executor/comparator/equality/unsigned_long_equality_comparator.c"
#include "../../executor/comparator/equality/wide_character_equality_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares two elements for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left element
 * @param p2 the right element
 * @param p3 the element abstraction
 */
void compare_equal_element(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare elements for equality.");

        if (*a == *CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_character(p0, p1, p2);

        } else if (*a == *DOUBLE_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_double(p0, p1, p2);

        } else if (*a == *INTEGER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_integer(p0, p1, p2);

        } else if (*a == *POINTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_pointer(p0, p1, p2);

        } else if (*a == *UNSIGNED_LONG_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_unsigned_long(p0, p1, p2);

        } else if (*a == *WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION) {

            compare_equal_wide_character(p0, p1, p2);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare elements for equality. The element abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare elements for equality. The element abstraction is null.");
    }
}

/* ELEMENT_EQUALITY_COMPARATOR_SOURCE */
#endif
