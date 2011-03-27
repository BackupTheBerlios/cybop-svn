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
#include "../constant/abstraction/operation/operation_abstraction.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../executor/comparator/equality_comparator.c"
#include "../executor/comparator/greaterness_comparator.c"
#include "../executor/comparator/greaterness_or_equality_comparator.c"
#include "../executor/comparator/smallerness_comparator.c"
#include "../executor/comparator/smallerness_or_equality_comparator.c"
#include "../logger/logger.c"

/**
 * Compares two models.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model
 * @param p2 the left model count
 * @param p3 the right model
 * @param p4 the right model count
 * @param p5 the operand abstraction
 * @param p6 the operand abstraction count
 * @param p7 the operation abstraction
 * @param p8 the operation abstraction count
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare models.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p7, p8, (void*) EQUAL_OPERATION_ABSTRACTION, (void*) EQUAL_OPERATION_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_equal(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p7, p8, (void*) GREATER_OPERATION_ABSTRACTION, (void*) GREATER_OPERATION_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_greater(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p7, p8, (void*) GREATER_OR_EQUAL_OPERATION_ABSTRACTION, (void*) GREATER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_greater_or_equal(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p7, p8, (void*) SMALLER_OPERATION_ABSTRACTION, (void*) SMALLER_OPERATION_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_smaller(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_array((void*) &r, p7, p8, (void*) SMALLER_OR_EQUAL_OPERATION_ABSTRACTION, (void*) SMALLER_OR_EQUAL_OPERATION_ABSTRACTION_COUNT, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_smaller_or_equal(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare models. The operation abstraction is unknown.");
    }
}

/* COMPARATOR_SOURCE */
#endif
