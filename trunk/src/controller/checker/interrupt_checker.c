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
#include "../../executor/accessor/getter.c"
#include "../../logger/logger.c"

/**
 * Checks for interrupt requests.
 *
 * @param p0 the interrupt request (Hand over as double-reference!)
 * @param p1 the mutex (Hand over as double-reference!)
 * @param p2 the handler abstraction (Hand over as double-reference!)
 * @param p3 the handler abstraction count (Hand over as double-reference!)
 * @param p4 the handler model (Hand over as double-reference!)
 * @param p5 the handler model count (Hand over as double-reference!)
 * @param p6 the handler details (Hand over as double-reference!)
 * @param p7 the handler details count (Hand over as double-reference!)
 * @param p8 the internal memory
 */
void check_interrupt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void*** irq = (void***) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Check for interrupt requests.");

        if (*irq == NULL_POINTER_MEMORY_MODEL) {

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
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected signal memory interrupt.");

                // Get signal memory interrupt request.
                get(p0, p8, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get signal memory mutex.
                get(p1, p8, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST detected signal memory irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected gnu/linux console interrupt.");

                // Get gnu/linux console interrupt request.
                get(p0, p8, (void*) GNU_LINUX_CONSOLE_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get gnu/linux console mutex.
                get(p1, p8, (void*) GNU_LINUX_CONSOLE_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get gnu/linux console handler abstraction, model, details.
                get(p2, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p3, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p4, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p5, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p6, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p7, p8, (void*) GNU_LINUX_CONSOLE_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST detected gnu/linux console irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected x window system interrupt.");

                // Get x window system interrupt request.
                get(p0, p8, (void*) X_WINDOW_SYSTEM_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get x window system mutex.
                get(p1, p8, (void*) X_WINDOW_SYSTEM_MUTEX_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get x window system handler abstraction, model, details.
                get(p2, p8, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p3, p8, (void*) X_WINDOW_SYSTEM_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p4, p8, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p5, p8, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p6, p8, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                get(p7, p8, (void*) X_WINDOW_SYSTEM_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST detected x window system irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected www service interrupt.");

                // Get www service interrupt request.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
                get(p0, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get www service mutex.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
                get(p1, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get www service handler abstraction, model, details.
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
                get(p2, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p3, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
                get(p4, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p5, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
                get(p6, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *WWW_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p7, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

//??    fwprintf(stdout, L"TEST detected www service irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic expression is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Detected cyboi service interrupt.");

                // Get cyboi service interrupt request.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_INTERRUPT_REQUEST_INTERNAL_MEMORY_MEMORY_NAME;
                get(p0, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get cyboi service mutex.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_MUTEX_INTERNAL_MEMORY_MEMORY_NAME;
                get(p1, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                // Get cyboi service handler abstraction, model, details.
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_INTERNAL_MEMORY_MEMORY_NAME;
                get(p2, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_ABSTRACTION_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p3, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_MEMORY_NAME;
                get(p4, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p5, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_INTERNAL_MEMORY_MEMORY_NAME;
                get(p6, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
                i = *CYBOI_BASE_INTERNAL_MEMORY_MEMORY_NAME + *SOCKET_HANDLER_DETAILS_COUNT_INTERNAL_MEMORY_MEMORY_NAME;
                get(p7, p8, (void*) &i, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    fwprintf(stdout, L"TEST detected cyboi service irq: %i\n", *((int*) **irq));
            }

            // CAUTION! The boolean logic AND expression && is necessary, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is zero anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not zero (irq is set),
            // this and further interrupts are NOT checked.
            if ((**irq == *NULL_POINTER_MEMORY_MODEL) || ((**irq != *NULL_POINTER_MEMORY_MODEL) && (*((int*) **irq) == *NUMBER_0_INTEGER_MEMORY_MODEL))) {

                log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. No interrupt request is set.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request dereferenced argument is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request argument is null.");
    }
}

/* INTERRUPT_CHECKER_SOURCE */
#endif
