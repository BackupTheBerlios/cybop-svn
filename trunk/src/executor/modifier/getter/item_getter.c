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

#ifndef ITEM_GETTER_SOURCE
#define ITEM_GETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/memoriser/reallocator/item_reallocator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Gets the source item element given by the source item element index
 * as reference copied to the destination pointer array.
 *
 * CAUTION! The parametre p0 does NOT have to be a reference!
 * It points to a memory area to which the source element is copied.
 * If using a local variable, then the memory area is allocated
 * automatically by the function, on the stack.
 * Of course, if a pointer is to be retrieved,
 * then parametre p0 has to be a reference.
 *
 * Example:
 *
 * void* item_reference = *NULL_POINTER_MEMORY_MODEL;
 * get_item_element((void*) &item_reference, whole_item, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j, (void*) DATA_ITEM_MEMORY_NAME);
 *
 * @param p0 the destination array (if source index is inside of source count boundary; unchanged otherwise)
 * @param p1 the source item
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination array index
 * @param p5 the source item index
 * @param p6 the source item element index
 */
void get_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get item element.");

    // CAUTION! Do NOT simplify the lines below to one line like:
    // copy_array_forward(p0, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);
    // If doing this, the parametres abstraction, count, index etc.
    // will not be considered.

    // The source item element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get source item element.
    //
    // CAUTION! It is NOT necessary to use the "overwrite" function here,
    // since the destination handed over as parametre is a pointer
    // with a fixed size of one which does not have to be changed.
    // Only a simple reference (pointer) of size one is copied here.
    // Using the "copy_array_forward" function is more efficient.
    copy_array_forward((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_integer((void*) &r, p6, (void*) DATA_ITEM_MEMORY_NAME, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // This is a data item element.

        // The count is only needed if the item element is "data".
        void* c = *NULL_POINTER_MEMORY_MODEL;

        // Get destination item element count.
        copy_array_forward((void*) &c, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

        // Reset comparison result.
        copy_integer((void*) &r, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        // CAUTION! The data item element's count HAS TO BE GREATER
        // than the given source index. Otherwise, array boundaries
        // might get crossed and false pointer values returned.
        // Therefore, this is checked here.
        compare_integer((void*) &r, c, p5, (void*) GREATER_PRIMITIVE_OPERATION_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Get destination array as element of the source item container.
            copy_array_forward(p0, e, p2, p3, p4, p5);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not get item element. The source item count is not greater than the given source index.");
        }

    } else {

        // This is a count or size item element.

        // CAUTION! The count or size do NOT have
        // a count or size themselves. They are just
        // primitive data values with a fixed size of one.
        // Therefore, nothing has to be checked here.

        // Get destination array as element of the source item container.
        copy_array_forward(p0, e, p2, p3, p4, p5);
    }
}

/* ITEM_GETTER_SOURCE */
#endif
