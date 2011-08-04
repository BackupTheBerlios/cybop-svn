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
 * @version $RCSfile: accessor.c,v $ $Revision: 1.24 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_REMOVER_SOURCE
#define ITEM_REMOVER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/memory_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/modifier/remover/array_remover.c"
#include "../../../logger/logger.c"

/**
 * Removes count elements from the item.
 *
 * The count and size are adjusted automatically.
 *
 * @param p0 the item
 * @param p1 the abstraction
 * @param p2 the count
 * @param p3 the index
 */
void remove_item(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Remove item.");

    // The item data, count, size.
    void* d = *NULL_POINTER_MEMORY_MODEL;
    void* c = *NULL_POINTER_MEMORY_MODEL;
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // Get item data, count, size.
    copy_array_forward((void*) &d, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &c, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &s, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIZE_ITEM_MEMORY_NAME);

    // Remove elements from item data.
    // The count and size are adjusted inside.
    remove_array((void*) &d, p1, p2, p3, c, s);

    // Set data as item element.
    // CAUTION! This IS NECESSARY, because reallocation may have happened
    // above which would return a completely new data array (memory area).
    // CAUTION! It is NOT necessary to also set count and size,
    // since only their references were used above to modify values.
    copy_array_forward(p0, (void*) &d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DATA_ITEM_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/* ITEM_REMOVER_SOURCE */
#endif
