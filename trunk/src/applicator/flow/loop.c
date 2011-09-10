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
 * @version $RCSfile: loop_guider.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/flow/loop_flow_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Loops the programme flow endlessly, until the break flag is set.
 *
 * Expected parametres:
 * - model (required): the knowledge model to be executed repeatedly by the loop
 * - break (required): the break flag; once set, the loop will be left (exited)
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 * @param p4 the signal memory item
 * @param p5 the signal memory interrupt request flag
 * @param p6 the signal memory mutex
 * @param p7 the shutdown flag
 */
void apply_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply loop.");

    // The model part.
    void* m = *NULL_POINTER_MEMORY_MODEL;
    // The break part.
    void* b = *NULL_POINTER_MEMORY_MODEL;
    // The break part model.
    void* bm = *NULL_POINTER_MEMORY_MODEL;
    // The break part model data.
    void* bmd = *NULL_POINTER_MEMORY_MODEL;

    // Get model part.
    get_name_array((void*) &m, p0, (void*) MODEL_LOOP_FLOW_OPERATION_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get break part.
    get_name_array((void*) &b, p0, (void*) BREAK_LOOP_FLOW_OPERATION_CYBOL_NAME, (void*) BREAK_LOOP_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get break part model.
    copy_array_forward((void*) &bm, b, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get break part model data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;
    // The direct execution flag.
    // CAUTION! The flag has to be set to true, because otherwise,
    // each loop cycle places a new signal in signal memory so that
    // these would only be processed with a delay.
    // But this is not desirable, since follow-up signals of this
    // loop may rely on its full execution, including all cycles.
    int x = *TRUE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        // Check if break flag is set to true.
        compare_integer_unequal((void*) &b, bmd, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Leave the loop if the break flag is true.
            break;

        } else {

            // Handle the model as new operation,
            // as long as the break flag is false (not set).
            handle(m, (void*) &x, p7, p2, p3, p4, p5, p6);
        }
    }
}

/* LOOP_SOURCE */
#endif
