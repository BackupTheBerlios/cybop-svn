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

#ifndef ARRAY_SUFFIX_COMPARATOR_SOURCE
#define ARRAY_SUFFIX_COMPARATOR_SOURCE

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
 * Compares if the right- is a suffix of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_suffix_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare suffix array.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_integer((void*) &r, p5, p6, (void*) GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The left array index.
        int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Add left array count.
        add_integer((void*) &i, p5, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        // Subtract right array count.
        subtract_integer((void*) &i, p6, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // CAUTION! Hand over RIGHT array count as count,
        // since it is shorter or equal to that of the left array.
        compare_array(p0, p1, p2, p3, p4, p6, (void*) &i, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not compare suffix array. The left array count is smaller than the right array count.");
    }
}

/* ARRAY_SUFFIX_COMPARATOR_SOURCE */
#endif
