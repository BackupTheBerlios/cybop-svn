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

#ifndef BRANCH_PART_GETTER_SOURCE
#define BRANCH_PART_GETTER_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/modifier/getter/hierarchical_part_getter.c"
#include "../../../executor/searcher/selector/knowledge/branch_knowledge_selector.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part branch.
 *
 * It may be "." for a model part or "#" for a meta property.
 *
 * @param p0 the destination part (Hand over as reference!)
 * @param p1 the source whole part
 * @param p2 the hierarchical part name current position (Hand over as reference!)
 * @param p3 the hierarchical part name remaining count
 */
void get_part_branch(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* rem = (int*) p3;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Get part branch.");

        // The part element index indicating the knowledge branch.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        while (*TRUE_BOOLEAN_MEMORY_MODEL) {

            if (*rem <= *NUMBER_0_INTEGER_MEMORY_MODEL) {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get part branch. The remaining count is zero or smaller.");

                break;
            }

            select_knowledge_branch((void*) &i, p2, p3);

            if (i > *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

                // Process the actual part name.
                //
                // CAUTION! The child part's element index is necessary
                // to distinguish between structural part (retrieved from model)
                // and meta property (retrieved from details).
                get_part_hierarchical(p0, p1, p2, p3, (void*) &i);

                break;
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get part branch. The remaining count is null.");
    }
}

/* BRANCH_PART_GETTER_SOURCE */
#endif
