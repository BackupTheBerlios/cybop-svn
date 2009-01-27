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
 * @version $RCSfile: checker.c,v $ $Revision: 1.67 $ $Date: 2009-01-27 23:03:50 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../controller/handler.c"
#include "../constant/model/log/message_log_model.c"
#include "../constant/model/memory/integer_memory_model.c"
#include "../constant/model/memory/pointer_memory_model.c"
#include "../logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"

/**
 * Gets signal at the given index.
 *
 * @param p0 the interrupt request (Hand over as double-reference!)
 * @param p1 the mutex (Hand over as double-reference!)
 * @param p2 the signal abstraction (Hand over as double-reference!)
 * @param p3 the signal abstraction count (Hand over as double-reference!)
 * @param p4 the signal model (Hand over as double-reference!)
 * @param p5 the signal model count (Hand over as double-reference!)
 * @param p6 the signal details (Hand over as double-reference!)
 * @param p7 the signal details count (Hand over as double-reference!)
 * @param p8 the signal priority (Hand over as double-reference!)
 * @param p9 the signal identification (Hand over as double-reference!)
 * @param p10 the signal memory
 * @param p11 the signal memory count
 * @param p12 the signal index
 * @param p13 the internal memory
 */
void check_get(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get and handle a signal.");

    // Get signal memory interrupt request.
    get_element(p13, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get_element(p13, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Get signal.
    get_signal(p10, p11, p12, p2, p3, p4, p5, p6, p7, p8, p9);
}

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
        get_element(p1, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &sm, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        get_element(p1, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &lc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        get_element(p1, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &xw, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p1, (void*) &i, (void*) &ww, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
        i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
        get_element(p1, (void*) &i, (void*) &cy, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

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

    fwprintf(stdout, L"TEST wait *signal_memory_irq: %i\n", *((int*) *sm));
    fwprintf(stdout, L"TEST wait *gnu_linux_console_irq: %i\n", *((int*) *lc));
    fwprintf(stdout, L"TEST wait *x_window_system_irq: %i\n", *((int*) *xw));
    fwprintf(stdout, L"TEST wait *www_service_irq: %i\n", *((int*) *ww));
    fwprintf(stdout, L"TEST wait *cyboi_service_irq: %i\n", *((int*) *cy));

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

/**
 * Checks for interrupt requests.
 *
 * @param p0 the interrupt request (Hand over as double-reference!)
 * @param p1 the mutex (Hand over as double-reference!)
 * @param p2 the handler abstraction (Hand over as double-reference!)
 * @param p3 the handler abstraction count (Hand over as double-reference!)
 * @param p4 the handler model (Hand over as double-reference!)
 * @param p5 the handler model count (Hand over as double-reference!)
 * @param p6 the handler details (Hand over as double-reference!)
 * @param p7 the handler details count (Hand over as double-reference!)
 * @param p8 the internal memory
 */
void check_interrupts(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void*** irq = (void***) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for interrupt requests.");

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected signal memory interrupt.");

                // Get signal memory interrupt request.
                get_element(p8, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get signal memory mutex.
                get_element(p8, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST detected signal memory irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected gnu/linux console interrupt.");

                // Get gnu/linux console interrupt request.
                get_element(p8, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get gnu/linux console mutex.
                get_element(p8, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get gnu/linux console handler abstraction, model, details.
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST detected gnu/linux console irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected x window system interrupt.");

                // Get x window system interrupt request.
                get_element(p8, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get x window system mutex.
                get_element(p8, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get x window system handler abstraction, model, details.
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                get_element(p8, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST detected x window system irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected www service interrupt.");

                // Get www service interrupt request.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get www service mutex.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get www service handler abstraction, model, details.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected cyboi service interrupt.");

                // Get cyboi service interrupt request.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get cyboi service mutex.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                // Get cyboi service handler abstraction, model, details.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get_element(p8, (void*) &i, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. No interrupt request is set.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request dereferenced argument is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request argument is null.");
    }
}

/**
 * Checks for the signal with highest priority.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory sleep time
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for signal with highest priority and otherwise, for interrupts.");

    // The interrupt request.
    void** irq = NULL_POINTER_MEMORY_MODEL;
    // The mutex.
    void** mt = NULL_POINTER_MEMORY_MODEL;
    // The signal (or interrupt handler, respectively) abstraction, model, details.
    void** a = NULL_POINTER_MEMORY_MODEL;
    void** ac = NULL_POINTER_MEMORY_MODEL;
    void** as = NULL_POINTER_MEMORY_MODEL;
    void** m = NULL_POINTER_MEMORY_MODEL;
    void** mc = NULL_POINTER_MEMORY_MODEL;
    void** ms = NULL_POINTER_MEMORY_MODEL;
    void** d = NULL_POINTER_MEMORY_MODEL;
    void** dc = NULL_POINTER_MEMORY_MODEL;
    void** ds = NULL_POINTER_MEMORY_MODEL;
    // The signal priority.
    void** p = NULL_POINTER_MEMORY_MODEL;
    // The signal identification.
    void** id = NULL_POINTER_MEMORY_MODEL;
    // The direct execution flag.
    int x = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The highest priority index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

    // Get index of the top priority signal.
    get_highest_priority_signal_index(p4, p5, (void*) &i);

    // There are various possibilities to process signals.
    //
    // 1 First process all signals found in the signal memory
    // and only then check interrupts for new input.
    // The drawback of this solution is that the processing of a signal with
    // a long processing time cannot be interrupted by a key press or mouse click,
    // since these are not recognised as long as the interrupt flags are not checked.
    //
    // 2 First check for and process all interrupts
    // and only then process the signals found in signal memory.
    // The drawback here might be that the system never comes to processing signals,
    // for example when acting as web server with thousands of client requests.
    // In this case, the client requests in form of socket interrupts would be
    // processed on and on and only if no more client requests could be found,
    // the actual signals in the signal memory would be processed.
    //
    // Further alternatives are welcome!
    //
    // The current solution implemented here is number 1.
    // An alternative for the future might be number 2
    // (just exchange the following two if-else blocks of source code).

    if (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

    fwprintf(stdout, L"TEST index of signal with highest priority: %i\n", i);

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        // Get signal at given index.
        check_get((void*) &irq, (void*) &mt, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
            (void*) &d, (void*) &dc, (void*) &p, (void*) &id, p4, p5, (void*) &i, p0);

    //?? For testing only. Delete these lines later!
    fwprintf(stdout, L"TEST checker signal a: %ls\n", *((wchar_t**) a));
    fwprintf(stdout, L"TEST checker signal ac: %i\n", **((int**) ac));
//??    fwprintf(stdout, L"TEST signal m: %ls\n", *m);
    fwprintf(stdout, L"TEST checker signal mc: %i\n", **((int**) mc));
    // CAUTION! d and dc are NULL. Do NOT try to print their values here!
/*??
    //?? p and id are not used anymore and do not always exist. So printing their value sometimes causes a crash.
    fwprintf(stdout, L"TEST p: %i\n", **((int**) p));
    fwprintf(stdout, L"TEST id: %i\n", **((int**) id));
*/

        // Lock signal memory mutex.
        pthread_mutex_lock(*mt);

        // Remove signal from signal memory.
        remove_signal(p4, p5, p6, (void*) &i);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(*mt);

        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, *irq, *mt, *a, *ac, *m, *mc, *d, *dc, p, id, (void*) &x);

    } else {

        // The signal memory is empty, so that the cyboi system
        // may check for new interrupt requests now.

        // Check interrupt requests and get the appropriate:
        // - interrupt request (to be reset below)
        // - mutex (to be blocked while resetting the interrupt request below)
        // - handler (to be forwarded to the "handle" function below)
        check_interrupts((void*) &irq, (void*) &mt, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, p0);

    fwprintf(stdout, L"TEST checker irq: %i\n", *irq);

        // CAUTION! These conditions have to be CONNECTED by a boolean AND operator,
        // because otherwise, the "else" branch below would not always be reached.
        if ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

    fwprintf(stdout, L"TEST checker irq pre reset: %i\n", *((int*) *irq));

    fwprintf(stdout, L"TEST checker irq a: %ls\n", (wchar_t*) *a);
    fwprintf(stdout, L"TEST checker irq ac: %i\n", *ac);
    //?? Signal memory interrupts do NOT have an abstraction, model, details!

            // Lock mutex.
            pthread_mutex_lock(*mt);

            // Reset interrupt request.
            //
            // The interrupt is reset to zero here because its purpose
            // of receiving data over some device in order to handle
            // the corresponding signal is fulfilled.
            //
            // This is done here, right after checking the interrupt flag
            // and yet BEFORE receiving data and handling the signal below,
            // so that the system may react faster to new interrupt requests.
            *((int*) *irq) = *NUMBER_0_INTEGER_MEMORY_MODEL;

    fwprintf(stdout, L"TEST checker irq post reset: %i\n", *((int*) *irq));

            // Unlock mutex.
            pthread_mutex_unlock(*mt);

            // Handle signal.
            //
            // CAUTION! The "handle" function has to be called DIRECTLY (with direct execution flag set) here!
            // For reasons, see the comment block above!
            handle(p0, p1, p2, p3, p4, p5, p6, p7, *irq, *mt, *a, *ac, *m, *mc, *d, *dc, p, id, (void*) &x);

            // CAUTION! An interrupt request was detected and the corresponding data received.
            // It is therefore VERY likely that new signals have been generated while handling the data.
            // The cyboi system is therefore NOT sent to sleep, so that possibly existing
            // signals may be handled in the next iteration of the signal checker loop.

        } else {

            // No interrupt request was detected, so that the cyboi system
            // can be sent to sleep now, in order to save cpu time.

            check_wait(p8, p0);
        }
    }

    //
    // CAUTION! Do NOT destroy here either of the signal's:
    // - abstraction
    // - model
    // - details
    // - priority
    // - identification
    //
    // A signal only encapsulates an abstraction and a logic model,
    // which are stored in the knowledge tree.
    // That knowledge tree and all its models get created at
    // system startup or later and destroyed when processing a
    // corresponding CYBOL operation, or at system shutdown.
    //
    // The signal priority and identification are FIXED integer constants.
    //
}

/**
 * Checks the signal memory for signals.
 *
 * @param p0 the internal memory
 */
void check(void* p0) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_MODEL_COUNT);

    // CAUTION! The parameters were not handed over as function arguments,
    // since it is more flexible to just hand over the internal memory as argument.
    //
    // It is very likely that new services (besides gnu/linux console, x window system, socket etc.)
    // will be added in the future. So it is easier not to have to change the function arguments,
    // but instead just retrieve them from the internal memory below.
    //
    // CAUTION! ALL parameters are retrieved from the internal memory HERE,
    // since doing so within the loop further below would eat up precious cpu time.

    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The knowledge memory.
    void** k = NULL_POINTER_MEMORY_MODEL;
    void** kc = NULL_POINTER_MEMORY_MODEL;
    void** ks = NULL_POINTER_MEMORY_MODEL;
    // The signal memory.
    void** s = NULL_POINTER_MEMORY_MODEL;
    void** sc = NULL_POINTER_MEMORY_MODEL;
    void** ss = NULL_POINTER_MEMORY_MODEL;
    // The signal memory sleep time.
    void** signal_memory_sleep_time = NULL_POINTER_MEMORY_MODEL;

    // Get knowledge memory internals.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &k, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &kc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ks, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory internals.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &s, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &sc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ss, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory sleep time.
    get_element(p0, (void*) SIGNAL_MEMORY_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) &signal_memory_sleep_time, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, *k, *kc, *ks, *s, *sc, *ss, (void*) &f, *signal_memory_sleep_time);
    }
}

/* CHECKER_SOURCE */
#endif
