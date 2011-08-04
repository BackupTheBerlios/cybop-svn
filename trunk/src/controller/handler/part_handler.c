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
 * @version $RCSfile: compound_handler.c,v $ $Revision: 1.34 $ $Date: 2009-01-31 16:31:28 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_HANDLER_SOURCE
#define PART_HANDLER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Handles the part (compound) signal element.
 *
 * @param p0 the signal model array (operation)
 * @param p1 the signal model array (operation) index
 * @param p2 the signal details array (parametres)
 * @param p3 the signal details array (parametres) count
 * @param p4 the direct execution flag
 * @param p5 the shutdown flag
 * @param p6 the knowledge memory part
 * @param p7 the internal memory array
 * @param p8 the signal memory item
 * @param p9 the signal memory interrupt request flag
 * @param p10 the signal memory mutex
 */
void handle_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle part signal element.");

    // The signal part (child element of the signal model pointer array).
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get signal part.
    copy_array_forward((void*) &s, p0, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1);
    // Evaluate direct execution flag.
    compare_integer((void*) &r, p4, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The signal is to be executed DIRECTLY,
        // i.e. by calling the corresponding function,
        // WITHOUT adding it to the signal memory.

        // Handle signal.
        handle(s, p4, p5, p6, p7, p8, p9, p10);

    } else {

        // The signal is to be executed INDIRECTLY,
        // i.e. by adding it to the signal memory,
        // where it later gets checked and handled.
        // This may be useful for REAL TIME SYSTEMS,
        // where a fast system response time is guaranteed.
        //
        // Example:
        // When a big algorithm takes very long to be processed,
        // then it is better to let its parts be executed
        // as separate signals. That way, other signals
        // waiting in the signal memory have the chance
        // to be processed in between, in order to fulfil
        // the response time requirement.

        // Lock signal memory mutex.
        pthread_mutex_lock(p10);

        // Add part model (signal) to signal memory.
        append_item_element(p8, (void*) &s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        // Set interrupt request flag, in order to notify the signal checker
        // that a new signal has been placed in the signal memory.
        copy_integer(p9, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(p10);
    }
}

/**
 * Handles the part (compound) signal.
 *
 * @param p0 the signal model array (operation)
 * @param p1 the signal model array (operation) count
 * @param p2 the signal details array (parametres)
 * @param p3 the signal details array (parametres) count
 * @param p4 the direct execution flag
 * @param p5 the shutdown flag
 * @param p6 the knowledge memory part
 * @param p7 the internal memory array
 * @param p8 the signal memory item
 * @param p9 the signal memory interrupt request flag
 * @param p10 the signal memory mutex
 */
void handle_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* mc = (int*) p1;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
        log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_PART_MESSAGE_LOG_MODEL, (void*) HANDLE_PART_MESSAGE_LOG_MODEL_COUNT);

        // The loop variable.
        int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

fwprintf(stdout, L"TEST handle part *mc: %i\n", *mc);

        while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

            if (j >= *mc) {

                break;
            }

fwprintf(stdout, L"TEST handle part j: %i\n", j);

            handle_part_element(p0, (void*) &j, p2, p3, p4, p5, p6, p7, p8, p9, p10);

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle part. The signal model array count is null.");
    }
}

/* PART_HANDLER_SOURCE */
#endif
