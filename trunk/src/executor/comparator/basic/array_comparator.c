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

#ifndef ARRAY_COMPARATOR_SOURCE
#define ARRAY_COMPARATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/basic/value_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares count elements of the left- and right array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the count
 */
void compare_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* c = (int*) p5;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare array elements.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
        // The value comparison result.
        int vr = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (j >= *c) {

                // All elements have been compared successfully.
                // The comparison of all element pairs delivered "true".
                //
                // CAUTION! The arrays are expected to be EQUAL, even if
                // the count is zero. This is important, because the DETAILS
                // (meta properties) of many otherwise equal models are empty.
                copy_integer(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

                break;
            }

            // Reset value comparison result.
            vr = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // CAUTION! This function does not change the result flag, if unequal.
            // Therefore, the result flag ALWAYS has to be initialised with zero before!
            compare_value_offset((void*) &vr, p1, p2, p3, p4, (void*) &j);

            if (vr == *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // Stop comparison if two elements do not match the
                // criteria, i.e. the comparison delivered "false".
                // Because then, the comparison of the two arrays is "false".
                // The final comparison result r is left as is,
                // since it was not touched.
                break;
            }

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array elements. The count is null.");
    }
}

/**
 * Compares left and right array, starting from the given offset.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 */
void compare_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if one or both of the two arrays are null!
    // All other copying functions are based on this copier function,
    // so that checking for null pointer right here suffices.

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare array.");

            // The left array, right array.
            // CAUTION! They HAVE TO BE initialised with p1 and p2,
            // since an offset is added below.
            void* l = p1;
            void* r = p2;

            // Add offset.
            add_offset((void*) &l, p4, p6);
            add_offset((void*) &r, p4, p7);

            compare_array_elements(p0, l, r, p3, p4, p5);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The left array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare array. The right array is null.");
    }
}

/* ARRAY_COMPARATOR_SOURCE */
#endif
