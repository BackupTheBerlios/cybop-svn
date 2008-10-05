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
 * @version $RCSfile: model_allocator.c,v $ $Revision: 1.2 $ $Date: 2008-10-05 23:15:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODEL_ALLOCATOR_SOURCE
#define MODEL_ALLOCATOR_SOURCE

#include "../../constant/model/log/message_log_model.c"
#include "../../logger/logger.c"

/**
 * Allocates the model.
 *
 * @param p0 the model (Hand over as reference!)
 * @param p1 the model size
 * @param p2 the abstraction
 * @param p3 the abstraction count
 */
void allocate(void* p0, void* p1, void* p2, void* p3);

/**
 * Sets the integer vector element.
 *
 * @param p0 the integer vector
 * @param p1 the index
 * @param p2 the element (Hand over as reference!)
 */
void set_integer_vector_element(void* p0, void* p1, void* p2);

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

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* ss = (int*) p3;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int** ds = (int**) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int** dc = (int**) p1;

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Allocate model.");

                allocate(p0, p3, p4, p5);
                allocate(p1, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
                allocate(p2, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

                // The OLD solution was:
                // **dc = *ss;
                // **ds = *ss;
                //
                // This is just mentioned here, so that in case of troubles
                // the new solution (call of function "set_integer_vector_element")
                // can easier be checked.
                set_integer_vector_element(*dc, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &p3);
                set_integer_vector_element(*ds, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) &p3);

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The destination model size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not allocate model. The source size is null.");
    }
}

/* MODEL_ALLOCATOR_SOURCE */
#endif
