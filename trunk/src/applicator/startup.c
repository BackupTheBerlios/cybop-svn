/*
 * $RCSfile: startup.c,v $
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
 * @version $Revision: 1.3 $ $Date: 2005-07-08 16:24:21 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module starts up a service.
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../applicator/startup/startup_tcp_socket.c"
#include "../applicator/startup/startup_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/constant.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array/array.c"
#include "../memoriser/creator/creator.c"

/**
 * Starts up a service.
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
void startup_service(const void* p0, const void* p1,
    const void* p2, const void* p3, const void* p4, void* p5) {

    log_message_debug("Startup service.");

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

    // The socket port abstraction.
    void** spa = NULL_POINTER;
    void** spac = NULL_POINTER;
    void** spas = NULL_POINTER;
    // The socket port model.
    void** spm = NULL_POINTER;
    void** spmc = NULL_POINTER;
    void** spms = NULL_POINTER;
    // The socket port details.
    void** spd = NULL_POINTER;
    void** spdc = NULL_POINTER;
    void** spds = NULL_POINTER;

    // Get parameters.
    get_real_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get parameters.
    get_real_compound_element_by_name(p0, p1,
        (void*) PORT_NAME, (void*) PORT_NAME_COUNT,
        (void*) &spa, (void*) &spac, (void*) &spas,
        (void*) &spm, (void*) &spmc, (void*) &spms,
        (void*) &spd, (void*) &spdc, (void*) &spds,
        p2, p3);

    // The comparison result.
    int r = 0;

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            startup_x_window_system(p5, p2, p3, p4);
        }
    }

    if (r != 1) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r == 1) {

            if (    (spa != NULL_POINTER)
                 && (spac != NULL_POINTER)
                 && (spm != NULL_POINTER)
                 && (spmc != NULL_POINTER) )
            {

                startup_tcp_socket( p5, p2, p3, p4,
                                    *spa, *spac, *spm, *spmc );
            }
            else {

                log_message_debug( "the socket port ist a null pointer" );
            }
        }
    }
}

/* STARTUP_SOURCE */
#endif