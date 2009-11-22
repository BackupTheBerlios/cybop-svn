/*
 * Copyright (C) 1999-2009. Christian Heller.
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

#ifndef ARRAY_SETTER_SOURCE
#define ARRAY_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Sets the array elements.
 *
 * @param p0 the array
 * @param p1 the index
 * @param p2 the elements
 * @param p3 the elements count
 * @param p4 the array type
 */
void set_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p3;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set array elements.");

            // The offset.
            int o = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The destination base.
            // CAUTION! It HAS TO BE initialised with p0,
            // since an offset is added to it below.
            void* db = p0;
            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Calculate offset depending on given array type.
            calculate_area((void*) &o, p1, p4);
            add_integer((void*) &db, (void*) &o, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

                assign_area_with_offset(db, p2, (void*) &j, p4);

                j++;
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set array elements. The array is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not set array elements. The elements count is null.");
    }
}

/* ARRAY_SETTER_SOURCE */
#endif
