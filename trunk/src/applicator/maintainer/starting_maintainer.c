/*
 * Copyright (C) 1999-2010. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: starting_maintainer.c,v $ $Revision: 1.9 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTING_MAINTAINER_SOURCE
#define STARTING_MAINTAINER_SOURCE

#include "../../applicator/maintainer/starting/gnu_linux_console_starting_maintainer.c"
#include "../../applicator/maintainer/starting/socket_starting_maintainer.c"
#include "../../applicator/maintainer/starting/x_window_system_starting_maintainer.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/lifecycle_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"

/**
 * Starts up a service.
 *
 * Expected parameters:
 * - service (required): the service to be started up (gnu_linux_console, tcp_socket, unix_socket, x_window_system, ...)
 * - namespace (optional, only if service is www, cyboi or similar): the namespace of the socket
 * - style (optional, only if service is www, cyboi or similar): the namespace of the socket
 * - style (optional, only if service is www, cyboi or similar): the address of hosts communicating with this system via socket
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the internal memory
 */
void maintain_starting(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Startup service.");

    // The service name, abstraction, model, details.
    void** sn = NULL_POINTER_MEMORY_MODEL;
    void** snc = NULL_POINTER_MEMORY_MODEL;
    void** sns = NULL_POINTER_MEMORY_MODEL;
    void** sa = NULL_POINTER_MEMORY_MODEL;
    void** sac = NULL_POINTER_MEMORY_MODEL;
    void** sas = NULL_POINTER_MEMORY_MODEL;
    void** sm = NULL_POINTER_MEMORY_MODEL;
    void** smc = NULL_POINTER_MEMORY_MODEL;
    void** sms = NULL_POINTER_MEMORY_MODEL;
    void** sd = NULL_POINTER_MEMORY_MODEL;
    void** sdc = NULL_POINTER_MEMORY_MODEL;
    void** sds = NULL_POINTER_MEMORY_MODEL;
    // The socket namespace name, abstraction, model, details.
    void** nn = NULL_POINTER_MEMORY_MODEL;
    void** nnc = NULL_POINTER_MEMORY_MODEL;
    void** nns = NULL_POINTER_MEMORY_MODEL;
    void** na = NULL_POINTER_MEMORY_MODEL;
    void** nac = NULL_POINTER_MEMORY_MODEL;
    void** nas = NULL_POINTER_MEMORY_MODEL;
    void** nm = NULL_POINTER_MEMORY_MODEL;
    void** nmc = NULL_POINTER_MEMORY_MODEL;
    void** nms = NULL_POINTER_MEMORY_MODEL;
    void** nd = NULL_POINTER_MEMORY_MODEL;
    void** ndc = NULL_POINTER_MEMORY_MODEL;
    void** nds = NULL_POINTER_MEMORY_MODEL;
    // The communication style name, abstraction, model, details.
    void** stn = NULL_POINTER_MEMORY_MODEL;
    void** stnc = NULL_POINTER_MEMORY_MODEL;
    void** stns = NULL_POINTER_MEMORY_MODEL;
    void** sta = NULL_POINTER_MEMORY_MODEL;
    void** stac = NULL_POINTER_MEMORY_MODEL;
    void** stas = NULL_POINTER_MEMORY_MODEL;
    void** stm = NULL_POINTER_MEMORY_MODEL;
    void** stmc = NULL_POINTER_MEMORY_MODEL;
    void** stms = NULL_POINTER_MEMORY_MODEL;
    void** std = NULL_POINTER_MEMORY_MODEL;
    void** stdc = NULL_POINTER_MEMORY_MODEL;
    void** stds = NULL_POINTER_MEMORY_MODEL;
    // The host address name, abstraction, model, details.
    void** an = NULL_POINTER_MEMORY_MODEL;
    void** anc = NULL_POINTER_MEMORY_MODEL;
    void** ans = NULL_POINTER_MEMORY_MODEL;
    void** aa = NULL_POINTER_MEMORY_MODEL;
    void** aac = NULL_POINTER_MEMORY_MODEL;
    void** aas = NULL_POINTER_MEMORY_MODEL;
    void** am = NULL_POINTER_MEMORY_MODEL;
    void** amc = NULL_POINTER_MEMORY_MODEL;
    void** ams = NULL_POINTER_MEMORY_MODEL;
    void** ad = NULL_POINTER_MEMORY_MODEL;
    void** adc = NULL_POINTER_MEMORY_MODEL;
    void** ads = NULL_POINTER_MEMORY_MODEL;

    // Get service.
    get_universal_compound_element_by_name(
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p0, p1,
        (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get socket namespace.
    get_universal_compound_element_by_name(
        (void*) &nn, (void*) &nnc, (void*) &nns,
        (void*) &na, (void*) &nac, (void*) &nas,
        (void*) &nm, (void*) &nmc, (void*) &nms,
        (void*) &nd, (void*) &ndc, (void*) &nds,
        p0, p1,
        (void*) NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get communication style.
    get_universal_compound_element_by_name(
        (void*) &stn, (void*) &stnc, (void*) &stns,
        (void*) &sta, (void*) &stac, (void*) &stas,
        (void*) &stm, (void*) &stmc, (void*) &stms,
        (void*) &std, (void*) &stdc, (void*) &stds,
        p0, p1,
        (void*) STYLE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) STYLE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // Get host address.
    get_universal_compound_element_by_name(
        (void*) &an, (void*) &anc, (void*) &ans,
        (void*) &aa, (void*) &aac, (void*) &aas,
        (void*) &am, (void*) &amc, (void*) &ams,
        (void*) &ad, (void*) &adc, (void*) &ads,
        p0, p1,
        (void*) ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;
    // The server socket internal.
    int** s = (int**) NULL_POINTER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_starting_gnu_linux_console(p5, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_starting_x_window_system(p5, p2, p3, p4);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) WWW_CYBOL_CHANNEL, (void*) WWW_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Get server socket internal.
            i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERNAL_MEMORY_MEMORY_NAME;
            get((void*) &s, p5, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

            if (*s == *NULL_POINTER_MEMORY_MODEL) {

                // Startup server socket if it does not already exist.
                maintain_starting_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) TCP_WWW_SERVICE_PORT_MODEL, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME, p2, p3, p4);

            } else {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not start up service. The www service is already running.");
            }
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) CYBOI_CYBOL_CHANNEL, (void*) CYBOI_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            // Get server socket internal.
            i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERNAL_MEMORY_MEMORY_NAME;
            get((void*) &s, p5, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

            if (*s == *NULL_POINTER_MEMORY_MODEL) {

                // Startup server socket if it does not already exist.
                maintain_starting_socket(p5, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) CYBOI_SERVICE_PORT_MODEL, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME, p2, p3, p4);

            } else {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not start up service. The cyboi service is already running.");
            }
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not start up service. The service model is unknown.");
    }
}

/* STARTING_MAINTAINER_SOURCE */
#endif
