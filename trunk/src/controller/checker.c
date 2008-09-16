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
 * @version $RCSfile: checker.c,v $ $Revision: 1.56 $ $Date: 2008-09-16 07:13:50 $ $Author: christian $
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
 * @param p0 the signal memory
 * @param p1 the signal memory count
 * @param p2 the signal memory size
 * @param p3 the signal memory mutex
 * @param p4 the signal index
 * @param p5 the action abstraction (Hand over as reference!)
 * @param p6 the action abstraction count
 * @param p7 the action model (Hand over as reference!)
 * @param p8 the action model count
 * @param p9 the action details (Hand over as reference!)
 * @param p10 the action details count
 * @param p11 the signal priority (Hand over as reference!)
 * @param p12 the signal identification (Hand over as reference!)
 */
void check_get(void* p0, void* p1, void* p2, void* p3, void* p4,
    void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p3;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Get and handle a signal.");

        // Get signal.
        get_signal(p0, p1, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        // Lock signal memory mutex.
        pthread_mutex_lock(mt);

        // Remove signal from signal memory.
        remove_signal(p0, p1, p2, p4);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(mt);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not get and handle a signal. The signal memory mutex is null.");
    }
}

/**
 * Waits for an interrupt request.
 *
 * @param p0 the signal memory sleep time
 * @param p1 the signal memory interrupt request flag
 * @param p2 the gnu/linux console interrupt request flag
 * @param p3 the x window system interrupt request flag
 * @param p4 the www service interrupt request flag
 * @param p5 the cyboi service interrupt request flag
 */
void check_wait(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    //
    // REMARK! The following variable checks and casts are not indented,
    // since many more variables may have to be added in the future,
    // so that indentation would lead to unreadable source code here.
    //

    if (p5 != *NULL_POINTER_MEMORY_MODEL) {

        int* cyboi_service_irq = (int*) p5;

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* www_service_irq = (int*) p4;

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* x_window_system_irq = (int*) p3;

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* gnu_linux_console_irq = (int*) p2;

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* signal_memory_irq = (int*) p1;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            double* signal_memory_sleep_time = (double*) p0;

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
            while ((*signal_memory_irq == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*gnu_linux_console_irq == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*x_window_system_irq == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*www_service_irq == *NUMBER_0_INTEGER_MEMORY_MODEL)
                && (*cyboi_service_irq == *NUMBER_0_INTEGER_MEMORY_MODEL)) {

                sleep(*signal_memory_sleep_time);
            }

            // The sleep loop above is left as soon as the interrupt variable
            // is set to a value other than zero.
            // This may happen if some user action is noted in one of the
            // receive threads, e.g. linux console, x window system, tcp socket.
            // In this case, a signal is placed in the signal memory and
            // the interrupt variable is set to *NUMBER_1_INTEGER_MEMORY_MODEL.

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The signal memory sleep time is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The signal memory interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The gnu/linux console interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The x window system interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The www service interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not wait for an interrupt request. The cyboi service interrupt request flag is null.");
    }
}

/**
 * Checks for interrupt requests.
 *
 * @param p0 the interrupt request flag (Hand over as reference!)
 * @param p1 the mutex (Hand over as reference!)
 * @param p2 the handler abstraction (Hand over as reference!)
 * @param p3 the handler abstraction count (Hand over as reference!)
 * @param p4 the handler model (Hand over as reference!)
 * @param p5 the handler model count (Hand over as reference!)
 * @param p6 the handler details (Hand over as reference!)
 * @param p7 the handler details count (Hand over as reference!)
 * @param p8 the signal memory interrupt request flag (Hand over as reference!)
 * @param p9 the signal memory mutex (Hand over as reference!)
 * @param p10 the gnu/linux console interrupt request flag (Hand over as reference!)
 * @param p11 the gnu/linux console mutex (Hand over as reference!)
 * @param p12 the gnu/linux console handler abstraction (Hand over as reference!)
 * @param p13 the gnu/linux console handler abstraction count (Hand over as reference!)
 * @param p14 the gnu/linux console handler model (Hand over as reference!)
 * @param p15 the gnu/linux console handler model count (Hand over as reference!)
 * @param p16 the gnu/linux console handler details (Hand over as reference!)
 * @param p17 the gnu/linux console handler details count (Hand over as reference!)
 * @param p18 the x window system interrupt request flag (Hand over as reference!)
 * @param p19 the x window system mutex (Hand over as reference!)
 * @param p20 the x window system handler abstraction (Hand over as reference!)
 * @param p21 the x window system handler abstraction count (Hand over as reference!)
 * @param p22 the x window system handler model (Hand over as reference!)
 * @param p23 the x window system handler model count (Hand over as reference!)
 * @param p24 the x window system handler details (Hand over as reference!)
 * @param p25 the x window system handler details count (Hand over as reference!)
 * @param p26 the www service interrupt request flag (Hand over as reference!)
 * @param p27 the www service mutex (Hand over as reference!)
 * @param p28 the www service handler abstraction (Hand over as reference!)
 * @param p29 the www service handler abstraction count (Hand over as reference!)
 * @param p30 the www service handler model (Hand over as reference!)
 * @param p31 the www service handler model count (Hand over as reference!)
 * @param p32 the www service handler details (Hand over as reference!)
 * @param p33 the www service handler details count (Hand over as reference!)
 * @param p34 the cyboi service interrupt request flag (Hand over as reference!)
 * @param p35 the cyboi service mutex (Hand over as reference!)
 * @param p36 the cyboi service handler abstraction (Hand over as reference!)
 * @param p37 the cyboi service handler abstraction count (Hand over as reference!)
 * @param p38 the cyboi service handler model (Hand over as reference!)
 * @param p39 the cyboi service handler model count (Hand over as reference!)
 * @param p40 the cyboi service handler details (Hand over as reference!)
 * @param p41 the cyboi service handler details count (Hand over as reference!)
 */
void check_interrupts(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25,
    void* p26, void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33,
    void* p34, void* p35, void* p36, void* p37, void* p38, void* p39, void* p40, void* p41) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** irq = (void**) p0;

//??    fwprintf(stderr, L"TEST IRQ 1: %i\n", p0);

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for interrupt requests.");

/*??
        // CAUTION! Compare *irq to NULL_POINTER_MEMORY_MODEL here!
        // An alternative would be to do the following cast above:
        // void*** irq = (void***) p0;
        // and then compare **irq to *NULL_POINTER_MEMORY_MODEL.
        // However, working with *** pointers is not nice,
        // so that the simpler version of comparing to the
        // pointer reference NULL_POINTER_MEMORY_MODEL is used here.
        if (*irq == NULL_POINTER_MEMORY_MODEL) {

    fwprintf(stderr, L"TEST IRQ 2: %i\n", p0);

            // This interrupt is only checked if the irq flag is null.
            // If it is not null, then another interrupt has been found before.

            //?? TODO: The mutex is NOT needed here; delete later!
            if (p9 != *NULL_POINTER_MEMORY_MODEL) {

                void** signal_memory_mutex = (void**) p9;

                if (p8 != *NULL_POINTER_MEMORY_MODEL) {

                    //?? TODO: OLD comment; delete later!
                    // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                    // and casting to int** might change the expected size.
                    // (Pointer and integer do not necessarily always have to have the same size.)
                    void** signal_memory_irq = (void**) p8;

                    if (**((int**) signal_memory_irq) != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected signal memory interrupt.");

                        // Set interrupt request flag.
                        get_element(p8, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set mutex.
                        get_element(p9, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST detected signal memory irq: %i\n", **((int**) irq));
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The signal memory interrupt request flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The signal memory mutex is null.");
            }
        }
*/

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

//??    fwprintf(stderr, L"TEST IRQ 3: %i\n", p0);

            // This interrupt is only checked if the irq flag is null.
            // If it is not null, then another interrupt has been found before.

            //?? TODO: The mutex is NOT needed here; delete later!
            if (p11 != *NULL_POINTER_MEMORY_MODEL) {

//??    fwprintf(stderr, L"TEST IRQ 4: %i\n", p0);

                void** gnu_linux_console_mutex = (void**) p11;

                if (p10 != *NULL_POINTER_MEMORY_MODEL) {

//??    fwprintf(stderr, L"TEST IRQ 5: %i\n", p0);

                    //?? TODO: OLD comment; delete later!
                    // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                    // and casting to int** might change the expected size.
                    // (Pointer and integer do not necessarily always have to have the same size.)
                    void** gnu_linux_console_irq = (void**) p10;

                    if (**((int**) gnu_linux_console_irq) != *NUMBER_0_INTEGER_MEMORY_MODEL) {

//??    fwprintf(stderr, L"TEST IRQ 6: %i\n", p0);

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected gnu/linux console interrupt.");

                        // Set interrupt request flag.
                        get_element(p10, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set mutex.
                        get_element(p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set handler.
                        get_element(p12, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p13, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p14, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p15, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p16, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p17, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST detected gnu/linux console irq: %i\n", **((int**) irq));
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The gnu/linux console interrupt request flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The gnu/linux console mutex is null.");
            }
        }

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

            // This interrupt is only checked if the irq flag is null.
            // If it is not null, then another interrupt has been found before.

            //?? TODO: The mutex is NOT needed here; delete later!
            if (p19 != *NULL_POINTER_MEMORY_MODEL) {

                void** x_window_system_mutex = (void**) p19;

                if (p18 != *NULL_POINTER_MEMORY_MODEL) {

                    //?? TODO: OLD comment; delete later!
                    // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                    // and casting to int** might change the expected size.
                    // (Pointer and integer do not necessarily always have to have the same size.)
                    void** x_window_system_irq = (void**) p18;

                    if (**((int**) x_window_system_irq) != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected x window system interrupt.");

                        // Set interrupt request flag.
                        get_element(p18, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set mutex.
                        get_element(p19, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set handler.
                        get_element(p20, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p21, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p22, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p23, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p24, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p25, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stderr, L"TEST detected x window system irq: %i\n", **((int**) irq));
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The x window system interrupt request flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The x window system mutex is null.");
            }
        }

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

            // This interrupt is only checked if the irq flag is null.
            // If it is not null, then another interrupt has been found before.

            //?? TODO: The mutex is NOT needed here; delete later!
            if (p27 != *NULL_POINTER_MEMORY_MODEL) {

                void** www_service_mutex = (void**) p27;

                if (p26 != *NULL_POINTER_MEMORY_MODEL) {

                    //?? TODO: OLD comment; delete later!
                    // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                    // and casting to int** might change the expected size.
                    // (Pointer and integer do not necessarily always have to have the same size.)
                    void** www_service_irq = (void**) p26;

                    if (**((int**) www_service_irq) != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected www service interrupt.");

                        // Set interrupt request flag.
                        get_element(p26, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set mutex.
                        get_element(p27, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set handler.
                        get_element(p28, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p29, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p30, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p31, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p32, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p33, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The www service interrupt request flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The www service mutex is null.");
            }
        }

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

            // This interrupt is only checked if the irq flag is null.
            // If it is not null, then another interrupt has been found before.

            //?? TODO: The mutex is NOT needed here; delete later!
            if (p35 != *NULL_POINTER_MEMORY_MODEL) {

                void** cyboi_service_mutex = (void**) p35;

                if (p34 != *NULL_POINTER_MEMORY_MODEL) {

                    //?? TODO: OLD comment; delete later!
                    // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                    // and casting to int** might change the expected size.
                    // (Pointer and integer do not necessarily always have to have the same size.)
                    void** cyboi_service_irq = (void**) p34;

                    if (**((int**) cyboi_service_irq) != *NUMBER_0_INTEGER_MEMORY_MODEL) {

                        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected cyboi service interrupt.");

                        // Set interrupt request flag.
                        get_element(p34, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p0, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set mutex.
                        get_element(p35, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p1, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        // Set handler.
                        get_element(p36, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p2, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p37, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p38, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p4, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p39, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p5, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p40, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p6, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                        get_element(p41, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p7, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
                    }

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The cyboi service interrupt request flag is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The cyboi service mutex is null.");
            }
        }

        if (*irq == *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. No interrupt request flag is set.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request flag is null.");
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
 * @param p8 the signal memory interrupt request flag (Hand over as reference!)
 * @param p9 the signal memory mutex (Hand over as reference!)
 * @param p10 the signal memory sleep time (Hand over as reference!)
 * @param p11 the gnu/linux console interrupt request flag (Hand over as reference!)
 * @param p12 the gnu/linux console mutex (Hand over as reference!)
 * @param p13 the gnu/linux console handler abstraction (Hand over as reference!)
 * @param p14 the gnu/linux console handler abstraction count (Hand over as reference!)
 * @param p15 the gnu/linux console handler model (Hand over as reference!)
 * @param p16 the gnu/linux console handler model count (Hand over as reference!)
 * @param p17 the gnu/linux console handler details (Hand over as reference!)
 * @param p18 the gnu/linux console handler details count (Hand over as reference!)
 * @param p19 the x window system interrupt request flag (Hand over as reference!)
 * @param p20 the x window system mutex (Hand over as reference!)
 * @param p21 the x window system handler abstraction (Hand over as reference!)
 * @param p22 the x window system handler abstraction count (Hand over as reference!)
 * @param p23 the x window system handler model (Hand over as reference!)
 * @param p24 the x window system handler model count (Hand over as reference!)
 * @param p25 the x window system handler details (Hand over as reference!)
 * @param p26 the x window system handler details count (Hand over as reference!)
 * @param p27 the www service interrupt request flag (Hand over as reference!)
 * @param p28 the www service mutex (Hand over as reference!)
 * @param p29 the www service handler abstraction (Hand over as reference!)
 * @param p30 the www service handler abstraction count (Hand over as reference!)
 * @param p31 the www service handler model (Hand over as reference!)
 * @param p32 the www service handler model count (Hand over as reference!)
 * @param p33 the www service handler details (Hand over as reference!)
 * @param p34 the www service handler details count (Hand over as reference!)
 * @param p35 the cyboi service interrupt request flag (Hand over as reference!)
 * @param p36 the cyboi service mutex (Hand over as reference!)
 * @param p37 the cyboi service handler abstraction (Hand over as reference!)
 * @param p38 the cyboi service handler abstraction count (Hand over as reference!)
 * @param p39 the cyboi service handler model (Hand over as reference!)
 * @param p40 the cyboi service handler model count (Hand over as reference!)
 * @param p41 the cyboi service handler details (Hand over as reference!)
 * @param p42 the cyboi service handler details count (Hand over as reference!)
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26,
    void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33, void* p34,
    void* p35, void* p36, void* p37, void* p38, void* p39, void* p40, void* p41, void* p42) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for signal with highest priority and otherwise, for interrupts.");

    // The interrupts and mutexes.
    //
    // CAUTION! These have to be handed over as REFERENCE to this function,
    // since their values get manipulated in the "check_interrupts" function called further below!
    void** signal_memory_irq = (void**) p8;
    void** signal_memory_mutex = (void**) p9;
    void** signal_memory_sleep_time = (void**) p10;
    void** gnu_linux_console_irq = (void**) p11;
    void** gnu_linux_console_mutex = (void**) p12;
    void** x_window_system_irq = (void**) p19;
    void** x_window_system_mutex = (void**) p20;
    void** www_service_irq = (void**) p27;
    void** www_service_mutex = (void**) p28;
    void** cyboi_service_irq = (void**) p35;
    void** cyboi_service_mutex = (void**) p36;

    // The signal abstraction, model, details.
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

    fwprintf(stderr, L"TEST index of signal with highest priority: %i\n", i);

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        // Get signal at given index.
        check_get(p4, p5, p6, *signal_memory_mutex, (void*) &i, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

    //?? For testing only. Delete these lines later!
    fwprintf(stderr, L"TEST checker signal a: %ls\n", *((wchar_t**) a));
    fwprintf(stderr, L"TEST checker signal ac: %i\n", **((int**) ac));
//??    fwprintf(stderr, L"TEST signal m: %ls\n", *m);
    fwprintf(stderr, L"TEST checker signal mc: %i\n", **((int**) mc));
    // CAUTION! d and dc are NULL. Do NOT try to print their values here!
/*??
    //?? p and id are not used anymore and do not always exist. So printing their value sometimes causes a crash.
    fwprintf(stderr, L"TEST p: %i\n", **((int**) p));
    fwprintf(stderr, L"TEST id: %i\n", **((int**) id));
*/

        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, *signal_memory_irq, *signal_memory_mutex, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

    } else {

        // The signal memory is empty, so that the cyboi system
        // may check for new interrupt requests now.

        // The interrupt request flag.
        int** irq = (int**) NULL_POINTER_MEMORY_MODEL;
        // The mutex.
        pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;

        // Check interrupt request flags and get the appropriate:
        // - interrupt request flag (to be reset below)
        // - mutex (to be blocked while resetting the interrupt request flag below)
        // - handler (to be forwarded to the "handle" function below)
        check_interrupts((void*) &irq, (void*) &mt, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc,
            p8, p9,
            p11, p12, p13, p14, p15, p16, p17, p18,
            p19, p20, p21, p22, p23, p24, p25, p26,
            p27, p28, p29, p30, p31, p32, p33, p34,
            p35, p36, p37, p38, p39, p40, p41, p42);

        if ((irq != (int**) NULL_POINTER_MEMORY_MODEL) && (*irq != (int*) *NULL_POINTER_MEMORY_MODEL) && (**irq != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

    fwprintf(stderr, L"TEST checker irq: %i\n", **irq);

    fwprintf(stderr, L"TEST checker irq a: %ls\n", (wchar_t*) *a);
    fwprintf(stderr, L"TEST checker irq ac: %i\n", **((int**) ac));
    fwprintf(stderr, L"TEST checker irq mc: %i\n", **((int**) mc));
    fwprintf(stderr, L"TEST checker irq dc: %i\n", **((int**) dc));

            // Lock mutex.
            pthread_mutex_lock(*mt);

            // Reset interrupt request flag.
            //
            // The interrupt is reset to zero here because its purpose
            // of receiving data over some device in order to handle
            // the corresponding signal is fulfilled.
            //
            // This is done here, right after checking the interrupt flag
            // and yet BEFORE receiving data and handling the signal below,
            // so that the system may react faster to new interrupt requests.
            **irq = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Unlock mutex.
            pthread_mutex_unlock(*mt);

            // Handle signal.
            //
            // CAUTION! The "handle" function has to be called DIRECTLY here!
            // For reasons, see the comment block above!
            handle(p0, p1, p2, p3, p4, p5, p6, p7, *signal_memory_irq, *signal_memory_mutex, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

            // CAUTION! An interrupt request was detected and the corresponding data received.
            // It is therefore VERY likely that new signals have been generated while handling the data.
            // The cyboi system is therefore NOT sent to sleep, so that possibly existing
            // signals may be handled in the next iteration of the signal checker loop.

        } else {

            // No interrupt request was detected, so that the cyboi system
            // can be sent to sleep now, in order to save cpu time.

            check_wait(*signal_memory_sleep_time, *signal_memory_irq, *gnu_linux_console_irq, *x_window_system_irq, *www_service_irq, *cyboi_service_irq);
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
    // The signal memory interrupt request flag.
    void** signal_memory_irq = NULL_POINTER_MEMORY_MODEL;
    // The signal memory mutex.
    void** signal_memory_mutex = NULL_POINTER_MEMORY_MODEL;
    // The signal memory sleep time.
    void** signal_memory_sleep_time = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console interrupt request flag.
    void** gnu_linux_console_irq = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console mutex.
    void** gnu_linux_console_mutex = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler abstraction.
    void** gnu_linux_console_handler_a = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler abstraction count.
    void** gnu_linux_console_handler_ac = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler model.
    void** gnu_linux_console_handler_m = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler model count.
    void** gnu_linux_console_handler_mc = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler details.
    void** gnu_linux_console_handler_d = NULL_POINTER_MEMORY_MODEL;
    // The gnu/linux console handler details count.
    void** gnu_linux_console_handler_dc = NULL_POINTER_MEMORY_MODEL;
    // The x window system interrupt request flag.
    void** x_window_system_irq = NULL_POINTER_MEMORY_MODEL;
    // The x window system mutex.
    void** x_window_system_mutex = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler abstraction.
    void** x_window_system_handler_a = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler abstraction count.
    void** x_window_system_handler_ac = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler model.
    void** x_window_system_handler_m = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler model count.
    void** x_window_system_handler_mc = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler details.
    void** x_window_system_handler_d = NULL_POINTER_MEMORY_MODEL;
    // The x window system handler details count.
    void** x_window_system_handler_dc = NULL_POINTER_MEMORY_MODEL;
    // The www service interrupt request flag.
    void** www_service_irq = NULL_POINTER_MEMORY_MODEL;
    // The www service mutex.
    void** www_service_mutex = NULL_POINTER_MEMORY_MODEL;
    // The www service handler abstraction.
    void** www_service_handler_a = NULL_POINTER_MEMORY_MODEL;
    // The www service handler abstraction count.
    void** www_service_handler_ac = NULL_POINTER_MEMORY_MODEL;
    // The www service handler model.
    void** www_service_handler_m = NULL_POINTER_MEMORY_MODEL;
    // The www service handler model count.
    void** www_service_handler_mc = NULL_POINTER_MEMORY_MODEL;
    // The www service handler details.
    void** www_service_handler_d = NULL_POINTER_MEMORY_MODEL;
    // The www service handler details count.
    void** www_service_handler_dc = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service interrupt request flag.
    void** cyboi_service_irq = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service mutex.
    void** cyboi_service_mutex = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler abstraction.
    void** cyboi_service_handler_a = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler abstraction count.
    void** cyboi_service_handler_ac = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler model.
    void** cyboi_service_handler_m = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler model count.
    void** cyboi_service_handler_mc = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler details.
    void** cyboi_service_handler_d = NULL_POINTER_MEMORY_MODEL;
    // The cyboi service handler details count.
    void** cyboi_service_handler_dc = NULL_POINTER_MEMORY_MODEL;

    // Get knowledge memory internals.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &k, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &kc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ks, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory internals.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_MEMORY_NAME, (void*) &s, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &sc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL_MEMORY_MEMORY_NAME, (void*) &ss, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory interrupt request flag.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &signal_memory_irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &signal_memory_mutex, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory sleep time.
    get_element(p0, (void*) SIGNAL_MEMORY_SLEEP_TIME_INTERNAL_MEMORY_MEMORY_NAME, (void*) &signal_memory_sleep_time, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console interrupt request flag.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_mutex, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler abstraction.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_a, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler abstraction count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_ac, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler model.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_m, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler model count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_mc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler details.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_d, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get gnu/linux console handler details count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME_MEMORY_MEMORY_NAME, (void*) &gnu_linux_console_handler_dc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system interrupt request flag.
    get_element(p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_mutex, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler abstraction.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_a, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler abstraction count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_ac, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler model.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_m, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler model count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_mc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler details.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_d, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get x window system handler details count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) &x_window_system_handler_dc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service interrupt request flag.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service mutex.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_mutex, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler abstraction.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_a, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler abstraction count.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_ac, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler model.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_m, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler model count.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_mc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler details.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_d, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get www service handler details count.
    i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &www_service_handler_dc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service interrupt request flag.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service mutex.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_mutex, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler abstraction.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_a, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler abstraction count.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_ac, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler model.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_m, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler model count.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_mc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler details.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_d, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get cyboi service handler details count.
    i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_dc, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

        if (f == *NUMBER_1_INTEGER_MEMORY_MODEL) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, *k, *kc, *ks, *s, *sc, *ss, (void*) &f,
            (void*) signal_memory_irq, (void*) signal_memory_mutex, (void*) signal_memory_sleep_time,
            (void*) gnu_linux_console_irq, (void*) gnu_linux_console_mutex, (void*) gnu_linux_console_handler_a, (void*) gnu_linux_console_handler_ac, (void*) gnu_linux_console_handler_m, (void*) gnu_linux_console_handler_mc, (void*) gnu_linux_console_handler_d, (void*) gnu_linux_console_handler_dc,
            (void*) x_window_system_irq, (void*) x_window_system_mutex, (void*) x_window_system_handler_a, (void*) x_window_system_handler_ac, (void*) x_window_system_handler_m, (void*) x_window_system_handler_mc, (void*) x_window_system_handler_d, (void*) x_window_system_handler_dc,
            (void*) www_service_irq, (void*) www_service_mutex, (void*) www_service_handler_a, (void*) www_service_handler_ac, (void*) www_service_handler_m, (void*) www_service_handler_mc, (void*) www_service_handler_d, (void*) www_service_handler_dc,
            (void*) cyboi_service_irq, (void*) cyboi_service_mutex, (void*) cyboi_service_handler_a, (void*) cyboi_service_handler_ac, (void*) cyboi_service_handler_m, (void*) cyboi_service_handler_mc, (void*) cyboi_service_handler_d, (void*) cyboi_service_handler_dc);
    }
}

/* CHECKER_SOURCE */
#endif
