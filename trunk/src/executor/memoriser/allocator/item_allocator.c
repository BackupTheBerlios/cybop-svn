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

#ifndef ITEM_ALLOCATOR_SOURCE
#define ITEM_ALLOCATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../logger/logger.c"

/**
 * Allocates the item.
 *
 * @param p0 the item (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void allocate_item(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** i = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate item.");

        // Allocate item.
        allocate_array(p0, (void*) ITEM_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // The data, count, size.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* c = *NULL_POINTER_MEMORY_MODEL;
        void* s = *NULL_POINTER_MEMORY_MODEL;

        // Allocate data, count, size.
        allocate_array((void*) &d, p1, p2);
        allocate_array((void*) &c, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_array((void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Initialise count, size.
        // The count is set to zero, since the model does not contain any elements yet.
        // The size is set to the value that was handed over as argument.
        // The data does NOT have to be initialised and remains empty.
        copy_array_offset(c, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_offset(s, p1, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        // Set data, count, size.
        copy_array_offset(*i, (void*) &d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DATA_ITEM_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_offset(*i, (void*) &c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) COUNT_ITEM_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_offset(*i, (void*) &s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) SIZE_ITEM_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate item. The item is null.");
    }
}

/* ITEM_ALLOCATOR_SOURCE */
#endif
