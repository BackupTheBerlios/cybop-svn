/*
 * $RCSfile: interrupt.c,v $
 *
 * Copyright (c) 1999-2007. Christian Heller and the CYBOP developers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * http://www.cybop.net
 * - Cybernetics Oriented Programming -
 *
 * @version $Revision: 1.22 $ $Date: 2007-12-28 19:25:54 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_SOURCE
#define INTERRUPT_SOURCE

/*??
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
*/
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
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

    if (p1 != *NULL_POINTER) {

        int* i = (int*) p1;

        if (p0 != *NULL_POINTER) {

            pthread_t* t = (pthread_t*) p0;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Interrupt thread.");

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
                pthread_join(*t, *NULL_POINTER);

                // A mutex is not needed while setting the following parameters,
                // since the corresponding thread was killed above so that NO
                // other entities exist that may access the parameters.

                // Reset thread.
                *t = *NUMBER_MINUS_1_INTEGER;

                // Reset thread interrupt flag for signal handler.
                *i = *NUMBER_0_INTEGER;

            } else {

                log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not interrupt thread. The service thread is invalid.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not interrupt thread. The service thread is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not interrupt thread. The service thread interrupt is null.");
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

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "Interrupt service.");

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
    int r = *NUMBER_0_INTEGER;

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) GNU_LINUX_CONSOLE_MODEL, (void*) GNU_LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            interrupt_thread((void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            interrupt_thread((void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            interrupt_thread((void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != *NUMBER_0_INTEGER) {

            interrupt_thread((void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER) {

        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not interrupt service. The service model is unknown.");
    }
}

/* INTERRUPT_SOURCE */
#endif
