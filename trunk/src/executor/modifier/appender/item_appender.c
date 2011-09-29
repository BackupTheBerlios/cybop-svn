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

#ifndef ITEM_APPENDER_SOURCE
#define ITEM_APPENDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Appends the source array to the destination item element
 * given by the destination item element index.
 *
 * A destination index is not expected as parametre,
 * since the source is appended at the end.
 *
 * The destination item element index is expected to be "data".
 * It has no sense to append "count" or "size",
 * since these are just integer primitives.
 * Thus, a destination item element index is not expected as parametre.
 *
 * @param p0 the destination item
 * @param p1 the source array
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the source array index
 */
void append_item_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append item element.");

    // The destination item element count.
    void* c = *NULL_POINTER_MEMORY_MODEL;

    // Get destination item element count.
    copy_array_forward((void*) &c, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // Append source array to destination item data array.
    // CAUTION! Use destination item count as destination index.
    // CAUTION! Set adjust flag since destination gets extended by append.
    overwrite_item_element(p0, p1, p2, p3, c, p4, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Overwrites the destination- with the source item.
 *
 * A destination index is not expected as parametre,
 * since the source is appended at the end.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the source index
 */
void append_item(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Append item.");

    // The destination item count.
    void* dc = *NULL_POINTER_MEMORY_MODEL;

    // Get destination item count.
    copy_array_forward((void*) &dc, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // Append source- to destination item data array.
    // CAUTION! Use destination item count as destination index.
    overwrite_item(p0, p1, p2, p3, dc, p4);
}

/* ITEM_APPENDER_SOURCE */
#endif
