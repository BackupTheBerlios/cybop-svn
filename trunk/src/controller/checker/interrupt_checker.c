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
 * @version $RCSfile: checker.c,v $ $Revision: 1.72 $ $Date: 2009-02-08 13:04:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_CHECKER_SOURCE
#define INTERRUPT_CHECKER_SOURCE

#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/level_log_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/internal_memory_memory_name.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Checks input channels for interrupt requests.
 *
 * Example input channels:
 * - signal memory
 * - gnu/linux console
 * - x window system
 * - socket
 *
 * The "handler" is an operation encapsulated as part, which is
 * to be forwarded as signal to be processed normally in the system.
 *
 * @param p0 the interrupt request (Hand over as reference!)
 * @param p1 the mutex (Hand over as reference!)
 * @param p2 the handler (Hand over as reference!)
 * @param p3 the internal memory array
 */
void check_interrupt(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** irq = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for interrupt requests.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_MEMORY_MODEL;

        // CAUTION! The boolean logic expression is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected signal memory interrupt.");

            // Get signal memory interrupt request.
            copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
            // Get signal memory mutex.
            copy_array_forward(p1, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
            // A handler is NOT set in the case of a signal memory interrupt.

//??    fwprintf(stdout, L"TEST detected signal memory irq: %i\n", *((int*) *irq));
        }

        // CAUTION! The boolean logic expression is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected gnu/linux console interrupt.");

            // Get gnu/linux console interrupt request.
            copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
            // Get gnu/linux console mutex.
            copy_array_forward(p1, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
            // Get gnu/linux console handler.
            copy_array_forward(p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) GNU_LINUX_CONSOLE_HANDLER_INTERNAL_MEMORY_MEMORY_NAME);

//??    fwprintf(stdout, L"TEST detected gnu/linux console irq: %i\n", *((int*) *irq));
        }

        // CAUTION! The boolean logic expression is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected x window system interrupt.");

            // Get x window system interrupt request.
            copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
            // Get x window system mutex.
            copy_array_forward(p1, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
            // Get x window system handler.
            copy_array_forward(p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) X_WINDOW_SYSTEM_HANDLER_INTERNAL_MEMORY_MEMORY_NAME);

//??    fwprintf(stdout, L"TEST detected x window system irq: %i\n", *((int*) *irq));
        }

        // CAUTION! The boolean logic expression is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected www service interrupt.");

            // Get www service interrupt request.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);
            // Get www service mutex.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);
            // Get www service handler.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_HANDLER_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);

//??    fwprintf(stdout, L"TEST detected www service irq: %i\n", *((int*) *irq));
        }

        // CAUTION! The boolean logic expression is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected cyboi service interrupt.");

            // Get cyboi service interrupt request.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p0, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);
            // Get cyboi service mutex.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);
            // Get cyboi service handler.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME);
            calculate_integer_add((void*) &i, (void*) SOCKET_HANDLER_INTERNAL_MEMORY_MEMORY_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &i);

fwprintf(stdout, L"TEST detected cyboi service irq: %i\n", *((int*) *irq));
        }

        // CAUTION! The boolean logic AND expression && is necessary, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is zero anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
        // this and further interrupts are NOT checked.
        if ((*irq == *NULL_POINTER_MEMORY_MODEL) || ((*irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) *irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. No interrupt request is set.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request argument is null.");
    }
}

/* INTERRUPT_CHECKER_SOURCE */
#endif
