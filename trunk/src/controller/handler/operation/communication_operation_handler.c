/*
 * Copyright (C) 1999-2010. Christian Heller.
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
#include "../../../constant/model/cybol/operation/communication_operation_cybol_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Handles the communication operation signal.
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
void handle_communication_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Handle communication operation.");

    // The comparison result.
    int* r = (int*) p16;

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays(p16, p10, p11, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            communicate_receiving(p12, p13, p0, p1, p2, p3);
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays(p16, p10, p11, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            communicate_sending(p12, p13, p0, p1, p2, p3, p4, p5, p6, p15);

            //?? TEST: For testing reasons, the p15 was replaced with *((int**) p15) here!
            //?? The signal id serves as client socket to which this cyboi system has to reply.
//??            send_message(p12, p13, p0, p1, p2, p3, p4, p5, p6, *((int**) p15));
        }
    }

    if (*r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays(p16, p10, p11, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (*r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            communicate_sensing(p12, p13, p0, p1, p2, p3, p4, p5, p6);
        }
    }
}

/* COMMUNICATION_OPERATION_HANDLER_SOURCE */
#endif
