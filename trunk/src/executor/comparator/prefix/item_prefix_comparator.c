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

#ifndef ITEM_PREFIX_COMPARATOR_SOURCE
#define ITEM_PREFIX_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/reallocator/item_reallocator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Compares if the right array is a prefix of the left item.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left item
 * @param p2 the right array
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 * @param p5 the right array count
 * @param p6 the left item element index
 */
void compare_prefix_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare prefix item element.");

    // The left item element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get left item element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_integer((void*) &r, p6, (void*) DATA_ITEM_MEMORY_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // This is a data item element.

        // The left item count.
        // CAUTION! It is only needed because this is a data item element.
        void* c = *NULL_POINTER_MEMORY_MODEL;

        // Get left item count.
        copy_array_forward((void*) &c, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

        // Compare if the right array is a prefix of the left item data array.
        compare_prefix_array(p0, e, p2, p3, p4, c, p5);

    } else {

        // This is a count or size item element.

        // Compare if the right array is a prefix of the left item data array.
        compare_prefix_array(p0, e, p2, p3, p4, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);
    }
}

/**
 * Compares if the right- is a prefix of the left item.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left item
 * @param p2 the right item
 * @param p3 the operation abstraction
 * @param p4 the operand abstraction
 */
void compare_prefix_item(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Compare prefix item.");

    // The left data, count.
    void* ld = *NULL_POINTER_MEMORY_MODEL;
    void* lc = *NULL_POINTER_MEMORY_MODEL;
    // The right data, count.
    void* rd = *NULL_POINTER_MEMORY_MODEL;
    void* rc = *NULL_POINTER_MEMORY_MODEL;

    // Get left data, count.
    copy_array_forward((void*) &ld, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &lc, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get right data, count.
    copy_array_forward((void*) &rd, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &rc, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // Compare if the right- is a prefix of the left item data array.
    compare_prefix_array(p0, ld, rd, p3, p4, lc, rc);
}

/* ITEM_PREFIX_COMPARATOR_SOURCE */
#endif
