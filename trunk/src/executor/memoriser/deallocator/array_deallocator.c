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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_DEALLOCATOR_SOURCE
#define ARRAY_DEALLOCATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 * @param p2 the array abstraction
 */
void deallocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** a = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate array.");

        // CAUTION! Check array for null value.
        // The "free" function would cause an error when handing over a null value.
        if (*a != *NULL_POINTER_MEMORY_MODEL) {

            // This function may cause an error if some wrong pointer
            // is forwarded to it as argument.
            // If this happens and the system crashes right here showing
            // a "Segmentation fault" or the like, then it is not the fault
            // of the "free" function but of the pointer passed on to it.
            // Somewhere else in the code, the pointer was manipulated
            // and probably set wrong, e.g. outside an allocated area.
            free(*a);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not deallocate array. The dereferenced array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate array. The array is null.");
    }
}

/* ARRAY_DEALLOCATOR_SOURCE */
#endif
