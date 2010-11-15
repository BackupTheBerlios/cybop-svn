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
 * @version $RCSfile: checker.c,v $ $Revision: 1.72 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WAIT_CHECKER_SOURCE
#define WAIT_CHECKER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/accessor/getter.c"
#include "../../logger/logger.c"

/**
 * Waits for an interrupt request.
 *
 * @param p0 the sleep time
 * @param p1 the internal memory
 */
void check_wait(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        double* sl = (double*) p0;

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // The signal memory interrupt request.
        void** sm = NULL_POINTER_MEMORY_MODEL;
        // The gnu/linux console interrupt request.
        void** lc = NULL_POINTER_MEMORY_MODEL;
        // The x window system interrupt request.
        void** xw = NULL_POINTER_MEMORY_MODEL;
        // The www service interrupt request.
        void** ww = NULL_POINTER_MEMORY_MODEL;
        // The cyboi service interrupt request.
        void** cy = NULL_POINTER_MEMORY_MODEL;

        // Get interrupt requests.
        get((void*) &sm, p1, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &lc, p1, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        get((void*) &xw, p1, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &ww, p1, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
        i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
        get((void*) &cy, p1, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        //
        // REMARK! The following variable checks and casts are not indented,
        // since many more variables may have to be added in the future,
        // so that indentation would lead to unreadable source code here.
        //

        if (*cy != *NULL_POINTER_MEMORY_MODEL) {

        if (*ww != *NULL_POINTER_MEMORY_MODEL) {

        if (*xw != *NULL_POINTER_MEMORY_MODEL) {

        if (*lc != *NULL_POINTER_MEMORY_MODEL) {

        if (*sm != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Wait for an interrupt request.");

            //
            // Sleep for some time.
            //
            // If no signals are waiting in the signal memory (queue)
            // and no hardware requests have been received from either the:
            // - gnu/linux console
            // - x window system
            // - www service
            // - cyboi service
            // then cpu processing time may be saved by sending the system to sleep.
            //
            // Several possibilities have been considered to achieve this:
            //
            // 1 pause
            //
            // The simplicity of pause can conceal serious timing errors
            // that can make a program hang mysteriously.
            // One can't safely use pause to wait until one more signal
            // arrives, and then resume real work. Even if one arranges
            // for the signal handler to cooperate by setting a flag,
            // one still can't use pause reliably.
            //
            // Example:
            // // The irq flag is set by some signal handler.
            // if (irq == 0) {
            //     pause();
            // }
            // // Do work once the signal arrives.
            // ...
            //
            // This has a bug: the signal could arrive after the variable
            // irq is checked, but before the call to pause. If no further
            // signals arrive, the process would never wake up again.
            //
            // 2 sleep
            //
            // One can put an upper limit on the excess waiting by using
            // sleep in a loop, instead of using pause.
            //
            // Example:
            // // The irq flag is set by some signal handler.
            // while (irq == 0) {
            //     sleep(1);
            // }
            // // Do work once the signal arrives.
            // ...
            //
            // For some purposes, that is good enough.
            //
            // 3 signals of the operating system
            //
            // With a little more complexity, one can wait reliably until
            // a particular signal handler is run, using sigsuspend.
            //
            // Solution in CYBOI
            //
            // The signal handler approach was tried out and implemented.
            // However, when the process was sent to sleep with sigsuspend,
            // all its threads were sleeping as well. This is a problem,
            // because the input/output (including user interface control)
            // is running in special threads. Since these were sleeping,
            // there was no way to wake up the CYBOI system on user request.
            //
            // Another approach was to let the input/output run in their
            // own process (instead of only a thread), each.
            // The problem here is resource sharing between the processes.
            // While threads use the same resources as their parent process,
            // child processes copy their parent process' resources at
            // creation and afterwards work independently on their own resources.
            // This is a problem because CYBOI's signal memory needs to be
            // accessed by all input/output processes without conflicts.
            //
            // Furthermore, the usage of operating system signals enforces
            // a global interrupt request flag variable. Since a signal
            // handler procedure may receive only the numeric code of the
            // signal, but not further parameters, the interrupt request
            // flag may not be handed over within the internal memory and
            // a global flag would have to be used, which is undesirable.
            //
            // Therefore, the decision fell on the usage of a simple SLEEP
            // procedure, which seems sufficient for the purposes of CYBOI.
            //
            while ((*((int*) *sm) == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*((int*) *lc) == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*((int*) *xw) == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*((int*) *ww) == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*((int*) *cy) == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                sleep(*sl);
            }

/*??
    fwprintf(stdout, L"TEST wait *signal_memory_irq: %i\n", *((int*) *sm));
    fwprintf(stdout, L"TEST wait *gnu_linux_console_irq: %i\n", *((int*) *lc));
    fwprintf(stdout, L"TEST wait *x_window_system_irq: %i\n", *((int*) *xw));
    fwprintf(stdout, L"TEST wait *www_service_irq: %i\n", *((int*) *ww));
    fwprintf(stdout, L"TEST wait *cyboi_service_irq: %i\n", *((int*) *cy));
*/

            // The sleep loop above is left as soon as at least one of the
            // interrupt variables is set to a value other than zero.
            // This may happen if some user action is noted in one of the
            // receive threads, e.g. linux console, x window system, tcp socket.
            // In this case, a signal is placed in the signal memory and
            // the corresponding interrupt variable is set to *NUMBER_1_INTEGER_MEMORY_MODEL.

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The signal memory interrupt request is null.");
        }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The gnu/linux console interrupt request is null.");
        }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The x window system interrupt request is null.");
        }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The www service interrupt request is null.");
        }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The cyboi service interrupt request is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The sleep time is null.");
    }
}

/* WAIT_CHECKER_SOURCE */
#endif
