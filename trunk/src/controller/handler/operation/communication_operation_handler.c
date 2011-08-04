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
 * @version $RCSfile: communication_operation_handler.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMUNICATION_OPERATION_HANDLER_SOURCE
#define COMMUNICATION_OPERATION_HANDLER_SOURCE

#include "../../../applicator/communicator/receiving_communicator.c"
#include "../../../applicator/communicator/sending_communicator.c"
#include "../../../applicator/communicator/sensing_communicator.c"
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../constant/model/cybol/operation/communication_operation_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Handles the communication operation signal.
 *
 * @param p0 the comparison result
 * @param p1 the signal model array (operation)
 * @param p2 the signal model array (operation) count
 * @param p3 the signal details array (parametres)
 * @param p4 the signal details array (parametres) count
 * @param p5 the knowledge memory part
 * @param p6 the internal memory array
 * @param p7 the signal memory item
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 */
void handle_communication_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        int* r = (int*) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle communication operation.");

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                communicate_receiving(p3, p4, p5, p6);
            }
        }

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                communicate_sending(p3, p4, p5, p6, p7, p8, p9);
            }
        }

        if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

            compare_all_array(p0, p1, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT);

            if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                communicate_sensing(p3, p4, p5, p6);
            }
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not handle lifecycle operation. The comparison result is null.");
    }
}

/* COMMUNICATION_OPERATION_HANDLER_SOURCE */
#endif
