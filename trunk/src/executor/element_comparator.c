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

#ifndef ELEMENT_COMPARATOR_SOURCE
#define ELEMENT_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../executor/arithmetiser/integer_multiplier.c"
#include "../executor/comparator/equality/primitive_equality_comparator.c"
#include "../logger/logger.c"

/**
 * Compares two elements.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left element
 * @param p2 the right element
 * @param p3 the element abstraction
 * @param p4 the operation abstraction
 */
void compare_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare elements.");

        if (*a == *EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_equal_element(p0, p1, p2, p3);

        } else if (*a == *SMALLER_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_smaller_element(p0, p1, p2, p3);

        } else if (*a == *GREATER_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_greater_element(p0, p1, p2, p3);

        } else if (*a == *SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_smaller_or_equal_element(p0, p1, p2, p3);

        } else if (*a == *GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_greater_or_equal_element(p0, p1, p2, p3);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare primitives for equality. The abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare elements. The operation abstraction is null.");
    }
}

/* ELEMENT_COMPARATOR_SOURCE */
#endif
