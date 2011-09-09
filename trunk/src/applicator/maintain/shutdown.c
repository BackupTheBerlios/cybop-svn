/*
 * Copyright (C) 1999-2011. Christian Heller.
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

#ifndef SHUTDOWN_SOURCE
#define SHUTDOWN_SOURCE

#include "../../applicator/maintainer/shutting/gnu_linux_console_shutting_maintainer.c"
#include "../../applicator/maintainer/shutting/socket_shutting_maintainer.c"
#include "../../applicator/maintainer/shutting/x_window_system_shutting_maintainer.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/lifecycle_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Shuts down a service.
 *
 * Expected parameters:
 * - service (required): the service to be shut down (gnu_linux_console, www, x_window_system, ...)
 *
 * @param p0 the parametres array (signal/ operation part details with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void apply_shutdown(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply shutdown.");

    // The service part.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    // The service part model.
    void* sm = *NULL_POINTER_MEMORY_MODEL;
    // The service part model data.
    void* smd = *NULL_POINTER_MEMORY_MODEL;

    // Get service part.
    get_name_array((void*) &s, p0, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get service part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get service part model data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_MEMORY_MODEL;

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            shutdown_gnu_linux_console(p3, (void*) GNU_LINUX_CONSOLE_THREAD, (void*) GNU_LINUX_CONSOLE_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            shutdown_x_window_system(p3, (void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) WWW_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            shutdown_socket(p3, (void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_MEMORY_MODEL) {

            shutdown_socket(p3, (void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not apply shutdown. The service is unknown.");
    }
}

/* SHUTDOWN_SOURCE */
#endif
