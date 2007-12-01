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
 * @version $Revision: 1.34 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
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
#include "../globals/variables/sleep_time_variables.c"
#include "../memoriser/accessor/signal_memory_accessor.c"

/**
 * Gets and handles a signal.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the signal memory interrupt request flag
 * @param p9 the signal memory mutex
 * @param p10 the signal index
 * @param p11 the action name (Hand over as reference!)
 * @param p12 the action name count
 * @param p13 the action name size
 * @param p14 the action abstraction (Hand over as reference!)
 * @param p15 the action abstraction count
 * @param p16 the action abstraction size
 * @param p17 the action model (Hand over as reference!)
 * @param p18 the action model count
 * @param p19 the action model size
 * @param p20 the action details (Hand over as reference!)
 * @param p21 the action details count
 * @param p22 the action details size
 * @param p23 the signal priority (Hand over as reference!)
 * @param p24 the signal identification (Hand over as reference!)
 */
void check_handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10,
    void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24) {

    if (p9 != *NULL_POINTER) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p9;

        log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Get and handle a signal.");

/*??
        // The abstraction.
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        // The model (signal operation).
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        // The details (parameters).
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        // The signal priority.
        void** p = NULL_POINTER;
        // The main signal identification.
        void** id = NULL_POINTER;
        // The direct execution flag.
        int x = *NUMBER_0_INTEGER;
*/

        // Get signal.
        get_signal(p4, p5, p10, p14, p15, p17, p18, p20, p21, p23, p24);

    /*??
        //?? For testing only. Delete these lines later!
        fprintf(stderr, "TEST index: %i\n", *((int*) p10));
        fprintf(stderr, "TEST a: %s\n", (char*) *a);
        fprintf(stderr, "TEST ac: %i\n", *((int*) *ac));
        fprintf(stderr, "TEST m: %s\n", (char*) *m);
        fprintf(stderr, "TEST mc: %i\n", *((int*) *mc));
        // CAUTION! d and dc are NULL. DO NOT try to print their values here!
        fprintf(stderr, "TEST p: %i\n", *((int*) *p));
        fprintf(stderr, "TEST id: %i\n", *((int*) *id));
    */

        // Lock signal memory mutex.
        pthread_mutex_lock(mt);

        // Remove signal from signal memory.
        remove_signal(p4, p5, p6, p10);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(mt);

/*??
        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p, id, &x);
*/

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not get and handle a signal. The signal memory mutex is null.");
    }
}

/**
 * Waits for an interrupt request.
 *
 * @param p0 the signal memory interrupt request flag
 * @param p1 the signal memory mutex
 * @param p2 the gnu/linux console interrupt request flag
 * @param p3 the gnu/linux console mutex
 * @param p4 the x window system interrupt request flag
 * @param p5 the x window system mutex
 * @param p6 the www service interrupt request flag
 * @param p7 the www service mutex
 * @param p8 the cyboi service interrupt request flag
 * @param p9 the cyboi service mutex
 */
void check_wait(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p8 != *NULL_POINTER) {

        int* cyboi_service_irq = (int*) p8;

        if (p6 != *NULL_POINTER) {

            int* www_service_irq = (int*) p6;

            if (p4 != *NULL_POINTER) {

                int* x_window_system_irq = (int*) p4;

                if (p2 != *NULL_POINTER) {

                    int* gnu_linux_console_irq = (int*) p2;

                    if (p1 != *NULL_POINTER) {

                        pthread_mutex_t* signal_memory_mutex = (pthread_mutex_t*) p1;

                        if (p0 != *NULL_POINTER) {

                            int* signal_memory_irq = (int*) p0;

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

                                sleep(*CHECKER_SLEEP_TIME);
                            }

                            // The sleep loop above is left as soon as the interrupt variable
                            // is set to a value other than zero.
                            // This may happen if some user action is noted in one of the
                            // receive threads, e.g. linux console, x window system, tcp socket.
                            // In this case, a signal is placed in the signal memory and
                            // the interrupt variable is set to *NUMBER_1_INTEGER.

                        } else {

                            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The signal memory interrupt request flag is null.");
                        }

                    } else {

                        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not wait for an interrupt request. The signal memory mutex is null.");
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
 * @param p0 the channel
 * @param p1 the channel count
 * @param p2 the mutex
 * @param p3 the interrupt request flag
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
 * @param p10 the gnu/linux console interrupt request flag (Hand over as reference!)
 * @param p11 the gnu/linux console mutex (Hand over as reference!)
 * @param p12 the x window system interrupt request flag (Hand over as reference!)
 * @param p13 the x window system mutex (Hand over as reference!)
 * @param p14 the www service interrupt request flag (Hand over as reference!)
 * @param p15 the www service mutex (Hand over as reference!)
 * @param p16 the cyboi service interrupt request flag (Hand over as reference!)
 * @param p17 the cyboi service mutex (Hand over as reference!)
 * @param p18 the comparison result
 * @param p19 the action name (Hand over as reference!)
 * @param p20 the action name count
 * @param p21 the action name size
 * @param p22 the action abstraction (Hand over as reference!)
 * @param p23 the action abstraction count
 * @param p24 the action abstraction size
 * @param p25 the action model (Hand over as reference!)
 * @param p26 the action model count
 * @param p27 the action model size
 * @param p28 the action details (Hand over as reference!)
 * @param p29 the action details count
 * @param p30 the action details size
 * @param p31 the model
 * @param p32 the model count
 * @param p33 the model size
 * @param p34 the details
 * @param p35 the details count
 * @param p36 the details size
 * @param p37 the commands
 * @param p38 the commands count
 * @param p39 the language
 * @param p40 the language count
 * @param p41 the style
 * @param p42 the style count
 * @param p43 the buffer (Hand over as reference!)
 * @param p44 the buffer count
 * @param p45 the buffer size
 */
void check_interrupts(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18,
    void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26, void* p27, void* p28, void* p29, void* p30,
    void* p31, void* p32, void* p33, void* p34, void* p35, void* p36, void* p37, void* p38, void* p39, void* p40, void* p41, void* p42,
    void* p43, void* p44, void* p45) {

    if (p3 != *NULL_POINTER) {

        void** irq = (void**) p3;

        if (p2 != *NULL_POINTER) {

            void** mt = (void**) p2;

            if (p1 != *NULL_POINTER) {

                int* cc = (int*) p1;

                if (p0 != *NULL_POINTER) {

                    void** c = (void**) p0;

                    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Check for interrupt requests.");

                    if (*irq == *NULL_POINTER) {

                        if (p9 != *NULL_POINTER) {

                            void** signal_memory_mutex = (void**) p9;

                            if (p8 != *NULL_POINTER) {

                                void** signal_memory_irq = (void**) p8;

                                if (**signal_memory_irq != *NUMBER_0_INTEGER) {

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

                        if (p11 != *NULL_POINTER) {

                            void** gnu_linux_console_mutex = (void**) p11;

                            if (p10 != *NULL_POINTER) {

                                void** gnu_linux_console_irq = (void**) p10;

                                if (**gnu_linux_console_irq != *NUMBER_0_INTEGER) {

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

                        if (p13 != *NULL_POINTER) {

                            void** x_window_system_mutex = (void**) p13;

                            if (p12 != *NULL_POINTER) {

                                void** x_window_system_irq = (void**) p12;

                                if (**x_window_system_irq != *NUMBER_0_INTEGER) {

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

                        if (p15 != *NULL_POINTER) {

                            void** www_service_mutex = (void**) p15;

                            if (p14 != *NULL_POINTER) {

                                void** www_service_irq = (void**) p14;

                                if (**www_service_irq != *NUMBER_0_INTEGER) {

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

                        if (p17 != *NULL_POINTER) {

                            void** cyboi_service_mutex = (void**) p17;

                            if (p16 != *NULL_POINTER) {

                                void** cyboi_service_irq = (void**) p16;

                                if (**cyboi_service_irq != *NUMBER_0_INTEGER) {

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
 * @param p10 the gnu/linux console interrupt request flag (Hand over as reference!)
 * @param p11 the gnu/linux console mutex (Hand over as reference!)
 * @param p12 the x window system interrupt request flag (Hand over as reference!)
 * @param p13 the x window system mutex (Hand over as reference!)
 * @param p14 the www service interrupt request flag (Hand over as reference!)
 * @param p15 the www service mutex (Hand over as reference!)
 * @param p16 the cyboi service interrupt request flag (Hand over as reference!)
 * @param p17 the cyboi service mutex (Hand over as reference!)
 * @param p18 the model (Hand over as reference!)
 * @param p19 the model count (Hand over as reference!)
 * @param p20 the model size (Hand over as reference!)
 * @param p21 the details (Hand over as reference!)
 * @param p22 the details count (Hand over as reference!)
 * @param p23 the details size (Hand over as reference!)
 * @param p24 the commands (Hand over as reference!)
 * @param p25 the commands count (Hand over as reference!)
 * @param p26 the language (Hand over as reference!)
 * @param p27 the language count (Hand over as reference!)
 * @param p28 the style (Hand over as reference!)
 * @param p29 the style count (Hand over as reference!)
 * @param p30 the buffer (Hand over as reference!)
 * @param p31 the buffer count (Hand over as reference!)
 * @param p32 the buffer size (Hand over as reference!)
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17,
    void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25, void* p26, void* p27, void* p28, void* p29,
    void* p30, void* p31, void* p32) {

    log_terminated_message((void*) DEBUG_LOG_LEVEL, (void*) "Check for signal with highest priority and otherwise, for interrupts.");

    // The action name, abstraction, model, details.
    void** n = NULL_POINTER;
    void** nc = NULL_POINTER;
    void** ns = NULL_POINTER;
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
    // The main signal identification.
    void** id = NULL_POINTER;
    // The direct execution flag.
    int x = *NUMBER_0_INTEGER;
    // The highest priority index.
    int i = *NUMBER_MINUS_1_INTEGER;

    // Get index of the top priority signal.
    get_highest_priority_signal_index(p4, p5, (void*) &i);

    if (i >= *NUMBER_0_INTEGER) {

    fprintf(stderr, "TEST signal priority: %i\n", i);

        // A signal was found and has to be handled.
        //
        // Handling a signal has higher priority than checking for new interrupt requests.

        check_handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, (void*) &i,
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            (void*) &p, (void*) &id);

        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

    } else {

        // The signal memory is empty, so that the cyboi system
        // may check for new interrupt requests now.

        // The channel.
        void* c = *NULL_POINTER;
        int cc = *NUMBER_0_INTEGER;
        // The mutex.
        pthread_mutex_t* mt = (pthread_mutex_t*) *NULL_POINTER;
        // The interrupt request flag.
        int* irq = (int*) *NULL_POINTER;

        // Check interrupt request flags and get the appropriate:
        // - channel (to be forwarded to the "receive" function below)
        // - mutex (to be used to reset the interrupt request flag below)
        // - interrupt request flag (to be reset below)
        check_interrupts((void*) &c, (void*) &cc, (void*) &mt, (void*) &irq,
            p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17,
            (void*) &n, (void*) &nc, (void*) &ns,
            (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms,
            (void*) &d, (void*) &dc, (void*) &ds,
            p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29, p30, p31, p32);

    fprintf(stderr, "TEST interrupts r: %i\n", *irq);

        if ((irq != *NULL_POINTER) && (*irq != *NUMBER_0_INTEGER)) {

            // Receive data.
            receive(p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29, p30, p31, p32, p33, p1, p2, c, (void*) &cc);

            // Handle signal.
            //
            // CAUTION! The "handle" function has to be called DIRECTLY here!
            // Placing a new signal in the signal memory will mostly not work correctly,
            // because the data received over socket are temporary and get deleted
            // each time, yet before receiving new data over socket.
            // But since the signal parses and references these temporary data,
            // the system will not process the signal correctly, if the data have been destroyed.
            handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

            // Lock cyboi service mutex.
            pthread_mutex_lock(mt);

            // Reset cyboi service interrupt request.
            //
            // The interrupt is reset to zero here because its purpose of
            // receiving data over some device and handling the corresponding
            // signals is fulfilled.
            *irq = *NUMBER_0_INTEGER;

            // Unlock cyboi service mutex.
            pthread_mutex_unlock(mt);

    fprintf(stderr, "TEST empty: %i\n", r);

            // An interrupt request was detected and the corresponding data received.
            // It is therefore VERY likely that new signals have been generated while handling the data.
            // The cyboi system is therefore NOT sent to sleep, so that possibly existing
            // signals may be handled in the next iteration of the signal checker loop.

        } else {

    fprintf(stderr, "TEST wait: %i\n", r);

            // No interrupt request was detected, so that the cyboi system
            // can be sent to sleep now, in order to save cpu time.

            check_wait(p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
        }
    }

    //
    // CAUTION! Do NOT destroy here either of the signal's:
    // - abstraction
    // - model
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
    // The gnu/linux console interrupt request flag.
    void** gnu_linux_console_irq = NULL_POINTER;
    // The gnu/linux console mutex.
    void** gnu_linux_console_mutex = NULL_POINTER;
    // The x window system interrupt request flag.
    void** x_window_system_irq = NULL_POINTER;
    // The signal memory mutex.
    void** x_window_system_mutex = NULL_POINTER;
    // The www service interrupt request flag.
    void** www_service_irq = NULL_POINTER;
    // The www service mutex.
    void** www_service_mutex = NULL_POINTER;
    // The cyboi service interrupt request flag.
    void** cyboi_service_irq = NULL_POINTER;
    // The cyboi service mutex.
    void** cyboi_service_mutex = NULL_POINTER;

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
    // Get gnu/linux console interrupt request flag.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL, (void*) &gnu_linux_console_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get gnu/linux console mutex.
    get_element(p0, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL, (void*) &gnu_linux_console_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system interrupt request flag.
    get_element(p0, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL, (void*) &x_window_system_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get x window system mutex.
    get_element(p0, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL, (void*) &x_window_system_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service interrupt request flag.
    i = *WWW_BASE_INTERNAL + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get www service mutex.
    i = *WWW_BASE_INTERNAL + *SOCKET_MUTEX_INTERNAL;
    get_element(p0, (void*) &i, (void*) &www_service_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service interrupt request flag.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_INTERRUPT_REQUEST_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get cyboi service mutex.
    i = *CYBOI_BASE_INTERNAL + *SOCKET_MUTEX_INTERNAL;
    get_element(p0, (void*) &i, (void*) &cyboi_service_mutex, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

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

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER) {

        if (f == *NUMBER_1_INTEGER) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, *k, *kc, *ks, *s, *sc, *ss, (void*) &f,
            (void*) signal_memory_irq, (void*) signal_memory_mutex,
            (void*) gnu_linux_console_irq, (void*) gnu_linux_console_mutex,
            (void*) x_window_system_irq, (void*) x_window_system_mutex,
            (void*) www_service_irq, (void*) www_service_mutex,
            (void*) cyboi_service_irq, (void*) cyboi_service_mutex,
            (void*) m, (void*) mc, (void*) ms, (void*) d, (void*) dc, (void*) ds,
            (void*) c, (void*) cc, (void*) l, (void*) lc, (void*) st, (void*) stc,
            (void*) b, (void*) bc, (void*) bs);
    }
}

/* CHECKER_SOURCE */
#endif
