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
 * @version $RCSfile: model_allocator.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_ALLOCATOR_SOURCE
#define MODEL_ALLOCATOR_SOURCE

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/modifier/replacer/array_replacer.c"
#include "../../../executor/modifier/replacer.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void allocate(void* p0, void* p1, void* p2, void* p3);

/**
 * Allocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count (Hand over as reference!)
 * @param p2 the model size (Hand over as reference!)
 * @param p3 the size
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void allocate_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** s = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** c = (void**) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate model.");

            allocate(p0, p3, p4, p5);
            allocate(p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
            allocate(p2, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

            // The count is set to zero, since the model does not contain any elements yet.
            replace_array(*c, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
            // The size is set to the value that was handed over as argument.
            replace_array(*s, p3, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model size is null.");
    }
}

/**
 * Allocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void allocate_model_NEW(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** mo = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate model.");

        // Allocate part.
        allocate_array(p0, (void*) MODEL_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // The name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;

        // Allocate name, abstraction, model, details.
        allocate_item((void*) &n, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &a, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        allocate_item((void*) &m, p1, p2);
        allocate_item((void*) &d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

        // Initialise name, abstraction, model, details.
        // The name does NOT have to be initialised, since it may remain empty.
        // The abstraction is set to the value that was handed over as argument.
        // The model and details have been initialised above.
        set_item((void*) &a, p2, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, abstraction-count, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        // Set name, abstraction, model, details.
        set_array(*mo, (void*) &n, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NAME_MODEL_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array(*mo, (void*) &a, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) ABSTRACTION_MODEL_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array(*mo, (void*) &m, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) MODEL_MODEL_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
        set_array(*mo, (void*) &d, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The model is null.");
    }
}

/* MODEL_ALLOCATOR_SOURCE */
#endif
