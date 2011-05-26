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
 * @param p1 the model size
 * @param p2 the element abstraction
 * @param p3 the element abstraction count
 */
void deallocate_model_NEW(void* p0, void* p1, void* p2, void* p3) {

/*??
    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** m = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate model.");

        // The data, count, size.
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* c = *NULL_POINTER_MEMORY_MODEL;
        void* s = *NULL_POINTER_MEMORY_MODEL;

        // Retrieve data, count, size.
    fwprintf(stdout, L"TEST deallocate model 0 d: %i\n", d);
        retrieve((void*) &d, *m, (void*) DATA_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST deallocate model 1 d: %i\n", d);
        retrieve((void*) &c, *m, (void*) COUNT_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST deallocate model 2 d: %i\n", d);
        retrieve((void*) &s, *m, (void*) SIZE_MODEL_MEMORY_NAME, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

        // Deallocate data, count, size.
    fwprintf(stdout, L"TEST deallocate model 3 d: %i\n", d);
        deallocate((void*) &d, p1, p2, p3);
    fwprintf(stdout, L"TEST deallocate model 4 d: %i\n", d);
        deallocate((void*) &c, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST deallocate model 5 d: %i\n", d);
        deallocate((void*) &s, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);
    fwprintf(stdout, L"TEST deallocate model 6 d: %i\n", d);

        // Deallocate model.
        deallocate(p0, (void*) MODEL_MEMORY_MODEL_COUNT, (void*) POINTER_MEMORY_ABSTRACTION, (void*) POINTER_MEMORY_ABSTRACTION_COUNT);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate model. The model is null.");
    }
*/
}

/* MODEL_DEALLOCATOR_SOURCE */
#endif
