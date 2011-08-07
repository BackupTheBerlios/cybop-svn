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

#ifndef NAME_PART_GETTER_SOURCE
#define NAME_PART_GETTER_SOURCE

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
 * Gets the knowledge part by name.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the part name array
 * @param p3 the part name array count
 * @param p4 the source whole part element index (one of:
 *           - MODEL_PART_MEMORY_NAME for structural parts
 *           - DETAILS_PART_MEMORY_NAME for meta properties)
 */
void get_part_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get part name.");

    // The source whole part element retrieved as reference.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    // The source whole part element count retrieved as reference.
    void* ec = *NULL_POINTER_MEMORY_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The part retrieved as reference.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p4);
    // Get part element item count retrieved as reference.
    copy_array_forward((void*) &ec, e, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        compare_integer((void*) &b, (void*) &j, ec, (void*) GREATER_OR_EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

        if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            break;
        }

        // Get part with index j from source part (whole, compound).
        get_part_element((void*) &p, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j, p4);

        // Compare current part's name with given part name.
        compare_all_part_element((void*) &r, p, p2, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p3, (void*) NAME_PART_MEMORY_NAME);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // A part with the given name was found.

            // Copy part pointer to result pointer.
            copy_pointer(p0, (void*) &p);

            break;
        }

        // Increment loop variable.
        j++;
    }
}

/* NAME_PART_GETTER_SOURCE */
#endif
