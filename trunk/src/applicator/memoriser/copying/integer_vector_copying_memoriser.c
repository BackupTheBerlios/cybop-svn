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
 * @version $RCSfile: integer_vector_copying_memoriser.c,v $ $Revision: 1.5 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_VECTOR_COPYING_MEMORISER_SOURCE
#define INTEGER_VECTOR_COPYING_MEMORISER_SOURCE

#include "../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../executor/comparator/array_equality_comparator.c"
#include "../../../logger/logger.c"

/**
 * Copies an integer vector.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source
 * @param p4 the source count
 */
void memorise_copying_integer_vector(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_MEMORY_MODEL) {

        int* sc = (int*) p4;

        if (p2 != *NULL_POINTER_MEMORY_MODEL) {

            int* ds = (int*) p2;

            if (p1 != *NULL_POINTER_MEMORY_MODEL) {

                int* dc = (int*) p1;

                if (p0 != *NULL_POINTER_MEMORY_MODEL) {

                    void** d = (void**) p0;

                    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Copy integer vector.");

                    // CAUTION! The destination array needs to be resized not only
                    // if the source array is greater, but also if it is smaller!
                    // If this is not done, false results may occur.
                    // Example: A colour gets copied from source to destination.
                    // The source colour is "red" with a count of 3.
                    // The destination colour is "green" with a count of 5.
                    // If the source colour gets copied to the destination,
                    // the resulting destination array is "reden" with a count of 5.
                    // This colour value does not exist and will cause errors!
                    // Therefore, the destination array count and size ALWAYS
                    // have to be adapted to the source array count and size.
                    // If this had been done in the example, the resulting
                    // destination array would have been "red" with a count of 3,
                    // which is correct.

                    // CAUTION! Do NOT use < or > here, for the reasons explained above!
                    if (*sc != *dc) {

                        *dc = *sc;
                        *ds = *dc;

                        reallocate_array(p0, p1, p2, (void*) INTEGER_MEMORY_ABSTRACTION);
                    }

                    set_array_elements(*d, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, p3, p4, (void*) INTEGER_MEMORY_ABSTRACTION);

                } else {

                    log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy integer vector. The destination is null.");
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy integer vector. The destination count is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy integer vector. The destination size is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not copy integer vector. The source count is null.");
    }
}

/* INTEGER_VECTOR_COPYING_MEMORISER_SOURCE */
#endif
