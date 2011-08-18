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
 * @version $RCSfile: assigner.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_COMPARATOR_SOURCE
#define INTEGER_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/smaller_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares the left- with the right integer.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation abstraction
 */
void compare_integer(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare integer.");

        // The comparison result.
        // CAUTION! It is used instead of if-else statements.
        // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_equal(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_greater_or_equal(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *GREATER_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_greater(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *SMALLER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_smaller_or_equal(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *SMALLER_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_smaller(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            if (*a == *UNEQUAL_PRIMITIVE_OPERATION_ABSTRACTION) {

                r = *NUMBER_1_INTEGER_MEMORY_MODEL;

                compare_integer_unequal(p0, p1, p2);
            }
        }

        if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not compare integer. The operation abstraction is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare integer. The operation abstraction is null.");
    }
}

/* INTEGER_COMPARATOR_SOURCE */
#endif
