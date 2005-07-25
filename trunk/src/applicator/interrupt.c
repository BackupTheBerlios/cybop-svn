/*
 * $RCSfile: interrupt.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-07-25 21:01:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERUPT_SOURCE
#define INTERUPT_SOURCE

#include "../applicator/interrupt/interrupt_tcp_socket.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../socket/unix_socket.c"

/**
 * Interupt a service.
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the internals
 */
void interupt_service(void* p0, void* p1,
    void* p2, void* p3, void* p4, void* p5) {

    // The service abstraction.
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    // The service model.
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    // The service details.
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;

    // Get service.
    get_real_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3 );

    // The comparison result.
    int r = 0;

/*??
    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TUI_ABSTRACTION, (void*) TUI_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

        }
    }

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {
        }
    }
*/

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) UNIX_SOCKET_CHANNEL, (void*) UNIX_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

        }
    }

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TCP_SOCKET_CHANNEL, (void*) TCP_SOCKET_CHANNEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            interrupt_tcp_socket( p5, p2, p3, p4 );
        }
    }
}

/* INTERUPT_SOURCE */
#endif
