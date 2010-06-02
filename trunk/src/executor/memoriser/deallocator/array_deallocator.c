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
#include "../../../variable/primitive_type_size.c"

/**
 * Deallocates the array.
 *
 * @param p0 the array (Hand over as reference!)
 * @param p1 the array size
 * @param p2 the array type
 */
void deallocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** a = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Deallocate array.");

        free(*a);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not deallocate array. The array is null.");
    }
}

/* ARRAY_DEALLOCATOR_SOURCE */
#endif
