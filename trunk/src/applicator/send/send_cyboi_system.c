/*
 * $RCSfile: send_cyboi_system.c,v $
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
 * @version $Revision: 1.8 $ $Date: 2007-08-17 04:06:51 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEND_CYBOI_SYSTEM_SOURCE
#define SEND_CYBOI_SYSTEM_SOURCE

#include <signal.h>
#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../globals/constants/log/log_message_constants.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../globals/constants/pointer/pointer_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/accessor/signal_memory_accessor.c"
#include "../../memoriser/accessor.c"

/**
 * Sends a message to the cyboi system (this system itself).
 *
 * @param p0 the internal memory
 * @param p1 the signal memory
 * @param p2 the signal memory count
 * @param p3 the signal memory size
 * @param p4 the message abstraction
 * @param p5 the message abstraction count
 * @param p6 the message model
 * @param p7 the message model count
 * @param p8 the message details
 * @param p9 the message details count
 * @param p10 the signal priority
 * @param p11 the signal identification
 */
void send_cyboi_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_debug("Information: Send message to cyboi system.");

    // The signal memory mutex.
    pthread_mutex_t** mt = (pthread_mutex_t**) NULL_POINTER;
    // The interrupt request flag.
    sig_atomic_t** irq = (sig_atomic_t**) NULL_POINTER;

    // Get signal memory mutex.
    get_element(p0, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL, (void*) &mt, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);
    // Get interrupt request internal.
    get_element(p0, (void*) INTERRUPT_REQUEST_INTERNAL, (void*) &irq, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

    // Lock signal memory mutex.
    pthread_mutex_lock(*mt);

    set_signal(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    **irq = *NUMBER_1_INTEGER;

    // Unlock signal memory mutex.
    pthread_mutex_unlock(*mt);
}

/* SEND_CYBOI_SYSTEM_SOURCE */
#endif
