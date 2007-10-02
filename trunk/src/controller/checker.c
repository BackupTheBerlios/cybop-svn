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
 * @version $Revision: 1.32 $ $Date: 2007-10-02 21:16:36 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

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
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the shutdown flag
 * @param p10 the signal index
 */
void check_handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p8 != *NULL_POINTER) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p8;

        log_message_debug("Get and handle a signal.");

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

        // Get signal.
        get_signal(p4, p5, p10, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

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

        //?? CAUTION! TODO? UNCERTAIN!
        //?? The handle procedure possibly needs to stand
        //?? BEFORE the remove_signal procedure.
        //?? This was so before and might be necessary for TCP sockets
        //?? which rely on the parent signal still being in the signal memory.

        // Handle signal.
        handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

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

    } else {

        log_message_debug("Could not get and handle a signal. The signal memory mutex is null.");
    }
}

/**
 * Waits for an interrupt request.
 *
 * @param p0 the interrupt request flag
 * @param p1 the signal memory mutex
 */
void check_wait(void* p0, void* p1) {

    if (p1 != *NULL_POINTER) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p1;

        if (p0 != *NULL_POINTER) {

            int* irq = (int*) p0;

            log_message_debug("Wait for an interrupt request.");

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

            // Sleep for some time.
            while (*irq == *NUMBER_0_INTEGER) {

                sleep(*CHECKER_SLEEP_TIME);
            }

            // The sleep loop above is left as soon as the interrupt variable
            // is set to a value other than zero.
            // This may happen if some user action is noted in one of the
            // receive threads, e.g. linux console, x window system, tcp socket.
            // In this case, a signal is placed in the signal memory and
            // the interrupt variable is set to *NUMBER_1_INTEGER.

            // Lock signal memory mutex.
            pthread_mutex_lock(mt);

            // Reset interrupt request flag.
            // The interrupt is reset to zero here because its purpose of
            // leaving the endless (sleep) loop above is fulfilled.
            // The signal checker is notified and will now start to handle
            // all signals found in the signal memory, until that is empty
            // and this endless loop waiting for an interrupt is entered again.
            *irq = *NUMBER_0_INTEGER;

            // Unlock signal memory mutex.
            pthread_mutex_unlock(mt);

        } else {

            log_message_debug("Could not wait for an interrupt request. The interrupt request flag is null.");
        }

    } else {

        log_message_debug("Could not wait for an interrupt request. The signal memory mutex is null.");
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
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 * @param p9 the shutdown flag
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_debug("Check for signal with highest priority.");

    // The highest priority index.
    int i = *NUMBER_MINUS_1_INTEGER;

    // Get index of the top priority signal.
    get_highest_priority_signal_index(p4, p5, (void*) &i);

    if (i >= *NUMBER_0_INTEGER) {

        // A signal was found and has to be handled.

        check_handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, (void*) &i);

    } else {

        // The signal memory is empty,
        // so that the CYBOP system can be sent to sleep,
        // in order to save CPU time.

        check_wait(p7, p8);
    }
}

/**
 * Checks the signal memory for signals.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the interrupt request flag
 * @param p8 the signal memory mutex
 */
void check(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_debug("\n\n");
    log_message((void*) INFORMATION_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

    // The shutdown flag.
    int f = *NUMBER_0_INTEGER;

    // Run endless loop checking signal memory for signals.
    while (*NUMBER_1_INTEGER) {

        if (f == *NUMBER_1_INTEGER) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, p1, p2, p3, p4, p5, p6, p7, p8, (void*) &f);
    }
}

/* CHECKER_SOURCE */
#endif
