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
 * @version $RCSfile: part_allocator.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_ALLOCATOR_SOURCE
#define PART_ALLOCATOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../logger/logger.c"

/**
 * Allocates the part.
 *
 * @param p0 the part (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void allocate_part(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** p = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate part.");

        // Allocate part.
        allocate_array(p0, (void*) PART_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // The name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;

        // Allocate name, abstraction, model, details.
        allocate_item((void*) &n, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &a, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &m, p1, p2);
        allocate_item((void*) &d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

        // Set name, abstraction, model, details.
        copy_array_forward(*p, (void*) &n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NAME_PART_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(*p, (void*) &a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) ABSTRACTION_PART_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(*p, (void*) &m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) MODEL_PART_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        copy_array_forward(*p, (void*) &d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DETAILS_PART_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate part. The part is null.");
    }
}

/* PART_ALLOCATOR_SOURCE */
#endif
