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

#ifndef MODEL_DEALLOCATOR_SOURCE
#define MODEL_DEALLOCATOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void deallocate(void* p0, void* p1, void* p2, void* p3);

/**
 * Deallocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model count (Hand over as reference!)
 * @param p2 the model size (Hand over as reference!)
 * @param p3 the size
 * @param p4 the abstraction
 * @param p5 the abstraction count
 */
void deallocate_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate model.");

    deallocate(p0, p3, p4, p5);
    deallocate(p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    deallocate(p2, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
}

/**
 * Deallocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the size
 * @param p2 the abstraction
 */
void deallocate_model_NEW(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** mo = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate model.");

        // The name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;

/*??
        // Get name, abstraction, model, details.
        get_array_offset(*mo, (void*) &n, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NAMES_MODEL_MEMORY_NAME, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        get_array_offset(*mo, (void*) &a, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) ABSTRACTIONS_MODEL_MEMORY_NAME, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        get_array_offset(*mo, (void*) &m, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) MODELS_MODEL_MEMORY_NAME, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        get_array_offset(*mo, (void*) &d, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) DETAILS_MODEL_MEMORY_NAME, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        // Deallocate name, abstraction, model, details.
        deallocate_item((void*) &n, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_item((void*) &a, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);
        deallocate_item((void*) &m, p1, p2);
        deallocate_item((void*) &d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) MODEL_PRIMITIVE_MEMORY_ABSTRACTION);

        // Deallocate model.
        deallocate_array(p0, (void*) MODEL_MEMORY_MODEL_COUNT, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate model. The model is null.");
    }
}

/* MODEL_DEALLOCATOR_SOURCE */
#endif
