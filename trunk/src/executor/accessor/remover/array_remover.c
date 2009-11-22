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

#ifndef ARRAY_REMOVER_SOURCE
#define ARRAY_REMOVER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/logger.c"
#include "../../variable/primitive_type_size.c"

/**
 * Removes the array elements.
 *
 * @param p0 the array
 * @param p1 the array size
 * @param p2 the index
 * @param p3 the elements count
 * @param p4 the array type
 */
void remove_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        int* i = (int*) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            int* as = (int*) p1;

            if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Remove array elements.");

                // The destination offset.
                int dos = *NUMBER_0_INTEGER_MEMORY_MODEL;
                // The source offset.
                int sos = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Calculate destination offset depending on given array type.
                calculate_area((void*) &dos, p2, p4);
                // Calculate source offset depending on given array type.
                calculate_area((void*) &sos, p3, p4);

                // The destination.
                // CAUTION! It HAS TO BE initialised with p0,
                // since an offset is added to it below.
                void* d = p0;

                // Add offset to destination.
                add_integer((void*) &d, (void*) &dos, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                // The source.
                // CAUTION! It HAS TO BE initialised with d,
                // AFTER the offset has been added to d above,
                // since an offset is added to it below.
                void* s = d;

                // Add offset to source.
                add_integer((void*) &s, (void*) &sos, (void*) POINTER_ARRAY_MEMORY_ABSTRACTION);

                // The subtrahend.
                // CAUTION! It HAS TO BE initialised with *i,
                // since an offset is added to it below.
                int sub = *i;

                // Add elements count to subtrahend.
                add_integer((void*) &sub, p3, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                // The remaining elements size.
                // CAUTION! It HAS TO BE initialised with *as,
                // since an offset is added to it below.
                int r = *as;

                // Subtract subtrahend from array size.
                subtract_integer((void*) &r, (void*) &sub, (void*) INTEGER_ARRAY_MEMORY_ABSTRACTION);

                // The loop variable.
                int j = *NUMBER_0_INTEGER_MEMORY_MODEL;

                // Starting from the given index, move all remaining elements
                // one place towards the beginning of the elements.
                //
                // Example: "test..array"
                // maxcount = 11
                // index = 4 (remove "..")
                // count = 2
                // rest = 11 - (4 + 2) = 11 - 6 = 5
                //
                // Finally, all remaining elements are moved by
                // "element count" places towards the beginning of the array.
                while (*NUMBER_1_INTEGER_MEMORY_MODEL) {

                    if (j >= r) {

                        break;
                    }

                    assign_area_with_offset(d, s, (void*) &j, p4);

                    j++;
                }

                // There is no need to set the former last elements to 0.
                // The calling procedure may just cut off the remaining
                // elements by decreasing the array size (resizing).

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The array is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The array size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not remove array elements. The index is null.");
    }
}

/* ARRAY_REMOVER_SOURCE */
#endif
