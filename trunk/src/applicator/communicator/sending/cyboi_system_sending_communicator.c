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
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.3 $ $Date: 2008-09-06 23:17:19 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SYSTEM_SENDER_SOURCE
#define CYBOI_SYSTEM_SENDER_SOURCE

#include <signal.h>
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"

/**
 * Sends a message to the cyboi system (this system itself).
 *
 * @param p0 the internal memory
 * @param p1 the signal memory
 * @param p2 the signal memory count
 * @param p3 the signal memory size
 * @param p4 the message abstraction (Hand over as reference!)
 * @param p5 the message abstraction count (Hand over as reference!)
 * @param p6 the message model (Hand over as reference!)
 * @param p7 the message model count (Hand over as reference!)
 * @param p8 the message details (Hand over as reference!)
 * @param p9 the message details count (Hand over as reference!)
 * @param p10 the signal priority (Hand over as reference!)
 * @param p11 the signal identification (Hand over as reference!)
 */
void send_cyboi_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Send message to cyboi system.");

    // The signal memory mutex.
    pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER_MEMORY_MODEL;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) NULL_POINTER_MEMORY_MODEL;

    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) &mt, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get_element(p0, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) &irq, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION, (void*) POINTER_VECTOR_MEMORY_ABSTRACTION_COUNT);

    // Lock signal memory mutex.
    pthread_mutex_lock(*mt);

    set_signal(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    **irq = *NUMBER_1_INTEGER_MEMORY_MODEL;

    // Unlock signal memory mutex.
    pthread_mutex_unlock(*mt);
}

/* CYBOI_SYSTEM_SENDER_SOURCE */
#endif
