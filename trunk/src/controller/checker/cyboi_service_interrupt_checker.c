/*
 * $RCSfile: cyboi_service_interrupt_checker.c,v $
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
 * @version $Revision: 1.1 $ $Date: 2007-12-01 23:57:41 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CYBOI_SERVICE_INTERRUPT_CHECKER_SOURCE
#define CYBOI_SERVICE_INTERRUPT_CHECKER_SOURCE

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
 * Checks for a cyboi service interrupt request.
 *
 * @param p0 the internal memory
 * @param p1 the knowledge memory
 * @param p2 the knowledge memory count
 * @param p3 the knowledge memory size
 * @param p4 the signal memory
 * @param p5 the signal memory count
 * @param p6 the signal memory size
 * @param p7 the shutdown flag
 * @param p8 the cyboi service interrupt request flag
 * @param p9 the cyboi service mutex
 * @param p10 the action name (Hand over as reference!)
 * @param p11 the action name count
 * @param p12 the action name size
 * @param p13 the action abstraction (Hand over as reference!)
 * @param p14 the action abstraction count
 * @param p15 the action abstraction size
 * @param p16 the action model (Hand over as reference!)
 * @param p17 the action model count
 * @param p18 the action model size
 * @param p19 the action details (Hand over as reference!)
 * @param p20 the action details count
 * @param p21 the action details size
 * @param p22 the model
 * @param p23 the model count
 * @param p24 the model size
 * @param p25 the details
 * @param p26 the details count
 * @param p27 the details size
 * @param p28 the commands
 * @param p29 the commands count
 * @param p30 the language
 * @param p31 the language count
 * @param p32 the style
 * @param p33 the style count
 * @param p34 the buffer (Hand over as reference!)
 * @param p35 the buffer count
 * @param p36 the buffer size
 */
/*??
void check_cyboi_service_interrupt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9,
    void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21,
    void* p22, void* p23, void* p24, void* p25, void* p26, void* p27, void* p28, void* p29, void* p30, void* p31, void* p32, void* p33,
    void* p34, void* p35, void* p36) {

    if (p9 != *NULL_POINTER) {

        int* mt = (int*) p9;

        if (p8 != *NULL_POINTER) {

            int* irq = (int*) p8;

            // Receive data via cyboi service.
            receive_socket(p22, p23, p24, p25, p26, p27, p28, p29, p30, p31, p32, p33, p1, p2);

            // Lock cyboi service mutex.
            pthread_mutex_lock(mt);

            // Reset cyboi service interrupt request.
            //
            // The interrupt is reset to zero here because its purpose of
            // leaving the endless (sleep) loop above is fulfilled.
            // The signal checker is notified and will now start to handle
            // all signals found in the signal memory, until that is empty
            // and this endless loop waiting for an interrupt is entered again.
            *irq = *NUMBER_0_INTEGER;

            // Unlock cyboi service mutex.
            pthread_mutex_unlock(mt);

        } else {

            log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check cyboi service interrupt. The cyboi service interrupt request flag is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LOG_LEVEL, (void*) "Could not check cyboi service interrupt. The cyboi service mutex is null.");
    }
}
*/

/* CYBOI_SERVICE_INTERRUPT_CHECKER_SOURCE */
#endif
