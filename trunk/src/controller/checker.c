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
 * @version $Revision: 1.29 $ $Date: 2007-08-17 03:15:31 $ $Author: christian $
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
 * Checks for signals.
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

    if (p7 != *NULL_POINTER) {

        int* irq = (int*) p7;

        log_message_debug("\n\n");
        log_message((void*) INFORMATION_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

        // The shutdown flag.
        int f = *NUMBER_0_INTEGER;
        // The abstraction.
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        // The model (signal operation).
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        // The details (parameters).
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        // The priority.
        void** p = NULL_POINTER;
        // The signal id.
        void** id = NULL_POINTER;
        // The direct execution flag.
        int x = *NUMBER_0_INTEGER;
        // The highest priority index.
        int i = *NUMBER_MINUS_1_INTEGER;
        // The comparison result.
        int r = *NUMBER_0_INTEGER;

        // Run endless loop checking signal memory for signals.
        while (*NUMBER_1_INTEGER) {

            if (f == *NUMBER_1_INTEGER) {

                // Leave loop if shutdown flag was set.
                break;
            }

            // Get index of the top priority signal.
            get_highest_priority_index(p4, p5, (void*) &i);

            if (i >= *NUMBER_0_INTEGER) {

                // Get signal.
                get_signal(p4, p5, (void*) &i,
                    (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
                    (void*) &d, (void*) &dc, (void*) &p, (void*) &id);

/*??
    //?? For testing only. TODO: Delete these lines later!
    fprintf(stderr, "check i: %i\n", i);
    fprintf(stderr, "check a: %s\n", (char*) *a);
    fprintf(stderr, "check ac: %i\n", *((int*) *ac));
    fprintf(stderr, "check m: %s\n", (char*) *m);
    fprintf(stderr, "check mc: %i\n", *((int*) *mc));
    //?? d and dc are NULL. DO NOT try to print their values here!
    fprintf(stderr, "check p: %i\n", *((int*) *p));
    fprintf(stderr, "check id: %i\n", *((int*) *id));
*/

    //?? TEST
//??    fprintf(stderr, "TEST checker k: %i\n", p1);
//??    test_knowledge_memory(p1, p2, 5);

                // Lock signal memory mutex.
                pthread_mutex_lock((pthread_mutex_t*) p8);

                // Remove signal from signal memory.
                remove_signal(p4, p5, p6, (void*) &i);

                // Unlock signal memory mutex.
                pthread_mutex_unlock((pthread_mutex_t*) p8);

                //?? CAUTION! TODO? UNCERTAIN!
                //?? The handle procedure possibly needs to stand
                //?? BEFORE the remove_signal procedure.
                //?? This was so before and might be necessary for TCP sockets
                //?? which rely on the parent signal still being in the signal memory.

                // Handle signal.
                handle(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                    (void*) &f, *a, *ac, *m, *mc, *d, *dc, *p, *id, &x);

                // CAUTION! Do NOT destroy the signal's abstraction or model here!
                // A signal only encapsulates an abstraction and a logic model,
                // which are stored in the knowledge tree.
                // That knowledge tree and all its models get created at
                // system startup or later and destroyed at system shutdown.

                // CAUTION! Do NOT destroy the signal priority!
                // It is a FIXED system constant.

                // Deallocate signal id.
                // CAUTION! Do NOT hand over as reference!
                // The id was read from signal memory and is of type void**.
                // The expression (&*id) is the same like (id).
/*??
                //?? TODO: For some reason, signals are not  processed properly
                //?? (wrong signal abstraction), if deallocating the signal id.
                fprintf(stderr, "TEST check pre integer destroy id: %i\n", **((int**) id));
                deallocate((void*) id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
                fprintf(stderr, "TEST check post integer destroy id: %i\n", *((int*) *id));
*/

                // Reset abstraction.
                a = NULL_POINTER;
                ac = NULL_POINTER;
                // Reset model (signal operation).
                m = NULL_POINTER;
                mc = NULL_POINTER;
                // Reset details (parameters).
                d = NULL_POINTER;
                dc = NULL_POINTER;
                // Reset priority.
                p = NULL_POINTER;
                // Reset main signal id.
                id = NULL_POINTER;
                // Reset direct execution flag.
                x = *NUMBER_0_INTEGER;
                // Reset highest priority index.
                i = *NUMBER_MINUS_1_INTEGER;
                // Reset comparison result.
                r = *NUMBER_0_INTEGER;

            } else {

                // The signal memory is empty,
                // so that the CYBOP system can be sent to sleep,
                // in order to save CPU time.

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

                    sleep(CHECKER_SLEEP_TIME);
                }

                // Lock signal memory mutex.
                pthread_mutex_lock((pthread_mutex_t*) p8);

                // Reset interrupt request flag.
                // The interrupt is reset to zero here because its purpose of
                // leaving the endless (sleep) loop above is fulfilled.
                // The signal checker is notified and will now start to handle
                // all signals found in the signal memory, until that is empty
                // and the endless loop waiting for an interrupt is entered again.
                *irq = *NUMBER_0_INTEGER;

                // Unlock signal memory mutex.
                pthread_mutex_unlock((pthread_mutex_t*) p8);
            }
        }

    } else {

        log_message_debug("Could not check for signals. The interrupt request flag is null.");
    }
}

/* CHECKER_SOURCE */
#endif
