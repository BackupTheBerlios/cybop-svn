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
 * @version $RCSfile: communicator.c,v $ $Revision: 1.7 $ $Date: 2008-10-05 23:15:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

//
// CAUTION! Do NOT name the pre-processor statement COMMUNICATOR_SOURCE!
// The reason is that this name is already used by the file "memoriser/communicator.c".
//
#ifndef APPLICATOR_COMMUNICATOR_SOURCE
#define APPLICATOR_COMMUNICATOR_SOURCE

#include "../applicator/communicator/receiving_communicator.c"
#include "../applicator/communicator/sending_communicator.c"
#include "../applicator/communicator/sensing_communicator.c"
#include "../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../constant/model/cybol/operation/communication_operation_cybol_model.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../constant/name/cybol/operation/communication/send_communication_operation_cybol_name.c"
#include "../constant/name/cybol/operation/communication/sense_communication_operation_cybol_name.c"
#include "../constant/name/cybol/operation_cybol_name.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"

/**
 * Communicates between partners.
 *
 * Expected parameters:
 * - type (required): the type of the operation
 * - ... (depending on the type, further parameters may have to be given)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the internal memory
 */
void communicate(void* p0, int* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Communicate between partners.");

    // The operation type name, abstraction, model, details.
    void** tn = NULL_POINTER_MEMORY_MODEL;
    void** tnc = NULL_POINTER_MEMORY_MODEL;
    void** tns = NULL_POINTER_MEMORY_MODEL;
    void** ta = NULL_POINTER_MEMORY_MODEL;
    void** tac = NULL_POINTER_MEMORY_MODEL;
    void** tas = NULL_POINTER_MEMORY_MODEL;
    void** tm = NULL_POINTER_MEMORY_MODEL;
    void** tmc = NULL_POINTER_MEMORY_MODEL;
    void** tms = NULL_POINTER_MEMORY_MODEL;
    void** td = NULL_POINTER_MEMORY_MODEL;
    void** tdc = NULL_POINTER_MEMORY_MODEL;
    void** tds = NULL_POINTER_MEMORY_MODEL;

    // Get operation type.
    get_universal_compound_element_by_name(p0, p1,
        (void*) TYPE_OPERATION_CYBOL_NAME, (void*) TYPE_OPERATION_CYBOL_NAME_COUNT,
        (void*) &tn, (void*) &tnc, (void*) &tns,
        (void*) &ta, (void*) &tac, (void*) &tas,
        (void*) &tm, (void*) &tmc, (void*) &tms,
        (void*) &td, (void*) &tdc, (void*) &tds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) INTERRUPT_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) INTERRUPT_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            communicate_interrupting(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) RECEIVE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            communicate_receiving(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) SEND_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            communicate_sending(p0, p1, p2, p3, p4, p5);

            //?? OLD STUFF!
            //?? TEST: For testing reasons, the p15 was replaced with *((int**) p15) here!
            //?? The signal id serves as client socket to which this cyboi system has to reply.
            //?? send_message(p12, p13, p0, p1, p2, p3, p4, p5, p6, *((int**) p15));
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays(*tm, *tmc, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL, (void*) SENSE_COMMUNICATION_OPERATION_CYBOL_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??            communicate_sensing(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not communicate between partners. The operation type is unknown.");
    }
}

/* APPLICATOR_COMMUNICATOR_SOURCE */
#endif
