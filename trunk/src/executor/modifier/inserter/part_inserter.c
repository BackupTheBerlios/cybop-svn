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

#ifndef PART_INSERTER_SOURCE
#define PART_INSERTER_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/model/memory_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/modifier/inserter/item_inserter.c"
#include "../../../logger/logger.c"

/**
 * Inserts the source array into the destination part element
 * given by the destination part element index.
 *
 * The destination part element may be either of:
 * name, abstraction, model, details.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination part index
 * @param p5 the source array index
 * @param p6 the destination part element index
 */
void insert_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Insert part element.");

    // The destination part element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get destination part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Insert item as element of the part container.
    insert_item_element(e, p1, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Inserts the source into the destination.
 *
 * The name, abstraction and details of the destination
 * remain unchanged. Only the model gets inserted.
 *
 * The count and size are adjusted automatically.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void insert_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Insert part.");

    // The destination model.
    void* dm = *NULL_POINTER_MEMORY_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;

    // Get destination model.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Insert source- into destination part model item.
    insert_item(dm, sm, p2, p3, p4, p5);
}

/* PART_INSERTER_SOURCE */
#endif
