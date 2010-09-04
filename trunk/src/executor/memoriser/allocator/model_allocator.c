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
 * @version $RCSfile: model_allocator.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_ALLOCATOR_SOURCE
#define MODEL_ALLOCATOR_SOURCE

#include "../../../constant/model/log/message_log_model.c"
#include "../../../executor/accessor/setter/array_setter.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void allocate(void* p0, void* p1, void* p2, void* p3);

/**
 * Allocates the model.
 *
 * @param p0 the destination model (Hand over as reference!)
 * @param p1 the destination model count (Hand over as reference!)
 * @param p2 the destination model size (Hand over as reference!)
 * @param p3 the source size
 * @param p4 the source abstraction
 * @param p5 the source abstraction count
 */
void allocate_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int** ds = (int**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int** dc = (int**) p1;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate model.");

            allocate(p0, p3, p4, p5);
            allocate(p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);
            allocate(p2, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) MEMORY_ABSTRACTION_COUNT);

            //?? TEMPORARY COMMENT!
            //
            // The OLD solution was:
            // **dc = *((int*) p3);
            // **ds = *((int*) p3);
            //
            // This is just mentioned here, so that in case of troubles
            // the new solution (call of function "set_array_elements")
            // can easier be checked.
            set_array_elements(*dc, p3, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);
            set_array_elements(*ds, p3, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_MEMORY_ABSTRACTION);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model count is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model size is null.");
    }
}

/* MODEL_ALLOCATOR_SOURCE */
#endif
