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
 * @version $RCSfile: interrupting_maintainer.c,v $ $Revision: 1.7 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPTING_MAINTAINER_SOURCE
#define INTERRUPTING_MAINTAINER_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/lifecycle_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Interrupts the thread.
 *
 * @param p0 the service thread
 * @param p1 the service thread interrupt
 */
void apply_interrupt_thread(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            pthread_t* t = (pthread_t*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Interrupt thread.");

            if (*t != *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL) {

                // Set thread interrupt flag for signal handler.
                *i = *NUMBER_1_INTEGER_MEMORY_MODEL;

                // Send signal to thread.
                //
                // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
                // ends the ENTIRE PROCESS, not simply the target thread.
                // SIGKILL is defined to end the entire process, regardless
                // of the thread it is delivered to, or how it is sent.
                //
                // The user signal SIGUSR1 is used here instead.
                // It is processed in the interrupt_service_system_signal_handler
                // procedure, situated in the following module:
                // controller/manager/system_signal_handler_manager.c
                pthread_kill(*t, SIGUSR1);

                // Wait for thread to finish.
                pthread_join(*t, *NULL_POINTER_MEMORY_MODEL);

                // A mutex is not needed while setting the following parameters,
                // since the corresponding thread was killed above so that NO
                // other entities exist that may access the parameters.

                // Reset thread.
                *t = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

                // Reset thread interrupt flag for signal handler.
                *i = *FALSE_BOOLEAN_MEMORY_MODEL;

            } else {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not interrupt thread. The service thread is invalid.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not interrupt thread. The service thread is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not interrupt thread. The service thread interrupt is null.");
    }
}

/**
 * Interrupts a service.
 *
 * Expected parametres:
 * - service (required): the service to be interrupted (gnu_linux_console, www, x_window_system etc.)
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 */
void apply_interrupt(void* p0, void* p1) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply interrupt.");

    // The service part.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The service part model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    // The service part model data.
    void* smd = *NULL_POINTER_MEMORY_MODEL;

    // Get service part.
    get_name_array((void*) &s, p0, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get service part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get service part model data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            apply_interrupt_thread((void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            apply_interrupt_thread((void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) WWW_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            apply_interrupt_thread((void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            apply_interrupt_thread((void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply interrupt. The service is unknown.");
    }
}

/* INTERRUPTING_MAINTAINER_SOURCE */
#endif
