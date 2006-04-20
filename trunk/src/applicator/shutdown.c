/*
 * $RCSfile: shutdown.c,v $
 *
 * Copyright (c) 1999-2006. Christian Heller and the CYBOP developers.
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
 * @version $Revision: 1.10 $ $Date: 2006-04-20 22:36:09 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module shuts down a service.
 */

#ifndef SHUTDOWN_SOURCE
#define SHUTDOWN_SOURCE

#include "../applicator/shutdown/shutdown_linux_console.c"
#include "../applicator/shutdown/shutdown_tcp_socket.c"
#include "../applicator/shutdown/shutdown_unix_socket.c"
#include "../applicator/shutdown/shutdown_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/array.c"

/**
 * Shuts down a service.
 *
 * Expected parameters:
 * - service: linux_console, tcp_socket, unix_socket, x_window_system
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the internal memory
 */
void shutdown_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_debug("Shutdown service.");

    // The service abstraction.
    void** sa = &NULL_POINTER;
    void** sac = &NULL_POINTER;
    void** sas = &NULL_POINTER;
    // The service model.
    void** sm = &NULL_POINTER;
    void** smc = &NULL_POINTER;
    void** sms = &NULL_POINTER;
    // The service details.
    void** sd = &NULL_POINTER;
    void** sdc = &NULL_POINTER;
    void** sds = &NULL_POINTER;

    // Get parameters.
    get_real_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // The comparison result.
    int r = 0;

    // Reset comparison result.
    r = 0;

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            shutdown_linux_console(p5, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) UNIX_SOCKET_MODEL, (void*) UNIX_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            shutdown_unix_socket(p5, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) TCP_SOCKET_MODEL, (void*) TCP_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            shutdown_tcp_socket(p5, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            shutdown_x_window_system(p5, p2, p3, p4);
        }
    }
}

/* SHUTDOWN_SOURCE */
#endif
