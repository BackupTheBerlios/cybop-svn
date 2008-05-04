/*
 * $RCSfile: signal_memory_interrupt_checker.c,v $
 *
 * Copyright (c) 1999-2008. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.2 $ $Date: 2008-05-04 00:18:11 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_INTERRUPT_CHECKER_SOURCE
#define SIGNAL_MEMORY_INTERRUPT_CHECKER_SOURCE

/*??
#include "../controller/handler.c"
#include "../globals/constants/integer/integer_constants.c"
#include "../globals/constants/log/log_message_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
#include "../globals/logger/logger.c"
#include "../globals/variables/sleep_time_variables.c"
#include "../memoriser/accessor/signal_memory_accessor.c"
*/

/**
 * Checks for a signal memory interrupt request.
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
 */
/*??
void check_signal_memory_interrupt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p9 != *NULL_POINTER) {

        int* mt = (int*) p9;

        if (p8 != *NULL_POINTER) {

            int* irq = (int*) p8;

            // Receive data via signal memory.
            receive_signal_memory();

            // Lock signal memory mutex.
            pthread_mutex_lock(mt);

            // Reset signal memory interrupt request.
            //
            // The interrupt is reset to zero here because its purpose of
            // leaving the endless (sleep) loop above is fulfilled.
            // The signal checker is notified and will now start to handle
            // all signals found in the signal memory, until that is empty
            // and this endless loop waiting for an interrupt is entered again.
            *irq = *NUMBER_0_INTEGER;

            // Unlock signal memory mutex.
            pthread_mutex_unlock(mt);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not check signal memory interrupt. The signal memory interrupt request flag is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) L"Could not check signal memory interrupt. The signal memory mutex is null.");
    }
}
*/

/* SIGNAL_MEMORY_INTERRUPT_CHECKER_SOURCE */
#endif
