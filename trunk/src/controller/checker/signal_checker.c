/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef SIGNAL_CHECKER_SOURCE
#define SIGNAL_CHECKER_SOURCE

#include <pthread.h>

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../controller/checker/interrupt_checker.c"
#include "../../controller/checker/wait_checker.c"
#include "../../controller/handler.c"
#include "../../executor/accessor/getter/signal_memory_getter.c"
#include "../../executor/accessor/remover/signal_memory_remover.c"
#include "../../executor/accessor/getter.c"
#include "../../logger/logger.c"

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
    get(p0, p13, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    // Get signal memory mutex.
    get(p1, p13, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    // Get signal.
    get_signal(p10, p11, p12, p2, p3, p4, p5, p6, p7, p8, p9);
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
    get_highest_priority_signal_index((void*) &i, p4, p5);

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

//??    fwprintf(stdout, L"TEST index of signal with highest priority: %i\n", i);

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        // Get signal at given index.
        check_get((void*) &irq, (void*) &mt, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc,
            (void*) &d, (void*) &dc, (void*) &p, (void*) &id, p4, p5, (void*) &i, p0);

/*??
    fwprintf(stdout, L"TEST checker signal ac: %i\n", **((int**) ac));
    fwprintf(stdout, L"TEST checker signal a: %ls\n", (wchar_t*) *a);
    fwprintf(stdout, L"TEST checker signal mc: %i\n", **((int**) mc));
    fwprintf(stdout, L"TEST checker signal m: %ls\n", (wchar_t*) *m);
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
        check_interrupt((void*) &irq, (void*) &mt, (void*) &a, (void*) &ac, (void*) &m, (void*) &mc, (void*) &d, (void*) &dc, p0);

/*??
    fwprintf(stdout, L"TEST checker irq: %i\n", *irq);
    fwprintf(stdout, L"TEST checker handler ac: %i\n", *ac);
    fwprintf(stdout, L"TEST checker handler a: %i\n", *a);
    fwprintf(stdout, L"TEST checker handler mc: %i\n", *mc);
    fwprintf(stdout, L"TEST checker handler m: %i\n", *m);
*/

        // CAUTION! These conditions have to be CONNECTED by a boolean AND operator,
        // because otherwise, the "else" branch below would not always be reached.
        if ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

/*??
    fwprintf(stdout, L"TEST checker irq pre reset: %i\n", *((int*) *irq));
    fwprintf(stdout, L"TEST checker irq ac: %i\n", *ac);
    fwprintf(stdout, L"TEST checker irq a: %ls\n", (wchar_t*) *a);
    //?? Signal memory interrupts do NOT have an abstraction, model, details!
*/

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

/* SIGNAL_CHECKER_SOURCE */
#endif
