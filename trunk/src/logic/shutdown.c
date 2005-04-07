/*
 * $RCSfile: shutdown.c,v $
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
 * @version $Revision: 1.5 $ $Date: 2005-04-07 22:53:47 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module shuts down a service.
 */

#ifndef SHUTDOWN_SOURCE
#define SHUTDOWN_SOURCE

#include "../array/array.c"
#include "../global/abstraction_constants.c"
#include "../global/log_constants.c"
#include "../global/name_constants.c"
#include "../logger/logger.c"
#include "../logic/shutdown/shutdown_tcp_socket.c"
#include "../logic/shutdown/shutdown_x_window_system.c"

/**
 * Shuts down a service.
 *
 * Expected parameters:
 * - service: unix_socket, tcp_socket, x_window_system, ms_windows
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge
 * @param p3 the knowledge count
 * @param p4 the knowledge size
 * @param p5 the internals
 */
void shutdown_service(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, void* p5) {

    log_message_debug("Shutdown.");

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

/*??
    // Get parameters.
    get_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds);

    // The comparison result.
    int r = 0;

    // Get service.
    if (r != 1) {

        compare_arrays((void*) *sa, (void*) *sac, (void*) STRING_ABSTRACTION, (void*) STRING_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            get_compound_element_by_name(p0, p1,
                (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds);
        }
    }

    if (r != 1) {

        compare_arrays((void*) *sa, (void*) *sac, (void*) KNOWLEDGE_ABSTRACTION, (void*) KNOWLEDGE_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            get_compound_element_by_encapsulated_name(p0, p1,
                (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
                (void*) &sa, (void*) &sac, (void*) &sas,
                (void*) &sm, (void*) &smc, (void*) &sms,
                (void*) &sd, (void*) &sdc, (void*) &sds,
                p2, p3);
        }
    }

    // Only shutdown x window system, if a correct abstraction was found above.
    if (r == 1) {

        // Reset comparison result.
        r = 0;

        if (r != 1) {

            compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_ABSTRACTION, (void*) X_WINDOW_SYSTEM_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 1) {

                shutdown_x_window_system(p5, p2, p3, p4);
            }
        }

        if (r != 1) {

            compare_arrays((void*) *sm, (void*) *smc, (void*) TCP_SERVER_SOCKET_ABSTRACTION, (void*) TCP_SERVER_SOCKET_ABSTRACTION_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

            if (r == 1) {

                shutdown_x_window_system(p5, p2, p3, p4);
            }
        }
    }
*/
}

/* SHUTDOWN_SOURCE */
#endif
