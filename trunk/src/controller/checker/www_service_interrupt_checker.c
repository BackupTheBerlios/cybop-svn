/*
 * $RCSfile: www_service_interrupt_checker.c,v $
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

#ifndef WWW_SERVICE_INTERRUPT_CHECKER_SOURCE
#define WWW_SERVICE_INTERRUPT_CHECKER_SOURCE

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
 * Checks for a www service interrupt request.
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
 * @param p10 the www service interrupt request flag
 * @param p11 the www service mutex
 */
/*??
void check_www_service_interrupt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6,
    void* p7, void* p8, void* p9, void* p10, void* p11) {

    // Receive data via www service.
    receive_socket();

    // Handle signal.
    handle(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, *a, *ac, *m, *mc, *d, *dc, p, id, &x);

    // Reset gnu/linux console interrupt request.
    *www_service_irq = *NUMBER_0_INTEGER;
}
*/

/* WWW_SERVICE_INTERRUPT_CHECKER_SOURCE */
#endif
