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

#ifndef SEQUENCE_SOURCE
#define SEQUENCE_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/flow/sequence_flow_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Executes the given programme flow as sequence.
 *
 * Expected parameters:
 * - model (required): the knowledge model to be executed as sequence
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
void apply_sequence(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply sequence.");

    // The model part.
    void* m = *NULL_POINTER_MEMORY_MODEL;

    // Get model part.
    get_name_array((void*) &m, p0, (void*) MODEL_SEQUENCE_FLOW_OPERATION_CYBOL_NAME, (void*) MODEL_SEQUENCE_FLOW_OPERATION_CYBOL_NAME_COUNT, p1);

    // The direct execution flag.
    // CAUTION! The flag has to be set to true, because otherwise,
    // a new signal would be placed in signal memory and only
    // be processed with a delay.
    // But this is not desirable here, since the model sequence
    // is expected to be executed directly.
    // Further, follow-up signals may rely on its full execution.
    //
    // If a model is to be executed as signal, then the
    // cyboi signal sending operation may be used instead.
    int x = *TRUE_BOOLEAN_MEMORY_MODEL;

    // Handle the model as new operation.
    handle(m, (void*) &x, p7, p2, p3, p4, p5, p6);
}

/* SEQUENCE_SOURCE */
#endif
