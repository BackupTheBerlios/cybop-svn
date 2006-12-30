/*
 * $RCSfile: startup.c,v $
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
 * @version $Revision: 1.22 $ $Date: 2006-12-30 13:42:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module starts up a service.
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../applicator/startup/startup_linux_console.c"
#include "../applicator/startup/startup_socket.c"
#include "../applicator/startup/startup_x_window_system.c"
#include "../globals/constants/abstraction_constants.c"
#include "../globals/constants/channel_constants.c"
#include "../globals/constants/log_constants.c"
#include "../globals/constants/model_constants.c"
#include "../globals/constants/name_constants.c"
#include "../globals/constants/service_port_constants.c"
#include "../globals/constants/structure_constants.c"
#include "../globals/logger/logger.c"
#include "../memoriser/accessor/compound_accessor.c"
#include "../memoriser/array.c"
#include "../memoriser/allocator.c"

/**
 * Starts up a service.
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
void startup_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_debug("Startup service.");

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

    // The socket namespace abstraction.
    void** na = &NULL_POINTER;
    void** nac = &NULL_POINTER;
    void** nas = &NULL_POINTER;
    // The socket namespace model.
    void** nm = &NULL_POINTER;
    void** nmc = &NULL_POINTER;
    void** nms = &NULL_POINTER;
    // The socket namespace details.
    void** nd = &NULL_POINTER;
    void** ndc = &NULL_POINTER;
    void** nds = &NULL_POINTER;

    // The communication style abstraction.
    void** sta = &NULL_POINTER;
    void** stac = &NULL_POINTER;
    void** stas = &NULL_POINTER;
    // The communication style model.
    void** stm = &NULL_POINTER;
    void** stmc = &NULL_POINTER;
    void** stms = &NULL_POINTER;
    // The communication style details.
    void** std = &NULL_POINTER;
    void** stdc = &NULL_POINTER;
    void** stds = &NULL_POINTER;

    // The host address abstraction.
    void** aa = &NULL_POINTER;
    void** aac = &NULL_POINTER;
    void** aas = &NULL_POINTER;
    // The host address model.
    void** am = &NULL_POINTER;
    void** amc = &NULL_POINTER;
    void** ams = &NULL_POINTER;
    // The host address details.
    void** ad = &NULL_POINTER;
    void** adc = &NULL_POINTER;
    void** ads = &NULL_POINTER;

    // Get service.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get socket namespace.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAMESPACE_NAME, (void*) SERVICE_NAMESPACE_NAME_COUNT,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // Get communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_STYLE_NAME, (void*) SERVICE_STYLE_NAME_COUNT,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p2, p3);

    // Get host address.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_ADDRESS_NAME, (void*) SERVICE_ADDRESS_NAME_COUNT,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // The comparison result.
    int r = 0;
    // The internal memory index.
    int i = *INVALID_VALUE;
    // The server socket internal.
    int** s = (int**) &NULL_POINTER;

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) LINUX_CONSOLE_MODEL, (void*) LINUX_CONSOLE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            startup_linux_console(p5, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_MODEL, (void*) X_WINDOW_SYSTEM_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            startup_x_window_system(p5, p2, p3, p4);
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) WWW_SERVICE_MODEL, (void*) WWW_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Get server socket internal.
            i = *WWW_BASE_INTERNAL + *SOCKET_INTERNAL;
            get(p5, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            if (*s == NULL_POINTER) {

                // Startup server socket if it does not already exist.
                startup_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) WWW_PORT, (void*) WWW_BASE_INTERNAL, p2, p3, p4);

            } else {

                log_message_debug("Warning: Could not start up service. The www service is already running.");
            }
        }
    }

/*??
    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) UNIX_SOCKET_MODEL, (void*) UNIX_SOCKET_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Get server socket internal.
            get(p5, (void*) WWW_SERVICE_SOCKET_INTERNAL, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            if (*s == NULL_POINTER) {

                // Startup server socket if it does not already exist.
                startup_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) WWW_PORT, (void*) SOME_LOCAL_UNIX_SERVICE_BASE_INTERNAL, p2, p3, p4);

            } else {

                log_message_debug("Warning: Could not start up service. The www service is already running.");
            }
        }
    }
*/
}

/* STARTUP_SOURCE */
#endif
