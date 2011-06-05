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

#ifndef MODEL_ALLOCATOR_SOURCE_OLD
#define MODEL_ALLOCATOR_SOURCE_OLD

#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/name/memory/model_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../executor/converter/encoder/abstraction_encoder.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/modifier/replacer/array_replacer.c"
#include "../../../executor/modifier/replacer.c"
#include "../../../executor/referencer/setter/offset_array_setter.c"
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

/* MODEL_ALLOCATOR_SOURCE_OLD */
#endif
