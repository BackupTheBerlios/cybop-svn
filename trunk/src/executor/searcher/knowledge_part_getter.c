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

#ifndef KNOWLEDGE_PART_GETTER_SOURCE
#define KNOWLEDGE_PART_GETTER_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/http/cyboi_http_name.c"
#include "../../executor/accessor/appender/part_appender.c"
#include "../../executor/converter/selector/http_request/method_http_request_selector.c"
#include "../../executor/memoriser/allocator/model_allocator.c"
#include "../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../logger/logger.c"

/**
 * Gets the knowledge part by name.
 *
 * @param p0 the destination part reference
 * @param p1 the source part
 * @param p2 the source part count
 * @param p3 the part name
 * @param p4 the part name count
 */
void get_knowledge_part_by_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get knowledge part by name.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
/*??
        // The part retrieved as reference.
        void* p = *NULL_POINTER_MEMORY_MODEL;
        // The part name retrieved as reference.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        // The part name data, count retrieved as reference.
        void* nd = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
*/
        // The comparison result.
        int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *sc) {

                break;
            }

            // Compare current part's name with given part name.
            compare_all_part_element((void*) &r, p1, p3, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, (void*) NAME_PART_MEMORY_NAME);
/*??
            // Get part name.
            copy_array_forward((void*) &n, p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            // Get part name data, count retrieved as reference.
            copy_array_forward((void*) &nd, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &nc, n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
            // Compare current part name with given part name.
            compare_all_array((void*) &r, nd, p2, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, nc, p3);
*/

            if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                // A part with the given name was found.

                // Get part with index j from source part (whole, compound, pointer array).
                get_part_element(p0, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j, (void*) MODEL_PART_MEMORY_NAME);

                break;
            }

            // Increment loop variable.
            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get knowledge part. The remaining count is null.");
    }
}

/**
 * Gets the knowledge part.
 *
 * CAUTION! The parametre p0 does NOT have to be a reference!
 * It points to a memory area to which the source element is copied.
 * If using a local variable, then the memory area is allocated
 * automatically by the function, on the stack.
 *
 * Example:
 *
 * void* part_reference = *NULL_POINTER_MEMORY_MODEL;
 * get_part_element((void*) &part_reference, whole_part, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j, (void*) MODEL_PART_MEMORY_NAME);
 *
 * @param p0 the destination array
 * @param p1 the source part
 * @param p2 the abstraction
 * @param p3 the count
 * @param p4 the current position (Hand over as reference!)
 * @param p5 the remaining count
 */
void get_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p7 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p7;

        if (p6 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p6;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get knowledge part.");

            // The element.
            void* e = *pos;
            int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    break;
                }

                select_http_request_method(p0, p1, p2, p3, p4, p5, (void*) &b, p6, p7);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    decode_http_request_method_append_part(p3, p4, p5,
                        (void*) CYBOI_METHOD_HTTP_NAME, (void*) CYBOI_METHOD_HTTP_NAME_COUNT,
                        (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                        e, (void*) &ec, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

                    break;

                } else {

                    // Increment request method count.
                    ec++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get knowledge part. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get knowledge part. The remaining count is null.");
    }
}

/* KNOWLEDGE_PART_GETTER_SOURCE */
#endif
