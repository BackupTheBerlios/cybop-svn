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
 * @version $RCSfile: branch_guider.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCH_SOURCE
#define BRANCH_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/flow/branch_flow_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Branches the programme flow, depending on a flag.
 *
 * Expected parametres:
 * - criterion (required): the flag specifying which of the two models to execute
 * - true (required): the logic knowledge model to be executed if the condition is true
 * - false (required): the logic knowledge model to be executed if the condition is false
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
void apply_branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply branch.");

    // The criterion part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The criterion part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;
    // The criterion part model data.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;
    // The true part.
    void* t = *NULL_POINTER_MEMORY_MODEL;
    // The false part.
    void* f = *NULL_POINTER_MEMORY_MODEL;

    // Get criterion part.
    get_name_array((void*) &c, p0, (void*) CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) CRITERION_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get true part.
    get_name_array((void*) &t, p0, (void*) TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) TRUE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get false part.
    get_name_array((void*) &f, p0, (void*) FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME, (void*) FALSE_BRANCH_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get criterion part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get criterion part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The direct execution flag.
    int x = *TRUE_BOOLEAN_MEMORY_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    compare_integer_equal(&r, cmd, (void*) TRUE_BOOLEAN_MEMORY_MODEL);

    if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // The criterion is true. Handle true model.
        handle(t, (void*) &x, p7, p2, p3, p4, p5, p6);

    } else {

        // The criterion is false. Handle false model.
        handle(f, (void*) &x, p7, p2, p3, p4, p5, p6);
    }
}

/* BRANCH_SOURCE */
#endif
