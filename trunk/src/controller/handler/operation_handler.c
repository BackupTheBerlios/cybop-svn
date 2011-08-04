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
 * @version $RCSfile: operation_handler.c,v $ $Revision: 1.58 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPERATION_HANDLER_SOURCE
#define OPERATION_HANDLER_SOURCE

#include "../../constant/model/cybol/operation_cybol_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../controller/handler/operation/arithmetic_operation_handler.c"
#include "../../controller/handler/operation/communication_operation_handler.c"
#include "../../controller/handler/operation/comparison_operation_handler.c"
#include "../../controller/handler/operation/file_operation_handler.c"
#include "../../controller/handler/operation/flow_operation_handler.c"
#include "../../controller/handler/operation/lifecycle_operation_handler.c"
#include "../../controller/handler/operation/memory_operation_handler.c"
#include "../../controller/handler/operation/run_operation_handler.c"
#include "../../logger/logger.c"

/**
 * Handles the operation signal.
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
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL, (void*) HANDLE_OPERATION_MESSAGE_LOG_MODEL_COUNT);

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, p0);
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n");

fwprintf(stdout, L"TEST handle operation count: %i\n", *((int*) p1));
fwprintf(stdout, L"TEST handle operation: %ls\n", (wchar_t*) p0);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_arithmetic_operation((void*) &r, p0, p1, p2, p3, p6);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_communication_operation((void*) &r, p0, p1, p2, p3, p5, p6, p7, p8, p9, p10);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_comparison_operation((void*) &r, p0, p1, p2, p3, p6);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_file_operation((void*) &r, p0, p1, p2, p3, p6);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_flow_operation((void*) &r, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_lifecycle_operation((void*) &r, p0, p1, p2, p3, p5, p6, p7);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_memory_operation((void*) &r, p0, p1, p2, p3, p6);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        handle_run_operation((void*) &r, p0, p1, p2, p3, p6);
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, "Could not handle operation. The operation is unknown.");
    }
}

/* OPERATION_HANDLER_SOURCE */
#endif
