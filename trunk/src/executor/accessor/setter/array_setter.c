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
 * @version $RCSfile: array.c,v $ $Revision: 1.23 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SETTER_SOURCE
#define ARRAY_SETTER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/accessor/assigner.c"
#include "../../../executor/arithmetiser/integer_adder.c"
#include "../../../executor/arithmetiser/integer_multiplier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Sets the array elements.
 *
 * @param p0 the destination array
 * @param p1 the source elements
 * @param p2 the source elements count
 * @param p3 the destination array index
 * @param p4 the primitive abstraction
 */
void replace_array(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p2;

        if (p0 != *NULL_POINTER_MEMORY_MODEL) {

            log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Set array elements.");

            // The destination offset.
            int dos = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Determine abstraction (type) size.
            determine_size((void*) &dos, p4);

            // Calculate memory area (destination offset).
            multiply_with_integer((void*) &dos, p3, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);

            // The destination.
            // CAUTION! It HAS TO BE initialised with p0,
            // since an offset is added to it below.
            void* d = p0;

            // Add offset to destination.
            add_integer((void*) &d, (void*) &dos, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);

            // The loop variable.
            int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

            while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                if (j >= *sc) {

                    break;
                }

                assign_with_offset(d, p1, (void*) &j, p4);

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
