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
 * @version $RCSfile: interrupting_maintainer.c,v $ $Revision: 1.1 $ $Date: 2008-09-03 22:04:00 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPTER_SOURCE
#define INTERRUPTER_SOURCE

#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../constant/model/log/message_log_model.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../globals/variables/service_interrupt_variables.c"
#include "../globals/variables/thread_identification_variables.c"
#include "../memoriser/accessor/compound_accessor.c"

/**
 * Interrupts the thread.
 *
 * @param p0 the service thread
 * @param p1 the service thread interrupt
 */
void interrupt_thread(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            pthread_t* t = (pthread_t*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Interrupt thread.");

            if (*t != *NUMBER_MINUS_1_INTEGER) {

                // Set thread interrupt flag for signal handler.
                *i = *NUMBER_1_INTEGER;

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
                *t = *NUMBER_MINUS_1_INTEGER;

                // Reset thread interrupt flag for signal handler.
                *i = *NUMBER_0_INTEGER_MEMORY_MODEL;

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
 * Expected parameters:
 * - service (required): the service to be interrupted (gnu_linux_console, www, x_window_system etc.)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void interrupt_service(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Interrupt service.");

    // The service name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // Get service.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            interrupt_thread((void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            interrupt_thread((void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            interrupt_thread((void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) WIDE_CHARACTER_ARRAY_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            interrupt_thread((void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not interrupt service. The service model is unknown.");
    }
}

/* INTERRUPTER_SOURCE */
#endif
