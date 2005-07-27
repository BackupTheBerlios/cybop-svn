/*
 * $RCSfile: compound_allocator.c,v $
 *
 * Copyright (c) 1999-2005. Christian Heller and the CYBOP developers.
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
 * This file contains the functionality to:
 * - create a compound model in memory
 *
 * @version $Revision: 1.5 $ $Date: 2005-07-27 13:30:20 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPOUND_ALLOCATOR_SOURCE
#define COMPOUND_ALLOCATOR_SOURCE

#include "../../globals/constants/integer_constants.c"
#include "../../globals/constants/log_constants.c"
#include "../../globals/constants/structure_constants.c"
#include "../../globals/logger/logger.c"
#include "../../memoriser/array.c"

/**
 * Allocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound size
 */
void allocate_compound(void* p0, void* p1) {

    if (p0 != NULL_POINTER) {

        void** c = (void**) p0;

        log_message_debug("Allocate compound.");

        // Create compound.
        allocate_array(p0, (void*) COMPOUND_COUNT, (void*) POINTER_ARRAY);

        // The names, abstractions, models, details.
        void* n = NULL_POINTER;
        void* nc = NULL_POINTER;
        void* ns = NULL_POINTER;
        void* a = NULL_POINTER;
        void* ac = NULL_POINTER;
        void* as = NULL_POINTER;
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        void* ms = NULL_POINTER;
        void* d = NULL_POINTER;
        void* dc = NULL_POINTER;
        void* ds = NULL_POINTER;

        // Create names, abstractions, models, details.
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
        // CAUTION! Use ascending order, as compared to destruction!
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

        log_message_debug("Could not create compound. The model parameter is null.");
    }
}

/**
 * Deallocates the compound.
 *
 * @param p0 the compound (Hand over as reference!)
 * @param p1 the compound size
 */
void deallocate_compound(void* p0, void* p1) {

    if (p0 != NULL_POINTER) {

        void** c = (void**) p0;

        log_message_debug("Deallocate compound.");

        // The names, abstractions, models, details.
        void* n = NULL_POINTER;
        void* nc = NULL_POINTER;
        void* ns = NULL_POINTER;
        void* a = NULL_POINTER;
        void* ac = NULL_POINTER;
        void* as = NULL_POINTER;
        void* m = NULL_POINTER;
        void* mc = NULL_POINTER;
        void* ms = NULL_POINTER;
        void* d = NULL_POINTER;
        void* dc = NULL_POINTER;
        void* ds = NULL_POINTER;

        // Get names, abstractions, models, details.
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
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

        // Remove names, abstractions, models, details.
        // CAUTION! Use descending order, as compared to creation!
        // The p0 parameter needs to be dereferenced since it is handed over
        // as reference, but this procedure expects a normal array.
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) DETAILS_SIZES_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) DETAILS_COUNTS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) DETAILS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) MODELS_SIZES_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) MODELS_COUNTS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) MODELS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) ABSTRACTIONS_SIZES_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) ABSTRACTIONS_COUNTS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) ABSTRACTIONS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) NAMES_SIZES_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) NAMES_COUNTS_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);
        remove_array_elements(*c, (void*) COMPOUND_COUNT, (void*) NAMES_INDEX, (void*) NUMBER_1_INTEGER, (void*) POINTER_ARRAY);

        // Destroy names, abstractions, models, details.
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

        // Destroy compound.
        deallocate_array(p0, (void*) COMPOUND_COUNT, (void*) POINTER_ARRAY);

    } else {

        log_message_debug("Could not destroy compound. The model parameter is null.");
    }
}

/* COMPOUND_ALLOCATOR_SOURCE */
#endif
