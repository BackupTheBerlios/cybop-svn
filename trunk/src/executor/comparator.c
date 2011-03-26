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

#ifndef COMPARATOR_SOURCE
#define COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../executor/comparator/equal_comparator.c"
#include "../executor/comparator/greater_comparator.c"
#include "../executor/comparator/greater_or_equal_comparator.c"
#include "../executor/comparator/smaller_comparator.c"
#include "../executor/comparator/smaller_or_equal_comparator.c"
#include "../logger/logger.c"

/**
 * Compares two values.
 *
 * @param p0 the result (number 1 if equal; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the abstraction
 * @param p4 the comparison
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare.");

        if (*c == *EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_equal(p0, p1, p2, p3);

        } else if (*c == *SMALLER_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_smaller(p0, p1, p2, p3);

        } else if (*c == *GREATER_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_greater(p0, p1, p2, p3);

        } else if (*c == *SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_smaller_or_equal(p0, p1, p2, p3);

        } else if (*c == *GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

            compare_greater_or_equal(p0, p1, p2, p3);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare. The comparison is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare. The comparison is null.");
    }
}

/* COMPARATOR_SOURCE */
#endif
