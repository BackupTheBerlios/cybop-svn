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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_NAME_GETTER_SOURCE
#define PART_NAME_GETTER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/http/cyboi_http_name.c"
#include "../../../executor/accessor/appender/part_appender.c"
#include "../../../executor/comparator/all/part_all_comparator.c"
#include "../../../executor/converter/selector/http_request/method_http_request_selector.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part by name array, from the given whole part.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the part name array
 * @param p3 the part name array count
 * @param p4 the destination part element index
 */
void get_name_part_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get name part element.");

    // The source whole item.
    void* s = *NULL_POINTER_MEMORY_MODEL;

    // Get source whole item.
    copy_array_forward((void*) &s, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p4);

    // Get destination part with given name from source whole data item.
    get_name_item_element(p0, s, p2, p3);
}

/**
 * Gets the knowledge part by name part, from the given whole part.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the part name part
 */
void get_name_part(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get name part.");

    // The source whole part.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The part name part.
    void* n = *NULL_POINTER_MEMORY_MODEL;

    // Get source whole part.
    copy_array_forward((void*) &s, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get part name part.
    copy_array_forward((void*) &n, p2, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);

    // Get destination part with given name from source whole data item.
    get_name_item(p0, s, n);
}

/* PART_NAME_GETTER_SOURCE */
#endif
