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
 * @version $RCSfile: sensing_communicator.c,v $ $Revision: 1.11 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_SOURCE
#define SENSE_SOURCE

#include "../../applicator/communicator/sensing/gnu_linux_console_sensing_communicator.c"
#include "../../applicator/communicator/sensing/socket_sensing_communicator.c"
#include "../../applicator/communicator/sensing/x_window_system_sensing_communicator.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/communication/sense_communication_operation_cybol_name.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'apply_sense_gnu_linux_console' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &apply_sense_gnu_linux_console
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void apply_sense_gnu_linux_console(void* p0);
void apply_sense_cyboi_socket(void* p0);
void apply_sense_www_socket(void* p0);
void apply_sense_x_window_system(void* p0);

/**
 * Senses message.
 *
 * @param p0 the internal memory
 * @param p1 the service thread
 * @param p2 the thread procedure
 */
void apply_sense_message(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* t = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Apply sense message.");

        // Only create thread, if not existent.
        // CAUTION! The "pthread_t" type is an integer, so both can be compared.
        if (*t == *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Create sense message thread.");

            // Create thread.
            //
            // CAUTION! Do NOT allocate any resources within the thread procedure!
            // The reason is that this main process thread gets forked when executing
            // external programs. A "fork" duplicates ALL resources of the parent process,
            // including ALL resources of any threads running within the parent process.
            // However, since the created child process does not have those threads running,
            // their duplicated resources will never be deallocated, which eats up memory.
            // See source code file: applicator/run/run_execute.c
            //
            // Any dynamically allocated resources needed within the thread have to be:
            // - allocated at service startup
            // - added to the internal memory
            // - handed over to the thread procedure HERE
            // - deallocated at service shutdown
            //
            // The third parameter is the procedure to be called.
            pthread_create((pthread_t*) p1, *NULL_POINTER_MEMORY_MODEL, p2, p0);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not apply sense message. The service thread is null.");
    }
}

/**
 * Senses an interrupt request happening on the given device channel.
 *
 * In order to sense interrupt requests of various devices, special mechanisms
 * for interrupt detection have to be started. To these mechanisms belong:
 * - gnu/linux console
 * - x window system
 * - socket
 *
 * All of them have their own internal signal/ action/ event/ interrupt waiting loops
 * which get (re-)activated here, running as parallel services in separate threads.
 * Whenever an event occurs in one of these threads, it gets transformed into a
 * cyboi-internal interrupt request by setting the corresponding flag.
 * The cyboi signal checker loop then senses the interrupt and receives the
 * corresponding message via the channel the interrupt belongs to.
 *
 * Expected parameters:
 * - channel (required): the channel via which to receive the message (gnu_linux_console, www, x_window_system etc.)
 * - handler (optional): the handler (usually a receive operation) that parses an input and filters out a command that the system is to react to
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 * @param p4 the signal memory array
 */
void apply_sense(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply sense.");

    // The channel part.
    void* c = *NULL_POINTER_MEMORY_MODEL;
    // The handler part.
    void* h = *NULL_POINTER_MEMORY_MODEL;

    // The channel part model.
    void* cm = *NULL_POINTER_MEMORY_MODEL;
    // The handler part model.
    void* hm = *NULL_POINTER_MEMORY_MODEL;

    // The channel part model data, count.
    void* cmd = *NULL_POINTER_MEMORY_MODEL;
    void* cmc = *NULL_POINTER_MEMORY_MODEL;
    // The handler part model data, count.
    void* hmd = *NULL_POINTER_MEMORY_MODEL;
    void* hmc = *NULL_POINTER_MEMORY_MODEL;

    // Get channel part.
    get_name_array((void*) &c, p0, (void*) CHANNEL_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) CHANNEL_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get handler part.
    get_name_array((void*) &h, p0, (void*) HANDLER_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME, (void*) HANDLER_SENSE_COMMUNICATION_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get channel part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get handler part model.
    copy_array_forward((void*) &hm, h, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get channel part model data, count.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &cmc, cm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get handler part model data, count.
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &hmc, hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) CYBOI_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) CYBOI_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST sense cyboi service hac: %i\n", *hac);
    fwprintf(stdout, L"TEST sense cyboi service ha: %i\n", *ha);

            // Set handler abstraction, model, details.
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) ha, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hac, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hmc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hdc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

            // Sense incoming message (http request or response).
            apply_sense_message(p2, (void*) CYBOI_SERVICE_THREAD, (void*) &apply_sense_cyboi_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            copy_array_forward(p2, (void*) ha, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hac, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hmc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hdc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

            // Sense incoming message.
            apply_sense_message(p2, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) &apply_sense_gnu_linux_console);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) WWW_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) WWW_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) ha, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hac, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hmc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
            copy_array_forward(p2, (void*) hdc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

            // Sense incoming message (http request or response).
            apply_sense_message(p2, (void*) WWW_SERVICE_THREAD, (void*) &apply_sense_www_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, cmd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, cmc, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Set handler abstraction, model, details.
            copy_array_forward(p2, (void*) ha, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hac, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hmc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hd, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            copy_array_forward(p2, (void*) hdc, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

            // Sense incoming message.
            apply_sense_message(p2, (void*) X_WINDOW_SYSTEM_THREAD, (void*) &apply_sense_x_window_system);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply sense interrupt request. The channel is unknown.");
    }
}

/* SENSE_SOURCE */
#endif
