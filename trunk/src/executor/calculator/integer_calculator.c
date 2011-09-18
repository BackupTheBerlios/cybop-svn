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

#ifndef INTEGER_CALCULATOR_SOURCE
#define INTEGER_CALCULATOR_SOURCE

#include "../../../constant/abstraction/operation/operation_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/integer/add_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/divide_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/multiply_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/subtract_integer_calculator.c"
#include "../../../logger/logger.c"

/**
 * Calculates the integer using the given operation.
 *
 * @param p0 the result
 * @param p1 the operand
 * @param p2 the operation abstraction
 */
void calculate_integer(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate integer.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) ABSOLUTE_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_absolute(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) ADD_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_add(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DIVIDE_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_divide(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) MULTIPLY_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_multiply(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NEGATE_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_negate(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SUBTRACT_OPERATION_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            calculate_integer_subtract(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not calculate integer. The operation abstraction is unknown.");
    }
}

/* INTEGER_CALCULATOR_SOURCE */
#endif
