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

#ifndef ARRAY_CALCULATOR_SOURCE
#define ARRAY_CALCULATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/value_comparator.c"
#include "../../../logger/logger.c"

/**
 * Calculates count elements of the result- and operand array.
 *
 * @param p0 the result array, which contains the operands BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation abstraction
 * @param p3 the operand abstraction
 * @param p4 the count
 */
void calculate_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p4;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Calculate array elements.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (j >= *c) {

                break;
            }

            calculate_value_offset(p0, p1, p2, p3, (void*) &j);

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate array elements. The count is null.");
    }
}

/**
 * Calculates count elements of the result- and operand array,
 * starting from the given offset.
 *
 * @param p0 the result array, which contains the operands BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation abstraction
 * @param p3 the operand abstraction
 * @param p4 the count
 * @param p5 the result (operand before operation) index
 * @param p6 the operand index
 */
void calculate_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if one or both of the two arrays are null!
    // All other calculate functions are based on this calculate function,
    // so that checking for null pointer right here suffices.

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Calculate array.");

            // The result array, operand array.
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            void* r = p0;
            void* o = p1;

            // Add offset.
            add_offset((void*) &r, p3, p5);
            add_offset((void*) &o, p3, p6);

            calculate_array_elements(r, o, p2, p3, p4);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate array. The result (operand before operation) array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate array. The operand array is null.");
    }
}

/* ARRAY_CALCULATOR_SOURCE */
#endif
