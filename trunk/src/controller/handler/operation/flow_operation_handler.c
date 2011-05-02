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
 * @version $RCSfile: flow_operation_handler.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FLOW_OPERATION_HANDLER_SOURCE
#define FLOW_OPERATION_HANDLER_SOURCE

#include "../../../applicator/guider/branch_guider.c"
#include "../../../applicator/guider/loop_guider.c"
#include "../../../applicator/guider/sequence_guider.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/cybol/operation/flow_operation_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/wide_character_equal_array_comparator.c"
#include "../../../logger/logger.c"

/**
 * Handles the flow operation signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the model / signal / operation
 * @param p11 the model / signal / operation count
 * @param p12 the details / parameters
 * @param p13 the details / parameters count
 * @param p14 the signal priority (Hand over as reference!)
 * @param p15 the signal identification (Hand over as reference!)
 * @param p16 the comparison result
 */
void handle_flow_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle flow operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character(p16, p10, p11, (void*) BRANCH_FLOW_OPERATION_CYBOL_MODEL, (void*) BRANCH_FLOW_OPERATION_CYBOL_MODEL_COUNT);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            guide_branch(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character(p16, p10, p11, (void*) LOOP_FLOW_OPERATION_CYBOL_MODEL, (void*) LOOP_FLOW_OPERATION_CYBOL_MODEL_COUNT);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            guide_loop(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_array_equal_wide_character(p16, p10, p11, (void*) SEQUENCE_FLOW_OPERATION_CYBOL_MODEL, (void*) SEQUENCE_FLOW_OPERATION_CYBOL_MODEL_COUNT);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            guide_sequence(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p12, p13, p14, p15);
        }
    }
}

/* FLOW_OPERATION_HANDLER_SOURCE */
#endif
