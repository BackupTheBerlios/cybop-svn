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

#ifndef ITEM_SETTER_SOURCE
#define ITEM_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/memoriser/reallocator/item_reallocator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/modifier/assigner.c"
#include "../../../logger/logger.c"

/**
 * Sets the array to the item container element.
 *
 * If DATA (not count or size) are set, then the item
 * container count is adjusted automatically.
 *
 * CAUTION! Simply adding the source- to the destination count
 * is not always correct! The source is added to the destination
 * at position index and not always appended at the end,
 * i.e. existing elements may be overwritten as well.
 * Therefore, the COUNT is added to the destination INDEX.
 *
 * An extra number one does NOT have to be added!
 * The index plus count is just right.
 *
 * @param p0 the item container
 * @param p1 the array
 * @param p2 the operand abstraction
 * @param p3 the count
 * @param p4 the item container index
 * @param p5 the array index
 * @param p6 the item container element index
 */
void set_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set item element.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    compare_array_count((void*) &r, p6, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DATA_ITEM_MEMORY_NAME, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // Resize the item container's data element.
        // If a count or size are copied, then the following is NOT executed.

        // The new count.
        int n = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Add item container index.
        add_integer((void*) &n, p4, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Add count (number of elements to be copied).
        // CAUTION! Do NOT use source count here, since not all of the source has to be copied.
        add_integer((void*) &n, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Reallocate item.
        reallocate_item(p0, (void*) &n, p2);

        // Set destination count.
        //
        // CAUTION! Do NOT set the destination size here!
        // It was already set in the "reallocate_item" function.
        //
        // Efficiency:
        // One might think that performance would be better
        // if the size would be enlarged in greater blocks,
        // not one by one.
        // But this IS done here! If many elements are to be copied,
        // then their count (number of elements) is added to the size,
        // so that reallocation is necessary only once,
        // and not for each single element.
        set_item_element(p0, (void*) &n, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    }

    // The item container element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get item container element.
    // CAUTION! Get item container element ONLY AFTER
    // having reallocated the item above!
    // Otherwise, a wrong DATA_ITEM pointer will be returned
    // and cause a "Segmentation fault".
    copy_array_forward((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Copy array to item container element.
    copy_array_forward(e, p1, p2, p3, p4, p5);
}

/* ITEM_SETTER_SOURCE */
#endif
