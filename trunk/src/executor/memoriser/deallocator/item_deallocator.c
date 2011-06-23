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
 * @version $RCSfile: model_allocator.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_DEALLOCATOR_SOURCE
#define ITEM_DEALLOCATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the item.
 *
 * @param p0 the item (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void deallocate_item(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** i = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate item.");

        // The data, count, size.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* c = *NULL_POINTER_MEMORY_MODEL;
        void* s = *NULL_POINTER_MEMORY_MODEL;

        // Get data, count, size.
/*??
        get_array_offset((void*) &d, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        get_array_offset((void*) &c, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COUNT_ITEM_MEMORY_NAME);
        get_array_offset((void*) &s, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) SIZE_ITEM_MEMORY_NAME);
*/
        set_array_offset((void*) &d, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        set_array_offset((void*) &c, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COUNT_ITEM_MEMORY_NAME);
        set_array_offset((void*) &s, *i, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) SIZE_ITEM_MEMORY_NAME);

        // Deallocate data, count, size.
        deallocate_array((void*) &d, p1, p2);
        deallocate_array((void*) &c, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Deallocate item.
        deallocate_array(p0, (void*) ITEM_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate item. The item is null.");
    }
}

/* ITEM_DEALLOCATOR_SOURCE */
#endif
