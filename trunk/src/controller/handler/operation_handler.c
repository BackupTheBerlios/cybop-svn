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
 * @version $RCSfile: operation_handler.c,v $ $Revision: 1.50 $ $Date: 2008-12-31 00:14:56 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../../applicator/calculator.c"
#include "../../applicator/communicator.c"
#include "../../applicator/comparator.c"
#include "../../applicator/guider.c"
#include "../../applicator/maintainer.c"
#include "../../applicator/memoriser.c"
#include "../../applicator/runner.c"
#include "../../constant/model/cybol/operation_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../controller/handler/operation/communication_operation_handler.c"
#include "../../controller/handler/operation/lifecycle_operation_handler.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Handles the operation signal.
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
 */
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL_COUNT);

    fwprintf(stdout, L"TEST handle operation: %ls\n", (wchar_t*) p10);
    fwprintf(stdout, L"TEST handle operation count: %i\n", *((int*) p11));
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, p10);
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) ARITHMETIC_OPERATION_CYBOL_MODEL, (void*) ARITHMETIC_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            calculate(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) BIT_OPERATION_CYBOL_MODEL, (void*) BIT_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            calculate(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) BOOLEAN_OPERATION_CYBOL_MODEL, (void*) BOOLEAN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            calculate(p12, p13, p1, p2, p3);
        }
    }

/*??
    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            communicate(p12, p13, p1, p2, p3, p0);
        }
    }
*/

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_communication_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, (void*) &r);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) COMPARISON_OPERATION_CYBOL_MODEL, (void*) COMPARISON_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) FLOW_OPERATION_CYBOL_MODEL, (void*) FLOW_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            guide(p12, p13, p1, p2, p3, p0);
        }
    }

/*??
    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) LIFECYCLE_OPERATION_CYBOL_MODEL, (void*) LIFECYCLE_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain(p12, p13, p1, p2, p3, p0, p7);
        }
    }
*/

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_lifecycle_operation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, (void*) &r);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) MEMORY_OPERATION_CYBOL_MODEL, (void*) MEMORY_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            memorise(p12, p13, p1, p2, p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(p10, p11, (void*) RUN_OPERATION_CYBOL_MODEL, (void*) RUN_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            run(p12, p13, p1, p2, p3);
        }
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
