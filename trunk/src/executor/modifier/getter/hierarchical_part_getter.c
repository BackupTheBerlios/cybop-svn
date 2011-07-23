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

#ifndef HIERARCHICAL_PART_GETTER_SOURCE
#define HIERARCHICAL_PART_GETTER_SOURCE

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
 * Gets the knowledge part by hierarchical name.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the hierarchical part name current position (Hand over as reference!)
 * @param p3 the hierarchical part name remaining count
 * @param p4 the source whole part element index (one of:
 *           - MODEL_PART_MEMORY_NAME for structural parts
 *           - DETAILS_PART_MEMORY_NAME for meta properties)
 */
void get_part_hierarchical(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            void** pos = (void**) p2;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get part hierarchical.");

            // The element.
            void* e = *pos;
            int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The break flag.
            int b = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The child part element index.
            int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get part hierarchical. The remaining count is zero or smaller.");

                    break;
                }

                select_knowledge_part_name((void*) &b, p2, p3, (void*) &i);

                if (b != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                    // Find part by name in whole model or details (depending on part element index p4).
                    get_part_name(p0, p1, e, (void*) &ec, p4);

                    // Call this function recursively, in order to
                    // process the knowledge hierarchy further down.
                    //
                    // CAUTION! The current p0 is the source AND destination!
                    // A part node of the source will be assigned to the destination.
                    //
                    // CAUTION! The child part's element index is necessary
                    // to distinguish between structural part (retrieved from model)
                    // and meta property (retrieved from details).
                    get_part_hierarchical(p0, p0, p2, p3, (void*) &i);

                    break;

                } else {

                    // Increment request method count.
                    ec++;
                }
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get part hierarchical. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get part hierarchical. The remaining count is null.");
    }
}

/* HIERARCHICAL_PART_GETTER_SOURCE */
#endif
