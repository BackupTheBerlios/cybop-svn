/*
 * $RCSfile: checker.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.15 $ $Date: 2006-02-20 16:17:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Rolf Holzmueller <rolf.holzmueller@gmx.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

/*?? A simple sleep(1) is used instead of signals now!
#include <signal.h>
*/
#include "../controller/handler.c"
#include "../globals/constants/integer_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/variables/variables.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/signal_memory_accessor.c"

/**
 * Reacts to interrupt request by setting the corresponding flag.
 *
 * @param p0 the signal numeric code
 */
/*?? A simple sleep(1) is used instead of signals now!
void interrupt_request_handler(int p0) {

    // Set interrupt request flag.
    *INTERRUPT_REQUEST = *NUMBER_1_INTEGER;
}
*/

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
 * @param p7 the signal memory blocked flag
 * @param p8 the interrupt request flag
 */
void check(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != NULL_POINTER) {

        int* irq = (int*) p8;

        if (p7 != NULL_POINTER) {

            int* smb = (int*) p7;

            log_message_debug("\n\n");
            log_message((void*) INFO_LOG_LEVEL, (void*) CHECK_FOR_SIGNALS_MESSAGE, (void*) CHECK_FOR_SIGNALS_MESSAGE_COUNT);

            // The shutdown flag.
            int f = *NUMBER_0_INTEGER;
            // The abstraction.
            void** a = &NULL_POINTER;
            void** ac = &NULL_POINTER;
            // The model (signal operation).
            void** m = &NULL_POINTER;
            void** mc = &NULL_POINTER;
            // The details (parameters).
            void** d = &NULL_POINTER;
            void** dc = &NULL_POINTER;
            // The priority.
            void** p = &NULL_POINTER;
            // The signal id.
            void** id = &NULL_POINTER;
            // The direct execution flag.
            int x = *NUMBER_0_INTEGER;
            // The highest priority index.
            int i = -1;
            // The comparison result.
            int r = *NUMBER_0_INTEGER;

            //?? TODO: Delete this testing stuff from Rolf Holzmueller.
            // The interrupt flag.
            void** sf = &NULL_POINTER;
            // The blocking flag.
            void** bf = &NULL_POINTER;

            // Run endless loop checking signal memory for signals.
            while (*NUMBER_1_INTEGER) {

                if (f == *NUMBER_1_INTEGER) {

                    // Leave loop if shutdown flag was set.
                    break;
                }

                // Get index of the top priority signal.
                get_highest_priority_index(p4, p5, (void*) &i);

/*??
                //?? Wait for web input, if no signal is in memory.
                //?? TODO: Use a thread for this!
                //?? Testing from Rolf Holzmueller.
                get(p0, (void*) TCP_SOCKET_INTERRUPT_INTERNAL, (void*) &sf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
                get(p0, (void*) TCP_SOCKET_BLOCKING_INTERNAL, (void*) &bf, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

//??                if ((sf != NULL_POINTER) && (bf != NULL_POINTER)) {

                    if ((*sf != NULL_POINTER) && (*bf != NULL_POINTER)) {

                        if ((**((int**) sf) == 0) && (i < 0) && (**((int**) bf) == 1)) {

//??                            run_tcp_socket(p0);
                        }
                    }
//??                }
*/

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

/*??
        //?? TEST
        fprintf(stderr, "TEST checker k: %i\n", p1);
        test_knowledge_memory(p1, p2, 5);
*/

                    // Handle signal.
                    handle(p0, p1, p2, p3, p4, p5, p6, p7, p8,
                        (void*) &f, *a, *ac, *m, *mc, *d, *dc, *p, *id, &x);

                    // Wait while signal memory is blocked.
                    while (*smb != *NUMBER_0_INTEGER) {

                        sleep(1);
                    }

                    // Block signal memory.
                    *smb = *NUMBER_1_INTEGER;

                    // Remove signal from signal memory.
                    remove_signal(p4, p5, p6, (void*) &i);

                    // Unblock signal memory.
                    *smb = *NUMBER_0_INTEGER;

                    // CAUTION! Do NOT destroy the signal's abstraction or model here!
                    // A signal only encapsulates an abstraction and a logic model,
                    // which are stored in the knowledge tree.
                    // That knowledge tree and all its models get created at
                    // system startup and destroyed at system shutdown.

                    // CAUTION! Do NOT destroy the signal priority!
                    // It is a FIXED system constant.

                    // Destroy signal id.
                    // CAUTION! Do NOT hand over as reference!
                    // The id was read from signal memory and is of type void**.
                    // The expression (&*id) is the same like (id).
//??                    fprintf(stderr, "TEST check pre integer destroy i: %i\n", i);
//??                    deallocate((void*) id, (void*) PRIMITIVE_COUNT, (void*) INTEGER_VECTOR_ABSTRACTION, (void*) INTEGER_VECTOR_ABSTRACTION_COUNT);
//??                    fprintf(stderr, "TEST check post integer destroy i: %i\n", i);

                    // Reset abstraction.
                    a = &NULL_POINTER;
                    ac = &NULL_POINTER;
                    // Reset model (signal operation).
                    m = &NULL_POINTER;
                    mc = &NULL_POINTER;
                    // Reset details (parameters).
                    d = &NULL_POINTER;
                    dc = &NULL_POINTER;
                    // Reset priority.
                    p = &NULL_POINTER;
                    // Reset main signal id.
                    id = &NULL_POINTER;
                    // Reset direct execution flag.
                    x = *NUMBER_0_INTEGER;
                    // Reset highest priority index.
                    i = -1;
                    // Reset comparison result.
                    r = *NUMBER_0_INTEGER;

                    //?? Reset. TODO: Delete this testing stuff from Rolf Holzmueller.
                    sf = &NULL_POINTER;
                    bf = &NULL_POINTER;

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
                    // = Solution in CYBOI
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
                    // a global flag has to be used, which is undesirable.
                    //
                    // Therefore, the decision fell on the usage of a simple SLEEP
                    // procedure, which seems sufficient for the purposes of CYBOI.
                    //

                    // Reset interrupt request flag.
                    *irq = *NUMBER_0_INTEGER;

                    // Sleep for some time.
                    sleep(1);

/*?? A simple sleep(1) is used instead of signals now!
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
                    act.sa_handler = interrupt_request_handler;
                    act.sa_mask = mask;
                    act.sa_flags = 0;

                    // Establish old signal handler.
                    oldact.sa_mask = oldmask;

                    // Set up a new action for the SIGIO signal.
                    sigaction(SIGIO, &act, NULL_POINTER);

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
                    while (*INTERRUPT_REQUEST == *NUMBER_0_INTEGER) {

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
                    sigprocmask(SIG_UNBLOCK, &mask, NULL_POINTER);
*/
                }
            }

        } else {

            log_message_debug("Could not check for signals. The signal memory blocked flag is null.");
        }

    } else {

        log_message_debug("Could not check for signals. The interrupt request flag is null.");
    }
}

/* CHECKER_SOURCE */
#endif
