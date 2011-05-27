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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_ALLOCATOR_SOURCE
#define ARRAY_ALLOCATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Allocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** a = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate array.");

        // The memory area.
        int ma = *NUMBER_0_INTEGER_MEMORY_MODEL;

        // Determine abstraction (type) size.
        determine_size((void*) &ma, p2);

        // Calculate memory area.
        multiply_with_integer((void*) &ma, p1, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        // A minimal space in memory is always allocated,
        // even if the requested size is zero.
        // In other words, a handle to the new instance is always returned.
        *a = (void*) malloc((size_t) ma);

        // Initialise array elements with null pointer.
        memset(*a, *NUMBER_0_INTEGER_MEMORY_MODEL, ma);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate array. The array is null.");
    }
}

/* ARRAY_ALLOCATOR_SOURCE */
#endif
