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
 * @version $RCSfile: system_signal_handler_manager.c,v $ $Revision: 1.18 $ $Date: 2009-01-31 16:06:31 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SYSTEM_SIGNAL_HANDLER_MANAGER_SOURCE
#define SYSTEM_SIGNAL_HANDLER_MANAGER_SOURCE

#include <pthread.h>
#include <signal.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Reacts to an interrupt service system signal.
 *
 * Services run in a separate thread each, for example:
 * - gnu/linux console
 * - unix socket
 * - tcp socket
 * - x window system
 *
 * This signal handler procedure is used by all threads in the process.
 *
 * @param p0 the signal numeric code
 */
void interrupt_service_system_signal_handler(int p0) {

    // This thread itself.
    pthread_t t = pthread_self();
/*??
    // This thread's identification.
    pthread_id_np_t id;

    // Get this thread's identification.
    pthread_getunique_np(&t, &id);

    // Get unique thread id.
//??    pthread_id_np_t id = pthread_getthreadid_np();
*/

//??    fwprintf(stdout, L"TEST signal handler thread t: %l\n", t);

    if (t == *GNU_LINUX_CONSOLE_THREAD) {

//??    fwprintf(stdout, L"TEST signal handler gnu/linux console %i\n", p0);

        if (*GNU_LINUX_CONSOLE_EXIT != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST signal handler gnu/linux console irq %i\n", p0);

            pthread_exit(*NULL_POINTER_MEMORY_MODEL);

            // CAUTION! The thread CANNOT be reset here with:
            // *GNU_LINUX_CONSOLE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
        }
    }

    if (t == *X_WINDOW_SYSTEM_THREAD) {

//??    fwprintf(stdout, L"TEST signal handler x window system %i\n", p0);

        if (*X_WINDOW_SYSTEM_EXIT != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST signal handler x window system irq %i\n", p0);

            pthread_exit(*NULL_POINTER_MEMORY_MODEL);

            // CAUTION! The thread CANNOT be reset here with:
            // *X_WINDOW_SYSTEM_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
        }
    }

    if (t == *WWW_SERVICE_THREAD) {

//??    fwprintf(stdout, L"TEST signal handler www service %i\n", p0);

        if (*WWW_SERVICE_EXIT != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST signal handler www service irq %i\n", p0);

            pthread_exit(*NULL_POINTER_MEMORY_MODEL);

            // CAUTION! The thread CANNOT be reset here with:
            // *WWW_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
        }
    }

    if (t == *CYBOI_SERVICE_THREAD) {

//??    fwprintf(stdout, L"TEST signal handler cyboi service %i\n", p0);

        if (*CYBOI_SERVICE_EXIT != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stdout, L"TEST signal handler cyboi service irq %i\n", p0);

            pthread_exit(*NULL_POINTER_MEMORY_MODEL);

            // CAUTION! The thread CANNOT be reset here with:
            // *CYBOI_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
        }
    }
}

/**
 * Starts up the system signal handler.
 *
 * CAUTION! Operating system signals are NOT TO BE MIXED UP with cyboi signals!
 * The system signals are used in cyboi to notify and exit threads
 * that served for input/ output and user communication.
 * These threads are not able to exit themselves because they block
 * while waiting for cyboi signals.
 */
void startup_system_signal_handler() {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup system signal handler.");

    // The signal set (mask).
    sigset_t mask;
    // The old signal set (mask).
    sigset_t oldmask;
    // The signal action.
    struct sigaction act;
    // The old signal action.
    struct sigaction oldact;

    // Initialise signal set (mask) to exclude all of the defined signals.
    // Specify the set of signals to be blocked while the handler runs.
    sigemptyset(&mask);

    // All sigaddset does is to modify the signal set (mask);
    // it does not block or unblock any signals.
    sigaddset(&mask, SIGIO);

    // Establish signal handler.
    // The interrupt_request_handler procedure is located in module:
    // /controller/checker.c
    act.sa_handler = interrupt_service_system_signal_handler;
    act.sa_mask = mask;
    act.sa_flags = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Establish old signal handler.
    oldact.sa_mask = oldmask;

    // Set up a new action for the SIGUSR1 signal.
    sigaction(SIGUSR1, &act, *NULL_POINTER_MEMORY_MODEL);

/*??
    // Examine or change the calling process's signal mask.
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    // Wait for a signal to arrive.
    // Although the program is apparently only waiting for special
    // signals, the while loop is necessary. The signal set (mask)
    // passed to sigsuspend permits the process to be woken up
    // by the delivery of other kinds of signals, as well --
    // for example, job control signals. If the process is woken up
    // by a signal that doesn't set INTERRUPT_REQUEST, it just suspends
    // itself again until the "right" kind of signal eventually arrives.
    while (*INTERRUPT_REQUEST == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        // This function replaces the process's signal set (mask) with
        // the old set and then suspends the process until a signal is
        // delivered whose action is either to terminate the process
        // or to invoke a signal handling function. In other words,
        // the program is effectively suspended until one of the
        // signals that is NOT a member of the signal set arrives.
        // If the process is woken up by delivery of a signal that
        // invokes a handler function, and the handler function
        // returns, then sigsuspend also returns.
        // The signal set (mask) remains set only as long as sigsuspend
        // is waiting. The function sigsuspend always restores the
        // previous signal mask when it returns.
        sigsuspend(&oldmask);
    }

    // Examine or change the calling process's signal mask.
    // When sigsuspend returns, it resets the process's signal set (mask)
    // to the original value, the value from before the call to
    // sigsuspend -- in this case, the SIGIO and SIGUSR1 signals are
    // once again blocked. This call to sigprocmask is necessary to
    // explicitly unblock this signal.
    sigprocmask(SIG_UNBLOCK, &mask, *NULL_POINTER_MEMORY_MODEL);
*/
}

/* SYSTEM_SIGNAL_HANDLER_MANAGER_SOURCE */
#endif
