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
 * Checks for a signal.
 *
 * There are various possibilities to process signals:
 *
 * 1 Signals - Interrupts
 *
 * First process all signals found in the signal memory
 * and only then check interrupts for new input.
 * The drawback of this solution is that the processing of a signal with
 * a long processing time cannot be interrupted by a key press or mouse click,
 * since these are not recognised as long as the interrupt flags are not checked.
 *
 * 2 Interrupts - Signals
 *
 * First check for and process all interrupts
 * and only then process the signals found in signal memory.
 * The drawback here might be that the system never comes to processing signals,
 * for example when acting as web server with thousands of client requests.
 * In this case, the client requests in form of socket interrupts would be
 * processed on and on and only if no more client requests could be found,
 * the actual signals in the signal memory would be processed.
 *
 * Further alternatives are welcome!
 *
 * The current solution implemented here is number 1.
 * An alternative for the future might be number 2
 * (just exchange the following two if-else blocks of source code).
 *
 * @param p0 the shutdown flag
 * @param p1 the signal memory item
 * @param p2 the signal memory sleep time
 * @param p3 the knowledge memory part
 * @param p4 the internal memory array
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"\n\n");
    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for signal with highest priority and otherwise, for interrupts.");

    // The signal.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The interrupt request.
    // CAUTION! It CANNOT be handed over as parametre, since it
    // is not always only the signal memory interrupt request.
    // Other input channels' interrupts may be assigned as well below.
    void* irq = *NULL_POINTER_MEMORY_MODEL;
    // The mutex.
    // CAUTION! It CANNOT be handed over as parametre,
    // just like the interrupt request.
    void* mt = *NULL_POINTER_MEMORY_MODEL;
    // The direct execution flag.
    int x = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Get next signal to be processed from position index zero.
    // CAUTION! The signal memory item's count is checked inside
    // this function. If it is smaller or equal to the given index
    // (here: zero), then the signal value s is NOT changed,
    // i.e. it remains NULL if initialised so before.
    get_item_element((void*) &s, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);

    if (s != *NULL_POINTER_MEMORY_MODEL) {

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        // Get interrupt request.
        copy_array_forward((void*) &irq, p4, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
        // Get mutex.
        copy_array_forward((void*) &mt, p4, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);

        // Lock signal memory mutex.
        pthread_mutex_lock(mt);

        // Remove signal from signal memory.
        remove_item(p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        // Unlock signal memory mutex.
        pthread_mutex_unlock(mt);

        // Handle signal.
        handle(s, (void*) &x, p0, p3, p4, p1, irq, mt);

    } else {

        // The signal memory is empty, so that the cyboi system
        // may check for new interrupt requests now.

        // Check interrupt requests and get the appropriate:
        // - interrupt request (to be reset below)
        // - mutex (to be blocked while resetting the interrupt request below)
        // - handler (the signal to be forwarded to the "handle" function below)
        check_interrupt((void*) &irq, (void*) &mt, (void*) &s, p4);

        // CAUTION! These conditions HAVE TO BE connected by a boolean AND operator,
        // because otherwise, the "else" branch below would not always be reached.
        if ((irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) irq) != *NUMBER_0_INTEGER_MEMORY_MODEL)) {

            // Lock mutex.
            pthread_mutex_lock(mt);

            // Reset interrupt request.
            //
            // The interrupt is reset to zero here because its purpose
            // of receiving data over some device in order to handle
            // the corresponding signal is fulfilled.
            //
            // This is done here, right after checking the interrupt flag
            // and yet BEFORE receiving data and handling the signal below,
            // so that the system may react faster to new interrupt requests.
            copy_integer(irq, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

            // Unlock mutex.
            pthread_mutex_unlock(mt);

            // Handle signal.
            //
            // CAUTION! The "handle" function has to be called DIRECTLY
            // (with direct execution flag set) here!
            // For reasons, see the comment block above!
            handle(s, (void*) &x, p0, p3, p4, p1, irq, mt);

            // CAUTION! An interrupt request was detected and the corresponding data received.
            // It is therefore VERY likely that new signals have been generated while handling the data.
            // The cyboi system is therefore NOT sent to sleep, so that possibly existing
            // signals may be handled in the next iteration of the signal checker loop.

        } else {

            // No interrupt request was detected, so that the cyboi system
            // can be sent to sleep now, in order to save cpu time.

            check_wait(p2, p4);
        }
    }

    //
    // CAUTION! Do NOT destroy here the signal or its parts!
    // A signal ONLY ENCAPSULATES an abstraction and a logic model,
    // which are stored in the knowledge tree.
    // That knowledge tree and its parts get created at
    // system startup or later and destroyed when processing a
    // corresponding CYBOL operation, or at system shutdown.
    //
}

/* SIGNAL_CHECKER_SOURCE */
#endif
