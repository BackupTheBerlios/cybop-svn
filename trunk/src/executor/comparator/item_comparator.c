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

#ifndef ITEM_COMPARATOR_SOURCE
#define ITEM_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Compares left and right item.
 *
 * The left- and right count ALWAYS have to be EQUAL in order to
 * be able to compare all elements successfully one by one.
 * Even if the comparison operator is not "equals" (==), but
 * something else, e.g. "smaller" (<), both counts have to be equal.
 *
 * Example 1:
 *
 * first item: "blu" (count: 3)
 * second item: "bla" (count: 3)
 * --> comparison is possible and depends on the given operation (operator)
 * --> result parametre might be set to "true" or remain unchanged,
 *     depending on the given operator and actual contained elements
 *
 * Example 2:
 *
 * first item: "blu" (count: 3)
 * second item: "blue" (count: 4)
 * --> comparison is always "false", since the counts are not the same
 * --> result parametre remains unchanged
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left item
 * @param p2 the right item
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 */
void compare_item(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Compare item.");

    // CAUTION! The sizes do NOT have to be identical,
    // since they just represent allocated memory.
    // For comparison, only the actual number of elements is of interest.

    // The left data, count.
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    void* lc = *NULL_POINTER_MEMORY_MODEL;
    // The right data, count.
    void* rd = *NULL_POINTER_MEMORY_MODEL;
    void* rc = *NULL_POINTER_MEMORY_MODEL;

    // Get left data, count.
    get((void*) &ld, p1, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &lc, p1, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get right data, count.
    get((void*) &rd, p2, (void*) DATA_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    get((void*) &rc, p2, (void*) COUNT_ITEM_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // The data, count comparison results.
    int dr = *NUMBER_0_INTEGER_MEMORY_MODEL;
    int cr = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Compare left- with right count.
    // CAUTION! Use the equal operation to compare both counts.
    compare_array((void*) &cr, lc, rc, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    if (cr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Compare left and right data.
        // CAUTION! The right item's count is used here,
        // but the left item's count may be used as well.
        compare_array((void*) &dr, ld, rd, p3, p4, rc);

        if (dr != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Set result to true only if all comparisons have been true.
            set_array(p0, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
        }
    }
}

/* ITEM_COMPARATOR_SOURCE */
#endif
