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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE
#define ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Compares if the elements of the right- are a subsequence of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_subsequence_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare subsequence array elements.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Add left array count.
    add_integer((void*) &c, p5, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Subtract right array count.
    subtract_integer((void*) &c, p6, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
    // Add number one.
    // CAUTION! This IS NECESSARY since otherwise, two arrays with
    // identical length will never be processed as the count is zero then.
    // Problems with the loop variable used as investigated array index
    // will NOT occur, since the loop is left before.
    add_integer((void*) &c, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        compare_integer((void*) &r, p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // The subsequence had been found in the previous loop cycle.
            // The result flag has been set to true.
            // The loop may be left now.

            break;
        }

        if (j >= c) {

            // The maximum loop count has been reached.
            // All elements have been compared.
            // The subsequence could not be found.
            // Leave result flag untouched.

            break;
        }

        // CAUTION! Hand over RIGHT array count as count,
        // since it is shorter or equal to that of the left array.
        // CAUTION! Use loop variable as left array index.
        compare_array(p0, p1, p2, p3, p4, p6, (void*) &j, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        j++;
    }
}

/**
 * Compares if the right- is a subsequence of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_subsequence_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare subsequence array.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_integer((void*) &r, p5, p6, (void*) GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_subsequence_array_elements(p0, p1, p2, p3, p4, p5, p6);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare subsequence array. The left array count is smaller than the right array count.");
    }
}

/* ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE */
#endif
