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
 * @version $RCSfile: signal_memory_allocator.c,v $ $Revision: 1.21 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_MEMORY_DEALLOCATOR_SOURCE
#define SIGNAL_MEMORY_DEALLOCATOR_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/memory/signal_memory_memory_name.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the signal memory.
 *
 * @param p0 the signal memory (Hand over as reference!)
 * @param p1 the signal memory size
 */
void deallocate_signal_memory(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** s = (void**) p0;

        log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL, (void*) DESTROY_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_COUNT);

        // The abstractions, models, details, priorities, identifications.
        void** a = NULL_POINTER_MEMORY_MODEL;
        void** ac = NULL_POINTER_MEMORY_MODEL;
        void** m = NULL_POINTER_MEMORY_MODEL;
        void** mc = NULL_POINTER_MEMORY_MODEL;
        void** d = NULL_POINTER_MEMORY_MODEL;
        void** dc = NULL_POINTER_MEMORY_MODEL;
        void** p = NULL_POINTER_MEMORY_MODEL;
        void** id = NULL_POINTER_MEMORY_MODEL;

/*??
        log_message((void*) &INFORMATION_LEVEL_LOG_MODEL, (void*) &"Destroy all signals left in signal memory.");

        int i = *NUMBER_0_INTEGER_MEMORY_MODEL;
        get_array_count(m->signals, (void*) &i);
        i--;
        void* s = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;

        while (i >= *NUMBER_0_INTEGER_MEMORY_MODEL) {

            s = (void*) get_signal(p0, (void*) &i);
            a = (void*) memorise_getting_abstraction(p0, (void*) &i);
            // Priority is not needed to destroy the signal.

            // Abstraction and priority are removed internally,
            // together with the signal.
            remove_signal(p0, (void*) &i);

            // Destroy signal. Do not destroy the signal's abstraction and
            // priority here; they are static within CYBOI.
            decreate(s, NULL, NULL, (void*) a);

            i--;
        }
*/

        // Get abstractions, models, details, priorities, identifications.
        //
        // CAUTION! The p0 parameter (s) needs to be dereferenced since it is
        // handed over as reference, but this procedure expects a normal array.
        get_array_elements((void*) &a, *s, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &ac, *s, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &m, *s, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &mc, *s, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &d, *s, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &dc, *s, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &p, *s, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        get_array_elements((void*) &id, *s, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        //
        // CAUTION! Do NOT try to REMOVE the abstractions, models, details, priorities, identifications!
        // Each of them has a fixed position within the signal memory and CANNOT be removed.
        //
        // Trying to do so, would result in a runtime error:
        // *** glibc detected *** double free or corruption (fasttop)
        //
        // because the signal memory is already freed below.
        //

        // Deallocate abstractions, models, details, priorities, identifications.
        //
        // CAUTION! Do NOT hand over as reference!
        // The variables are of type void**.
        // The expression (&*variable) is the same like (variable).
        deallocate_array((void*) a, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) ac, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) m, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) mc, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) d, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) dc, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) p, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_array((void*) id, p1, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Deallocate signal memory.
        deallocate_array(p0, (void*) SIGNAL_MEMORY_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate signal memory. The signal memory parameter is null.");
    }
}

/* SIGNAL_MEMORY_DEALLOCATOR_SOURCE */
#endif
