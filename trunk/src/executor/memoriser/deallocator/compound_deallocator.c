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
 * @version $RCSfile: compound_allocator.c,v $ $Revision: 1.18 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_DEALLOCATOR_SOURCE
#define COMPOUND_DEALLOCATOR_SOURCE

#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/memory/compound_memory_name.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Deallocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound size
 */
void deallocate_compound(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** c = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Deallocate compound.");

        // The names, abstractions, models, details.
        void** n = NULL_POINTER_MEMORY_MODEL;
        void** nc = NULL_POINTER_MEMORY_MODEL;
        void** ns = NULL_POINTER_MEMORY_MODEL;
        void** a = NULL_POINTER_MEMORY_MODEL;
        void** ac = NULL_POINTER_MEMORY_MODEL;
        void** as = NULL_POINTER_MEMORY_MODEL;
        void** m = NULL_POINTER_MEMORY_MODEL;
        void** mc = NULL_POINTER_MEMORY_MODEL;
        void** ms = NULL_POINTER_MEMORY_MODEL;
        void** d = NULL_POINTER_MEMORY_MODEL;
        void** dc = NULL_POINTER_MEMORY_MODEL;
        void** ds = NULL_POINTER_MEMORY_MODEL;

        // Get names, abstractions, models, details.
        // The p0 parameter (c) needs to be dereferenced since it is handed
        // over as reference, but this procedure expects a normal array.
        get_array_elements(*c, (void*) NAMES_COMPOUND_MEMORY_NAME, (void*) &n, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) NAMES_COUNTS_COMPOUND_MEMORY_NAME, (void*) &nc, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) NAMES_SIZES_COMPOUND_MEMORY_NAME, (void*) &ns, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) ABSTRACTIONS_COMPOUND_MEMORY_NAME, (void*) &a, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) ABSTRACTIONS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &ac, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) ABSTRACTIONS_SIZES_COMPOUND_MEMORY_NAME, (void*) &as, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) MODELS_COMPOUND_MEMORY_NAME, (void*) &m, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) MODELS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &mc, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) MODELS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ms, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) DETAILS_COMPOUND_MEMORY_NAME, (void*) &d, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) DETAILS_COUNTS_COMPOUND_MEMORY_NAME, (void*) &dc, (void*) POINTER_MEMORY_ABSTRACTION);
        get_array_elements(*c, (void*) DETAILS_SIZES_COMPOUND_MEMORY_NAME, (void*) &ds, (void*) POINTER_MEMORY_ABSTRACTION);

        // CAUTION! Do NOT try to REMOVE the names, abstractions, models, details!
        // Each of them has a fixed position within the compound and
        // CANNOT be removed.
        // Trying to do so, would result in a runtime error:
        // *** glibc detected *** double free or corruption (fasttop)
        // because the compound is already freed below.

        // Deallocate names, abstractions, models, details.
        // CAUTION! Do NOT hand over as reference!
        // The variables are of type void**.
        // The expression (&*variable) is the same like (variable).
        deallocate_array((void*) n, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) nc, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) ns, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) a, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) ac, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) as, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) m, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) mc, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) ms, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) d, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) dc, p1, (void*) POINTER_MEMORY_ABSTRACTION);
        deallocate_array((void*) ds, p1, (void*) POINTER_MEMORY_ABSTRACTION);

        // Deallocate compound.
        deallocate_array(p0, (void*) COMPOUND_MEMORY_MODEL_COUNT, (void*) POINTER_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate compound. The compound is null.");
    }
}

/* COMPOUND_DEALLOCATOR_SOURCE */
#endif
