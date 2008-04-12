/*
 * $RCSfile: checker.c,v $
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
 * @version $Revision: 1.42 $ $Date: 2008-04-12 17:03:22 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../controller/checker/cyboi_service_interrupt_checker.c"
#include "../controller/checker/gnu_linux_console_interrupt_checker.c"
#include "../controller/checker/www_service_interrupt_checker.c"
#include "../controller/checker/x_window_system_interrupt_checker.c"
#include "../controller/handler.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
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

    if (p3 != *NULL_POINTER) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p3;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Get and handle a signal.");

        // Get signal.
        get_signal(p0, p1, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        // Lock signal memory mutex.
        pthread_mutex_lock(mt);

        // Remove signal from signal memory.
        remove_signal(p0, p1, p2, p4);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(mt);

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get and handle a signal. The signal memory mutex is null.");
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

    if (p5 != *NULL_POINTER) {

        int* cyboi_service_irq = (int*) p5;

    if (p4 != *NULL_POINTER) {

        int* www_service_irq = (int*) p4;

    if (p3 != *NULL_POINTER) {

        int* x_window_system_irq = (int*) p3;

    if (p2 != *NULL_POINTER) {

        int* gnu_linux_console_irq = (int*) p2;

    if (p1 != *NULL_POINTER) {

        int* signal_memory_irq = (int*) p1;

        if (p0 != *NULL_POINTER) {

            double* signal_memory_sleep_time = (double*) p0;

            log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Wait for an interrupt request.");

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
            while ((*signal_memory_irq == *NUMBER_0_INTEGER)
                && (*gnu_linux_console_irq == *NUMBER_0_INTEGER)
                && (*x_window_system_irq == *NUMBER_0_INTEGER)
                && (*www_service_irq == *NUMBER_0_INTEGER)
                && (*cyboi_service_irq == *NUMBER_0_INTEGER)) {

                sleep(*signal_memory_sleep_time);
            }

            // The sleep loop above is left as soon as the interrupt variable
            // is set to a value other than zero.
            // This may happen if some user action is noted in one of the
            // receive threads, e.g. linux console, x window system, tcp socket.
            // In this case, a signal is placed in the signal memory and
            // the interrupt variable is set to *NUMBER_1_INTEGER.

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The signal memory sleep time is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The signal memory interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The gnu/linux console interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The x window system interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The www service interrupt request flag is null.");
    }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The cyboi service interrupt request flag is null.");
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

    if (p7 != *NULL_POINTER) {

        void** dc = (void**) p7;

        if (p6 != *NULL_POINTER) {

            void** d = (void**) p6;

            if (p5 != *NULL_POINTER) {

                void** mc = (void**) p5;

                if (p4 != *NULL_POINTER) {

                    void** m = (void**) p4;

                    if (p3 != *NULL_POINTER) {

                        void** ac = (void**) p3;

                        if (p2 != *NULL_POINTER) {

                            void** a = (void**) p2;

                            if (p1 != *NULL_POINTER) {

                                void** mt = (void**) p1;

                                if (p0 != *NULL_POINTER) {

                                    void** irq = (void**) p0;

                                    //?? TODO: Use "set_pointer_array" functions instead of setting values directly below!?
                                    //?? This would also make the casts above superfluous.

                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Check for interrupt requests.");

                    // CAUTION! The irq and mutex parameters are NOT casted above,
                    // in order to maintain better readability and extensibility.
                    // Further channels may be added in the future and adding them
                    // to the list below is just easier than having to indent and nest whole
                    // blocks of code, as it would be necessary when casting all parameters above.

                    if (*irq == *NULL_POINTER) {

                        // This interrupt is only checked if the irq flag is null.
                        // If it is not null, then another interrupt has been found before.

                        if (p5 != *NULL_POINTER) {

                            void** signal_memory_mutex = (void**) p5;

                            if (p4 != *NULL_POINTER) {

                                // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                                // and casting to int** might change the expected size.
                                // (Pointer and integer do not necessarily always have to have the same size.)
                                void** signal_memory_irq = (void**) p4;

                                if (**((int**) signal_memory_irq) != *NUMBER_0_INTEGER) {

                                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Detected signal memory interrupt.");

                                    // Set channel.
                                    *c = SIGNAL_MODEL;
                                    *cc = *SIGNAL_MODEL_COUNT;

                                    // Set interrupt request flag.
                                    *irq = *signal_memory_irq;
                                    // Set mutex.
                                    *mt = *signal_memory_mutex;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The signal memory interrupt request flag is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The signal memory mutex is null.");
                        }
                    }

                    if (*irq == *NULL_POINTER) {

                        // This interrupt is only checked if the irq flag is null.
                        // If it is not null, then another interrupt has been found before.

                        if (p7 != *NULL_POINTER) {

                            void** gnu_linux_console_mutex = (void**) p7;

                            if (p6 != *NULL_POINTER) {

                                // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                                // and casting to int** might change the expected size.
                                // (Pointer and integer do not necessarily always have to have the same size.)
                                void** gnu_linux_console_irq = (void**) p6;

                                if (**((int**) gnu_linux_console_irq) != *NUMBER_0_INTEGER) {

                                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Detected gnu/linux console interrupt.");

                                    // Set channel.
                                    *c = GNU_LINUX_CONSOLE_MODEL;
                                    *cc = *GNU_LINUX_CONSOLE_MODEL_COUNT;

                                    // Set interrupt request flag.
                                    *irq = *gnu_linux_console_irq;
                                    // Set mutex.
                                    *mt = *gnu_linux_console_mutex;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The gnu/linux console interrupt request flag is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The gnu/linux console mutex is null.");
                        }
                    }

                    if (*irq == *NULL_POINTER) {

                        // This interrupt is only checked if the irq flag is null.
                        // If it is not null, then another interrupt has been found before.

                        if (p9 != *NULL_POINTER) {

                            void** x_window_system_mutex = (void**) p9;

                            if (p8 != *NULL_POINTER) {

                                // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                                // and casting to int** might change the expected size.
                                // (Pointer and integer do not necessarily always have to have the same size.)
                                void** x_window_system_irq = (void**) p8;

                                if (**((int**) x_window_system_irq) != *NUMBER_0_INTEGER) {

                                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Detected x window system interrupt.");

                                    // Set channel.
                                    *c = X_WINDOW_SYSTEM_MODEL;
                                    *cc = *X_WINDOW_SYSTEM_MODEL_COUNT;

                                    // Set interrupt request flag.
                                    *irq = *x_window_system_irq;
                                    // Set mutex.
                                    *mt = *x_window_system_mutex;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The x window system interrupt request flag is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The x window system mutex is null.");
                        }
                    }

                    if (*irq == *NULL_POINTER) {

                        // This interrupt is only checked if the irq flag is null.
                        // If it is not null, then another interrupt has been found before.

                        if (p11 != *NULL_POINTER) {

                            void** www_service_mutex = (void**) p11;

                            if (p10 != *NULL_POINTER) {

                                // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                                // and casting to int** might change the expected size.
                                // (Pointer and integer do not necessarily always have to have the same size.)
                                void** www_service_irq = (void**) p10;

                                if (**((int**) www_service_irq) != *NUMBER_0_INTEGER) {

                                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Detected www service interrupt.");

                                    // Set channel.
                                    *c = WWW_SERVICE_MODEL;
                                    *cc = *WWW_SERVICE_MODEL_COUNT;

                                    // Set interrupt request flag.
                                    *irq = *www_service_irq;
                                    // Set mutex.
                                    *mt = *www_service_mutex;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The www service interrupt request flag is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The www service mutex is null.");
                        }
                    }

                    if (*irq == *NULL_POINTER) {

                        // This interrupt is only checked if the irq flag is null.
                        // If it is not null, then another interrupt has been found before.

                        if (p13 != *NULL_POINTER) {

                            void** cyboi_service_mutex = (void**) p13;

                            if (p12 != *NULL_POINTER) {

                                // CAUTION! Do NOT cast to int** because the value is assigned to *mt below
                                // and casting to int** might change the expected size.
                                // (Pointer and integer do not necessarily always have to have the same size.)
                                void** cyboi_service_irq = (void**) p12;

                                if (**((int**) cyboi_service_irq) != *NUMBER_0_INTEGER) {

                                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Detected cyboi service interrupt.");

                                    // Set channel.
                                    *c = CYBOI_SERVICE_MODEL;
                                    *cc = *CYBOI_SERVICE_MODEL_COUNT;

                                    // Set interrupt request flag.
                                    *irq = *cyboi_service_irq;
                                    // Set mutex.
                                    *mt = *cyboi_service_mutex;
                                }

                            } else {

                                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The cyboi service interrupt request flag is null.");
                            }

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The cyboi service mutex is null.");
                        }
                    }

                    if (*irq == *NULL_POINTER) {

                        log_terminated_message((void*) WARNING_LOG_LEVEL, (void*) "Could not check for interrupt requests. No interrupt request flag is set.");
                    }

                } else {

                    log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The channel is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The channel count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The mutex is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check for interrupt requests. The interrupt request flag is null.");
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
--
 * @param p23 the model (Hand over as reference!)
 * @param p24 the model count (Hand over as reference!)
 * @param p25 the model size (Hand over as reference!)
 * @param p26 the details (Hand over as reference!)
 * @param p27 the details count (Hand over as reference!)
 * @param p28 the details size (Hand over as reference!)
 * @param p29 the commands (Hand over as reference!)
 * @param p30 the commands count (Hand over as reference!)
 * @param p31 the language (Hand over as reference!)
 * @param p32 the language count (Hand over as reference!)
 * @param p33 the style (Hand over as reference!)
 * @param p34 the style count (Hand over as reference!)
 * @param p35 the buffer (Hand over as reference!)
 * @param p36 the buffer count (Hand over as reference!)
 * @param p37 the buffer size (Hand over as reference!)
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7,
    void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26,
    void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33, void* p34,
    void* p35, void* p36, void* p37, void* p38, void* p39, void* p40, void* p41, void* p42) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "\n\n");
    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Check for signal with highest priority and otherwise, for interrupts.");

    // The interrupts and mutexes.
    //
    // CAUTION! These have to be handed over as REFERENCE to this function,
    // since their values get manipulated in the "check_interrupts" function called further below!
    void** signal_memory_irq = (void**) p8;
    void** signal_memory_mutex = (void**) p9;
    void** signal_memory_sleep_time = (void**) p10;
    void** gnu_linux_console_irq = (void**) p11;
    void** gnu_linux_console_mutex = (void**) p12;
    void** x_window_system_irq = (void**) p14;
    void** x_window_system_mutex = (void**) p15;
    void** www_service_irq = (void**) p17;
    void** www_service_mutex = (void**) p18;
    void** cyboi_service_irq = (void**) p20;
    void** cyboi_service_mutex = (void**) p21;

    // The signal abstraction, model, details.
    void** a = NULL_POINTER;
    void** ac = NULL_POINTER;
    void** as = NULL_POINTER;
    void** m = NULL_POINTER;
    void** mc = NULL_POINTER;
    void** ms = NULL_POINTER;
    void** d = NULL_POINTER;
    void** dc = NULL_POINTER;
    void** ds = NULL_POINTER;
    // The signal priority.
    void** p = NULL_POINTER;
    // The signal identification.
    void** id = NULL_POINTER;
    // The direct execution flag.
    int x = *NUMBER_0_INTEGER;
    // The highest priority index.
    int i = *NUMBER_MINUS_1_INTEGER;

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

    if (i >= *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST index of signal with highest priority: %i\n", i);

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        // Get signal at given index.
        check_get(p4, p5, p6, *signal_memory_mutex, (void*) &i, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

    //?? For testing only. Delete these lines later!
    fprintf(stderr, "TEST a: %s\n", *((char**) a));
    fprintf(stderr, "TEST ac: %i\n", **((int**) ac));
//??    fprintf(stderr, "TEST m: %s\n", *m);
    fprintf(stderr, "TEST mc: %i\n", **((int**) mc));
    // CAUTION! d and dc are NULL. Do NOT try to print their values here!
/*??
    //?? p and id are not used anymore and do not always exist. So printing their value sometimes causes a crash.
    fprintf(stderr, "TEST p: %i\n", **((int**) p));
    fprintf(stderr, "TEST id: %i\n", **((int**) id));
*/

        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, *signal_memory_irq, *signal_memory_mutex, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

    } else {

        // The signal memory is empty, so that the cyboi system
        // may check for new interrupt requests now.

        // The interrupt request flag.
        int* irq = (int*) *NULL_POINTER;
        // The mutex.
        pthread_mutex_t* mt = (pthread_mutex_t*) *NULL_POINTER;

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

        if ((irq != *NULL_POINTER) && (*irq != *NUMBER_0_INTEGER)) {

    fprintf(stderr, "TEST irq: %i\n", *irq);

            // Lock cyboi service mutex.
            pthread_mutex_lock(mt);

            // Reset cyboi service interrupt request.
            //
            // The interrupt is reset to zero here because its purpose of
            // receiving data over some device and handling the corresponding
            // signals is fulfilled.
            //
            // This is done here, right after checking the interrupt flag
            // and yet BEFORE receiving data and handling the signal below,
            // so that the system may react faster to new interrupt requests.
            *irq = *NUMBER_0_INTEGER;

            // Unlock cyboi service mutex.
            pthread_mutex_unlock(mt);

            // REFLEXION: The single input threads deliver various kinds of input:
            // - gnu/linux console: a sequence of input commands (key presses) as stored in the keyboard buffer
            // - x window system: just one command (key press or mouse click etc.)
            // - socket: just one command (action handed over in URL or form data via GET or POST)
            //
            // When programming this part, it had to be decided how to store the multiple
            // input commands received from gnu/linux console. Possible options were:
            // 1 only read the first command and ignore all others
            //   --> NOT good because the user expects that all key presses are registered
            //   and not just forgotten, so that s/he doesn't have to repeat them
            // 2 create a new signal for each command and store them in signal memory
            //   --> NOT good because the data received e.g. over socket are temporary
            //       and get destroyed/ overwritten with each new (socket) data reception;
            //       but since the generated signals may rely on and reference these temporary data,
            //       the commands have to be handled AT ONCE, without generating signals first
            //       (therefore, the "handle" function is called directly below)
            // 3 create a temporary compound structure and add the single commands

            // Receive signal data (message) via the given channel.
/*??
            receive_with_parameters(p0, (void*) m, (void*) mc, (void*) ms, (void*) d, (void*) dc, (void*) ds,
                *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
                *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER, *NULL_POINTER,
                *NULL_POINTER, *NULL_POINTER, c, (void*) &cc);
*/

            //?? OPEN QUESTION: How to retrieve the correct "receive" function as knowledge model?
            //?? It was handed over as property to the "sense" operation.
            //?? Either store it in the internal memory or get it somehow else?

            // Handle signal.
            //
            // CAUTION! The "handle" function has to be called DIRECTLY here!
            // For reasons, see the comment block above!
            handle(p0, p1, p2, p3, p4, p5, p6, p7, *signal_memory_irq, *signal_memory_mutex, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

            // An interrupt request was detected and the corresponding data received.
            // It is therefore VERY likely that new signals have been generated while handling the data.
            // The cyboi system is therefore NOT sent to sleep, so that possibly existing
            // signals may be handled in the next iteration of the signal checker loop.

        } else {

    fprintf(stderr, "TEST wait: %i\n", irq);

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

    log_terminated_message((void*) INFORMATION_LOG_LEVEL, (void*) "\n\n");
    log_message((void*) INFORMATION_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

    // CAUTION! The parameters were not handed over as function arguments,
    // since it is more flexible to just hand over the internal memory as argument.
    // It is very likely that new services (besides gnu/linux console, x window system, socket etc.)
    // will be added in the future. So it is easier not to have to change the function arguments,
    // but instead just retrieve them from the internal memory below.
    //
    // CAUTION! ALL parameters are retrieved from the internal memory HERE,
    // since doing so within the loop further below would eat up precious cpu time.

    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER;
    // The knowledge memory.
    void** k = NULL_POINTER;
    void** kc = NULL_POINTER;
    void** ks = NULL_POINTER;
    // The signal memory.
    void** s = NULL_POINTER;
    void** sc = NULL_POINTER;
    void** ss = NULL_POINTER;
    // The signal memory interrupt request flag.
    void** signal_memory_irq = NULL_POINTER;
    // The signal memory mutex.
    void** signal_memory_mutex = NULL_POINTER;
    // The signal memory sleep time.
    void** signal_memory_sleep_time = NULL_POINTER;
    // The gnu/linux console interrupt request flag.
    void** gnu_linux_console_irq = NULL_POINTER;
    // The gnu/linux console mutex.
    void** gnu_linux_console_mutex = NULL_POINTER;
    // The gnu/linux console handler abstraction.
    void** gnu_linux_console_handler_a = NULL_POINTER;
    // The gnu/linux console handler abstraction count.
    void** gnu_linux_console_handler_ac = NULL_POINTER;
    // The gnu/linux console handler model.
    void** gnu_linux_console_handler_m = NULL_POINTER;
    // The gnu/linux console handler model count.
    void** gnu_linux_console_handler_mc = NULL_POINTER;
    // The gnu/linux console handler details.
    void** gnu_linux_console_handler_d = NULL_POINTER;
    // The gnu/linux console handler details count.
    void** gnu_linux_console_handler_dc = NULL_POINTER;
    // The x window system interrupt request flag.
    void** x_window_system_irq = NULL_POINTER;
    // The x window system mutex.
    void** x_window_system_mutex = NULL_POINTER;
    // The x window system handler abstraction.
    void** x_window_system_handler_a = NULL_POINTER;
    // The x window system handler abstraction count.
    void** x_window_system_handler_ac = NULL_POINTER;
    // The x window system handler model.
    void** x_window_system_handler_m = NULL_POINTER;
    // The x window system handler model count.
    void** x_window_system_handler_mc = NULL_POINTER;
    // The x window system handler details.
    void** x_window_system_handler_d = NULL_POINTER;
    // The x window system handler details count.
    void** x_window_system_handler_dc = NULL_POINTER;
    // The www service interrupt request flag.
    void** www_service_irq = NULL_POINTER;
    // The www service mutex.
    void** www_service_mutex = NULL_POINTER;
    // The www service handler abstraction.
    void** www_service_handler_a = NULL_POINTER;
    // The www service handler abstraction count.
    void** www_service_handler_ac = NULL_POINTER;
    // The www service handler model.
    void** www_service_handler_m = NULL_POINTER;
    // The www service handler model count.
    void** www_service_handler_mc = NULL_POINTER;
    // The www service handler details.
    void** www_service_handler_d = NULL_POINTER;
    // The www service handler details count.
    void** www_service_handler_dc = NULL_POINTER;
    // The cyboi service interrupt request flag.
    void** cyboi_service_irq = NULL_POINTER;
    // The cyboi service mutex.
    void** cyboi_service_mutex = NULL_POINTER;
    // The cyboi service handler abstraction.
    void** cyboi_service_handler_a = NULL_POINTER;
    // The cyboi service handler abstraction count.
    void** cyboi_service_handler_ac = NULL_POINTER;
    // The cyboi service handler model.
    void** cyboi_service_handler_m = NULL_POINTER;
    // The cyboi service handler model count.
    void** cyboi_service_handler_mc = NULL_POINTER;
    // The cyboi service handler details.
    void** cyboi_service_handler_d = NULL_POINTER;
    // The cyboi service handler details count.
    void** cyboi_service_handler_dc = NULL_POINTER;

/*??
    // The model.
    void** m = NULL_POINTER;
    void** mc = NULL_POINTER;
    void** ms = NULL_POINTER;
    // The details.
    void** d = NULL_POINTER;
    void** dc = NULL_POINTER;
    void** ds = NULL_POINTER;
    // The commands.
    void** c = NULL_POINTER;
    void** cc = NULL_POINTER;
    // The language.
    void** l = NULL_POINTER;
    void** lc = NULL_POINTER;
    // The communication style.
    void** st = NULL_POINTER;
    void** stc = NULL_POINTER;

    // The character buffer.
    void** b = NULL_POINTER;
    void** bc = NULL_POINTER;
    // The maximum buffer size.
    // CAUTION! A message MUST NOT be longer!
    void** bs = NULL_POINTER;
*/

    // Get knowledge memory internals.
    get_element(p0, (void*) KNOWLEDGE_MEMORY_INTERNAL, (void*) &k, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_COUNT_INTERNAL, (void*) &kc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) KNOWLEDGE_MEMORY_SIZE_INTERNAL, (void*) &ks, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory internals.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_COUNT_INTERNAL, (void*) &sc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    get_element(p0, (void*) SIGNAL_MEMORY_SIZE_INTERNAL, (void*) &ss, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory interrupt request flag.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL, (void*) &signal_memory_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &signal_memory_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get signal memory sleep time.
    get_element(p0, (void*) SIGNAL_MEMORY_SLEEP_TIME_INTERNAL, (void*) &signal_memory_sleep_time, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console interrupt request flag.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL, (void*) &gnu_linux_console_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL, (void*) &gnu_linux_console_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler abstraction.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL, (void*) &gnu_linux_console_handler_a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler abstraction count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL, (void*) &gnu_linux_console_handler_ac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler model.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL, (void*) &gnu_linux_console_handler_m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler model count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL, (void*) &gnu_linux_console_handler_mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler details.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL, (void*) &gnu_linux_console_handler_d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console handler details count.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL, (void*) &gnu_linux_console_handler_dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system interrupt request flag.
    get_element(p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL, (void*) &x_window_system_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &x_window_system_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler abstraction.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL, (void*) &x_window_system_handler_a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler abstraction count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL, (void*) &x_window_system_handler_ac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler model.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL, (void*) &x_window_system_handler_m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler model count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL, (void*) &x_window_system_handler_mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler details.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL, (void*) &x_window_system_handler_d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system handler details count.
    get_element(p0, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL, (void*) &x_window_system_handler_dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service interrupt request flag.
    i = *WWW_BASE_INTERNAL + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service mutex.
    i = *WWW_BASE_INTERNAL + *SOCKET_MUTEX_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler abstraction.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler abstraction count.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_ac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler model.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler model count.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler details.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service handler details count.
    i = *WWW_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_handler_dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service interrupt request flag.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service mutex.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_MUTEX_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler abstraction.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_a, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler abstraction count.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_ac, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler model.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler model count.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler details.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service handler details count.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_handler_dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

/*??
    int base = *CYBOI_BASE_INTERNAL;

    // Get model.
    i = base + *SOCKET_MODEL_INTERNAL;
    get_element(p0, (void*) &i, (void*) &m, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_MODEL_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &mc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_MODEL_SIZE_INTERNAL;
    get_element(p0, (void*) &i, (void*) &ms, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get details.
    i = base + *SOCKET_DETAILS_INTERNAL;
    get_element(p0, (void*) &i, (void*) &d, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_DETAILS_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &dc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_DETAILS_SIZE_INTERNAL;
    get_element(p0, (void*) &i, (void*) &ds, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get commands.
    i = base + *SOCKET_COMMANDS_INTERNAL;
    get_element(p0, (void*) &i, (void*) &c, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_COMMANDS_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get language.
    i = base + *SOCKET_LANGUAGE_INTERNAL;
    get_element(p0, (void*) &i, (void*) &l, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_LANGUAGE_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &lc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get communication style.
    i = base + *SOCKET_STYLE_INTERNAL;
    get_element(p0, (void*) &i, (void*) &st, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_STYLE_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &stc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Get character buffer, which was set at socket startup.
    i = base + *SOCKET_CHARACTER_BUFFER_INTERNAL;
    get_element(p0, (void*) &i, (void*) &b, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_CHARACTER_BUFFER_COUNT_INTERNAL;
    get_element(p0, (void*) &i, (void*) &bc, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    i = base + *SOCKET_CHARACTER_BUFFER_SIZE_INTERNAL;
    get_element(p0, (void*) &i, (void*) &bs, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
*/

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER) {

        if (f == *NUMBER_1_INTEGER) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, *k, *kc, *ks, *s, *sc, *ss, (void*) &f,
            (void*) signal_memory_irq, (void*) signal_memory_mutex, (void*) signal_memory_sleep_time,
            (void*) gnu_linux_console_irq, (void*) gnu_linux_console_mutex, (void*) gnu_linux_console_handler_a, (void*) gnu_linux_console_handler_ac, (void*) gnu_linux_console_handler_m, (void*) gnu_linux_console_handler_mc, (void*) gnu_linux_console_handler_d, (void*) gnu_linux_console_handler_dc,
            (void*) x_window_system_irq, (void*) x_window_system_mutex, (void*) x_window_system_handler_a, (void*) x_window_system_handler_ac, (void*) x_window_system_handler_m, (void*) x_window_system_handler_mc, (void*) x_window_system_handler_d, (void*) x_window_system_handler_dc,
            (void*) www_service_irq, (void*) www_service_mutex, (void*) www_service_handler_a, (void*) www_service_handler_ac, (void*) www_service_handler_m, (void*) www_service_handler_mc, (void*) www_service_handler_d, (void*) www_service_handler_dc,
            (void*) cyboi_service_irq, (void*) cyboi_service_mutex, (void*) cyboi_service_handler_a, (void*) cyboi_service_handler_ac, (void*) cyboi_service_handler_m, (void*) cyboi_service_handler_mc, (void*) cyboi_service_handler_d, (void*) cyboi_service_handler_dc
/*??
            , (void*) *m, (void*) *mc, (void*) *ms, (void*) *d, (void*) *dc, (void*) *ds,
            (void*) *c, (void*) *cc, (void*) *l, (void*) *lc, (void*) *st, (void*) *stc,
            (void*) b, (void*) bc, (void*) bs
*/
        );
    }
}

/* CHECKER_SOURCE */
#endif
