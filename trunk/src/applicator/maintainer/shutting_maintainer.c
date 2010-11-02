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
 * @version $RCSfile: shutting_maintainer.c,v $ $Revision: 1.8 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTTING_MAINTAINER_SOURCE
#define SHUTTING_MAINTAINER_SOURCE

#include "../../applicator/maintainer/shutting/gnu_linux_console_shutting_maintainer.c"
#include "../../applicator/maintainer/shutting/socket_shutting_maintainer.c"
#include "../../applicator/maintainer/shutting/x_window_system_shutting_maintainer.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/lifecycle_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/array_equality_comparator.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Shuts down a service.
 *
 * Expected parameters:
 * - service (required): the service to be shut down (gnu_linux_console, www, x_window_system, ...)
 *
 * @param p0 the parameters
 * @param p1 the parameters count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 * @param p5 the internal memory
 */
void maintain_shutting(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Shutdown service.");

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

    // Get service.
    get_universal_compound_element_by_name(
        (void*) &sn, (void*) &snc, (void*) &sns,
        (void*) &sa, (void*) &sac, (void*) &sas,
        (void*) &sm, (void*) &smc, (void*) &sms,
        (void*) &sd, (void*) &sdc, (void*) &sds,
        p0, p1,
        (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_shutting_gnu_linux_console(p5, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_shutting_x_window_system(p5, (void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) WWW_CYBOL_CHANNEL, (void*) WWW_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_shutting_socket(p5, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME, (void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_equal_arrays((void*) &r, (void*) *sm, (void*) *smc, (void*) CYBOI_CYBOL_CHANNEL, (void*) CYBOI_CYBOL_CHANNEL_COUNT, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            maintain_shutting_socket(p5, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME, (void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not shut down service. The service model is unknown.");
    }
}

/* SHUTTING_MAINTAINER_SOURCE */
#endif
