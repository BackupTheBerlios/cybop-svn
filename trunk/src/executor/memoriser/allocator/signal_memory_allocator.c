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

#ifndef SIGNAL_MEMORY_ALLOCATOR_SOURCE
#define SIGNAL_MEMORY_ALLOCATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/signal_memory_memory_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the signal memory.
 *
 * @param p0 the signal memory (Hand over as reference!)
 * @param p1 the signal memory size
 */
void allocate_signal_memory(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** s = (void**) p0;

        log_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL, (void*) CREATE_SIGNAL_MEMORY_MESSAGE_LOG_MODEL_COUNT);

        // Allocate signal memory.
        allocate_array(p0, (void*) SIGNAL_MEMORY_MEMORY_MODEL_COUNT, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

        // The abstractions, models, details, priorities, identifications.
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* p = *NULL_POINTER_MEMORY_MODEL;
        void* id = *NULL_POINTER_MEMORY_MODEL;

        // Allocate abstractions, models, details, priorities, identifications.
        allocate_array((void*) &a, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &ac, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &m, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &mc, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &d, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &dc, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &p, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        allocate_array((void*) &id, p1, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

        // Set abstractions, models, details, priorities, identifications.
        //
        // CAUTION! The p0 parameter needs to be dereferenced since it is
        // handed over as reference, but this procedure expects a normal array.
        set_array_elements(*s, (void*) ABSTRACTIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &a, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) ABSTRACTIONS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &ac, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) MODELS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &m, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) MODELS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &mc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) DETAILS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &d, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) DETAILS_COUNTS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &dc, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) PRIORITIES_SIGNAL_MEMORY_MEMORY_NAME, (void*) &p, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);
        set_array_elements(*s, (void*) IDENTIFICATIONS_SIGNAL_MEMORY_MEMORY_NAME, (void*) &id, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate signal memory. The signal memory parameter is null.");
    }
}

/* SIGNAL_MEMORY_ALLOCATOR_SOURCE */
#endif
