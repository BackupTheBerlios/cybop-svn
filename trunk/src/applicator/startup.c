/*
 * $RCSfile: startup.c,v $
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
 * @version $Revision: 1.27 $ $Date: 2007-05-16 19:29:01 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @description This module starts up a service.
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../applicator/startup/startup_linux_console.c"
#include "../applicator/startup/startup_socket.c"
#include "../applicator/startup/startup_x_window_system.c"
#include "../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../globals/constants/cybol/cybol_channel_constants.c"
#include "../globals/constants/log_message/log_message_constants.c"
#include "../globals/constants/cybol/cybol_model_constants.c"
#include "../globals/constants/cybol/cybol_name_constants.c"
#include "../globals/constants/service_port_constants.c"
#include "../globals/constants/memory_structure/memory_structure_constants.c"
#include "../globals/constants/pointer/pointer_constants.c"
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

    // The service name, abstraction, model, details.
    void** sn = NULL_POINTER;
    void** snc = NULL_POINTER;
    void** sns = NULL_POINTER;
    void** sa = NULL_POINTER;
    void** sac = NULL_POINTER;
    void** sas = NULL_POINTER;
    void** sm = NULL_POINTER;
    void** smc = NULL_POINTER;
    void** sms = NULL_POINTER;
    void** sd = NULL_POINTER;
    void** sdc = NULL_POINTER;
    void** sds = NULL_POINTER;
    // The socket namespace name, abstraction, model, details.
    void** nn = NULL_POINTER;
    void** nnc = NULL_POINTER;
    void** nns = NULL_POINTER;
    void** na = NULL_POINTER;
    void** nac = NULL_POINTER;
    void** nas = NULL_POINTER;
    void** nm = NULL_POINTER;
    void** nmc = NULL_POINTER;
    void** nms = NULL_POINTER;
    void** nd = NULL_POINTER;
    void** ndc = NULL_POINTER;
    void** nds = NULL_POINTER;
    // The communication style name, abstraction, model, details.
    void** stn = NULL_POINTER;
    void** stnc = NULL_POINTER;
    void** stns = NULL_POINTER;
    void** sta = NULL_POINTER;
    void** stac = NULL_POINTER;
    void** stas = NULL_POINTER;
    void** stm = NULL_POINTER;
    void** stmc = NULL_POINTER;
    void** stms = NULL_POINTER;
    void** std = NULL_POINTER;
    void** stdc = NULL_POINTER;
    void** stds = NULL_POINTER;
    // The host address name, abstraction, model, details.
    void** an = NULL_POINTER;
    void** anc = NULL_POINTER;
    void** ans = NULL_POINTER;
    void** aa = NULL_POINTER;
    void** aac = NULL_POINTER;
    void** aas = NULL_POINTER;
    void** am = NULL_POINTER;
    void** amc = NULL_POINTER;
    void** ams = NULL_POINTER;
    void** ad = NULL_POINTER;
    void** adc = NULL_POINTER;
    void** ads = NULL_POINTER;

    // Get service.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAME, (void*) SERVICE_NAME_COUNT,
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p2, p3);

    // Get socket namespace.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_NAMESPACE_NAME, (void*) SERVICE_NAMESPACE_NAME_COUNT,
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p2, p3);

    // Get communication style.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_STYLE_NAME, (void*) SERVICE_STYLE_NAME_COUNT,
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p2, p3);

    // Get host address.
    get_universal_compound_element_by_name(p0, p1,
        (void*) SERVICE_ADDRESS_NAME, (void*) SERVICE_ADDRESS_NAME_COUNT,
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p2, p3);

    // The comparison result.
    int r = 0;
    // The internal memory index.
    int i = *INVALID_VALUE;
    // The server socket internal.
    int** s = (int**) NULL_POINTER;

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

            if (*s == *NULL_POINTER) {

                // Startup server socket if it does not already exist.
                startup_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) WWW_PORT, (void*) WWW_BASE_INTERNAL, p2, p3, p4);

            } else {

                log_message_debug("Warning: Could not start up service. The www service is already running.");
            }
        }
    }

    if (r == 0) {

        compare_arrays((void*) *sm, (void*) *smc, (void*) CYBOI_SERVICE_MODEL, (void*) CYBOI_SERVICE_MODEL_COUNT, (void*) &r, (void*) CHARACTER_ARRAY);

        if (r != 0) {

            // Get server socket internal.
            i = *CYBOI_BASE_INTERNAL + *SOCKET_INTERNAL;
            get(p5, (void*) &i, (void*) &s, (void*) POINTER_VECTOR_ABSTRACTION, (void*) POINTER_VECTOR_ABSTRACTION_COUNT);

            if (*s == *NULL_POINTER) {

                // Startup server socket if it does not already exist.
                startup_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) CYBOI_PORT, (void*) CYBOI_BASE_INTERNAL, p2, p3, p4);

            } else {

                log_message_debug("Warning: Could not start up service. The cyboi service is already running.");
            }
        }
    }
}

/* STARTUP_SOURCE */
#endif
