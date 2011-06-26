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

#ifndef PART_DEALLOCATOR_SOURCE
#define PART_DEALLOCATOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"

/**
 * Deallocates the part.
 *
 * @param p0 the model name (Hand over as reference!)
 * @param p1 the model name count (Hand over as reference!)
 * @param p2 the model name size (Hand over as reference!)
 * @param p3 the model abstraction (Hand over as reference!)
 * @param p4 the model abstraction count (Hand over as reference!)
 * @param p5 the model abstraction size (Hand over as reference!)
 * @param p6 the model model (Hand over as reference!)
 * @param p7 the model model count (Hand over as reference!)
 * @param p8 the model model size (Hand over as reference!)
 * @param p9 the model details (Hand over as reference!)
 * @param p10 the model details count (Hand over as reference!)
 * @param p11 the model details size (Hand over as reference!)
 * @param p12 the model size
 * @param p13 the source abstraction
 * @param p14 the source abstraction count
 */
void deallocate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5,
    void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate part.");

    // Deallocate name.
    deallocate_model(p0, p1, p2, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // A channel is not allocated, since that is only needed temporarily for model loading.
    // Deallocate abstraction.
    deallocate_model(p3, p4, p5, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
    // Deallocate model.
    deallocate_model(p6, p7, p8, p12, p13, p14);
    // Deallocate details.
    deallocate_model(p9, p10, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Deallocates the part.
 *
 * @param p0 the part (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void deallocate_part_NEW(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** p = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate part.");

        // The name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;

        // Get name, abstraction, model, details.
        copy_array_offset((void*) &n, *p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
        copy_array_offset((void*) &a, *p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
        copy_array_offset((void*) &m, *p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
        copy_array_offset((void*) &d, *p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

        // Deallocate name, abstraction, model, details.
        deallocate_item((void*) &n, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_item((void*) &a, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_item((void*) &m, p1, p2);
        deallocate_item((void*) &d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_PRIMITIVE_MEMORY_ABSTRACTION);

        // Deallocate part.
        deallocate_array(p0, (void*) PART_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate part. The part is null.");
    }
}

/* PART_DEALLOCATOR_SOURCE */
#endif
