/*
 * Copyright (C) 1999-2008. Christian Heller.
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
 * @version $RCSfile: compound_allocator.c,v $ $Revision: 1.16 $ $Date: 2008-09-03 22:04:02 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ALLOCATOR_SOURCE
#define COMPOUND_ALLOCATOR_SOURCE

#include "../../globals/constants/cybol/cybol_abstraction_constants.c"
#include "../../globals/constants/integer/integer_constants.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/abstraction/memory/array_memory_abstraction.c"
#include "../../globals/constants/memory_structure/memory_structure_constants.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound size
 */
void allocate_compound(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** c = (void**) p0;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Allocate compound.");

        // Allocate compound.
        allocate_array(p0, (void*) COMPOUND_COUNT, (void*) POINTER_ARRAY);

        // The names, abstractions, models, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        // Allocate names, abstractions, models, details.
        allocate_array((void*) &n, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &nc, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &ns, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &a, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &ac, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &as, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &m, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &mc, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &ms, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &d, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &dc, p1, (void*) POINTER_ARRAY);
        allocate_array((void*) &ds, p1, (void*) POINTER_ARRAY);

        // Set names, abstractions, models, details.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        set_array_elements(*c, (void*) NAMES_INDEX, (void*) &n, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) ABSTRACTIONS_INDEX, (void*) &a, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) &as, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) MODELS_INDEX, (void*) &m, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) DETAILS_INDEX, (void*) &d, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        set_array_elements(*c, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate compound. The compound is null.");
    }
}

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
        void** n = NULL_POINTER;
        void** nc = NULL_POINTER;
        void** ns = NULL_POINTER;
        void** a = NULL_POINTER;
        void** ac = NULL_POINTER;
        void** as = NULL_POINTER;
        void** m = NULL_POINTER;
        void** mc = NULL_POINTER;
        void** ms = NULL_POINTER;
        void** d = NULL_POINTER;
        void** dc = NULL_POINTER;
        void** ds = NULL_POINTER;

        // Get names, abstractions, models, details.
        // The p0 parameter (c) needs to be dereferenced since it is handed
        // over as reference, but this procedure expects a normal array.
        get_array_elements(*c, (void*) NAMES_INDEX, (void*) &n, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) NAMES_COUNTS_INDEX, (void*) &nc, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) NAMES_SIZES_INDEX, (void*) &ns, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) ABSTRACTIONS_INDEX, (void*) &a, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) &ac, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) &as, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) MODELS_INDEX, (void*) &m, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) MODELS_COUNTS_INDEX, (void*) &mc, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) MODELS_SIZES_INDEX, (void*) &ms, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) DETAILS_INDEX, (void*) &d, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) DETAILS_COUNTS_INDEX, (void*) &dc, (void*) POINTER_ARRAY);
        get_array_elements(*c, (void*) DETAILS_SIZES_INDEX, (void*) &ds, (void*) POINTER_ARRAY);

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
        deallocate_array((void*) n, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) nc, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) ns, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) a, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) ac, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) as, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) m, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) mc, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) ms, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) d, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) dc, p1, (void*) POINTER_ARRAY);
        deallocate_array((void*) ds, p1, (void*) POINTER_ARRAY);

        // Deallocate compound.
        deallocate_array(p0, (void*) COMPOUND_COUNT, (void*) POINTER_ARRAY);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate compound. The compound is null.");
    }
}

/* COMPOUND_ALLOCATOR_SOURCE */
#endif
