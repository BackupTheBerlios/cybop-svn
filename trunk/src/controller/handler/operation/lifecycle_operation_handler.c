/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: lifecycle_operation_handler.c,v $ $Revision: 1.6 $ $Date: 2009-01-09 00:36:13 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIFECYCLE_OPERATION_HANDLER_SOURCE
#define LIFECYCLE_OPERATION_HANDLER_SOURCE

#include "../../../applicator/maintainer/interrupting_maintainer.c"
#include "../../../applicator/maintainer/shutting_maintainer.c"
#include "../../../applicator/maintainer/starting_maintainer.c"
#include "../../../constant/model/cybol/operation/lifecycle_operation_cybol_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
#include "../../../memoriser/array.c"

/**
 * Handles the lifecycle operation signal.
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
void handle_lifecycle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle lifecycle operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL, (void*) EXIT_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL, (void*) SET_SHUTDOWN_FLAG_MESSAGE_LOG_MODEL_COUNT);

            int* f = (int*) p7;
            *f = *NUMBER_1_INTEGER_MEMORY_MODEL;
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) INTERRUPT_LIFECYCLE_OPERATION_CYBOL_MODEL, (void*) INTERRUPT_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_interrupting(p12, p13, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL, (void*) SHUTDOWN_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_shutting(p12, p13, p1, p2, p3, p0);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL, (void*) STARTUP_LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT, p16, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_starting(p12, p13, p1, p2, p3, p0);
        }
    }
}

/* LIFECYCLE_OPERATION_HANDLER_SOURCE */
#endif
